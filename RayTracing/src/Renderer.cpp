#include "Renderer.h"
#include <algorithm>
#include "Walnut/Random.h"
#include <execution>
#include <future>

namespace Utils {

	static uint32_t ConvertToRGBA(const glm::vec4& color)
	{
		uint8_t r = (uint8_t)(color.r * 255.0f);
		uint8_t g = (uint8_t)(color.g * 255.0f);
		uint8_t b = (uint8_t)(color.b * 255.0f);
		uint8_t a = (uint8_t)(color.a * 255.0f);

		uint32_t result = (a << 24) | (b << 16) | (g << 8) | r;
		return result;
	}

	static uint32_t PCG_Hash(uint32_t input)
	{
		uint32_t state = input * 747796405u + 2891336453u;
		uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
		return (word >> 22u) ^ word;
	}

	static float RandomFloat(uint32_t& seed)
	{
		seed = PCG_Hash(seed);
		return (float)seed / (float)UINT32_MAX;
	}

	static glm::vec3 InUnitSphere(uint32_t& seed)
	{
		return glm::normalize(glm::vec3(RandomFloat(seed) * 2.0f - 1.0f, RandomFloat(seed) * 2.0f - 1.0f, RandomFloat(seed) * 2.0f - 1.0f));
	}

}

void Renderer::OnResize(uint32_t width, uint32_t height)
{
	if (m_FinalImage)
	{
		// No resize necessary
		if (m_FinalImage->GetWidth() == width && m_FinalImage->GetHeight() == height)
			return;

		m_FinalImage->Resize(width, height);
	}
	else
	{
		m_FinalImage = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];

	delete[] m_AccumulatedColor;
	m_AccumulatedColor = new glm::vec4[width * height];

	m_ImageHorizontalIter.resize(width);
	m_ImageVerticalIter.resize(height);
	for (uint32_t i = 0; i < width; ++i)
		m_ImageHorizontalIter[i] = i;
	for (uint32_t i = 0; i < height; ++i)
		m_ImageVerticalIter[i] = i;
}

void Renderer::Render(const Scene& scene, const Camera& camera)
{
	m_ActiveCamera = &camera;
	m_ActiveScene = &scene;

	if (m_FrameIndex == 1)
		memset(m_AccumulatedColor, 0, m_FinalImage->GetWidth() * m_FinalImage->GetHeight() * sizeof(glm::vec4));

#define MT 1
#if MT
	if (m_Settings.LimitThreads) {
		unsigned int numThreads = std::thread::hardware_concurrency() / 2;
		std::vector<std::future<void>> futures;
		auto renderTask = [this](uint32_t startY, uint32_t endY)
			{
				for (uint32_t y = startY; y < endY; ++y)
				{
					for (uint32_t x = 0; x < m_FinalImage->GetWidth(); ++x)
					{
						glm::vec4 color = PerPixel(x, y);

						m_AccumulatedColor[x + y * m_FinalImage->GetWidth()] += color;

						auto accumulatedColor = m_AccumulatedColor[x + y * m_FinalImage->GetWidth()];
						accumulatedColor /= (float)m_FrameIndex;

						accumulatedColor = glm::clamp(accumulatedColor, glm::vec4(0.0f), glm::vec4(1.0f));
						m_ImageData[x + y * m_FinalImage->GetWidth()] = Utils::ConvertToRGBA(accumulatedColor);
					}
				}
			};
		uint32_t height = m_FinalImage->GetHeight();
		uint32_t chunkSize = height / numThreads;
		for (unsigned int i = 0; i < numThreads; ++i)
		{
			uint32_t startY = i * chunkSize;
			uint32_t endY = (i == numThreads - 1) ? height : startY + chunkSize;
			futures.push_back(std::async(std::launch::async, renderTask, startY, endY));
		}
		for (auto& future : futures)
		{
			future.get();
		}
	}
	else
	{
		std::for_each(std::execution::par, m_ImageVerticalIter.begin(), m_ImageVerticalIter.end(),
			[this](uint32_t y)
			{
				std::for_each(std::execution::par, m_ImageHorizontalIter.begin(), m_ImageHorizontalIter.end(),
					[this, y](uint32_t x)
					{
						glm::vec4 color = PerPixel(x, y);

						m_AccumulatedColor[x + y * m_FinalImage->GetWidth()] += color;

						auto accumulatedColor = m_AccumulatedColor[x + y * m_FinalImage->GetWidth()];
						accumulatedColor /= (float)m_FrameIndex;

						accumulatedColor = glm::clamp(accumulatedColor, glm::vec4(0.0f), glm::vec4(1.0f));
						m_ImageData[x + y * m_FinalImage->GetWidth()] = Utils::ConvertToRGBA(accumulatedColor);
					});
			});
	}

#else
	for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++)
	{
		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++)
		{

			glm::vec4 color = PerPixel(x, y);

			m_AccumulatedColor[x + y * m_FinalImage->GetWidth()] += color;

			auto accumulatedColor = m_AccumulatedColor[x + y * m_FinalImage->GetWidth()];
			accumulatedColor /= (float)m_FrameIndex;

			accumulatedColor = glm::clamp(accumulatedColor, glm::vec4(0.0f), glm::vec4(1.0f));
			m_ImageData[x + y * m_FinalImage->GetWidth()] = Utils::ConvertToRGBA(accumulatedColor);
	}
}
#endif

	m_FinalImage->SetData(m_ImageData);

	if (m_Settings.Accumulate)
		++m_FrameIndex;
	else
		m_FrameIndex = 1;
}

glm::vec4 Renderer::PerPixel(uint32_t x, uint32_t y)
{
	Ray ray;
	ray.Origin = m_ActiveCamera->GetPosition();
	ray.Direction = m_ActiveCamera->GetRayDirections()[x + y * m_FinalImage->GetWidth()];

	glm::vec3 light(0.0f);
	int bounces = 5;

	uint32_t seed = x + y * m_FinalImage->GetWidth();
	seed *= m_FrameIndex;

	// 颜色贡献量
	glm::vec3 contribution(1.0f);

	for (int i = 0; i < bounces; ++i) {
		seed += i;

		auto payload = TraceRay(ray);


		if (payload.HitDistance < 0.0f)
		{
			if(m_Settings.EnableSkyColor){
				glm::vec3 skyColor(0.6f, 0.7f, 0.9f);
				light += skyColor * contribution;
			}
			break;
		}


		//glm::vec3 lightDir = glm::normalize(glm::vec3(-1, -1, -1));
		//float lightIntensity = glm::max(glm::dot(payload.WorldNormal, -lightDir), 0.0f); // == cos(angle)

		Sphere sphere = m_ActiveScene->Spheres[payload.ObjectIndex];
		Material material = m_ActiveScene->Materials[sphere.MaterialIndex];

		//glm::vec3 sphereColor = material.Albedo;
		//sphereColor *= lightIntensity;


		contribution *= material.Albedo;
		// 增加光能量
		light += material.GetEmission();

		ray.Origin = payload.WorldPosition + payload.WorldNormal * 0.00001f;
		//ray.Direction = glm::reflect(ray.Direction, payload.WorldNormal + material.Roughness * Walnut::Random::Vec3(-0.5f, 0.5f));
		if (m_Settings.SlowRandom) {
			ray.Direction = glm::normalize(Walnut::Random::InUnitSphere() + payload.WorldNormal);
		}
		else {
			// 这里先加一步粗的判断，直接判断是不是镜面的
			if (!material.Metallic) {
				ray.Direction = glm::normalize(Utils::InUnitSphere(seed) + payload.WorldNormal);
			}
			else
			{
				ray.Direction = glm::reflect(ray.Direction, material.Metallic * payload.WorldNormal);
			}
		}
	}

	return glm::vec4(light, 1.0f);
}

Renderer::HitPayLoad Renderer::ClosestHit(const Ray& ray, float hitDistance, int objectIndex)
{
	HitPayLoad payload;
	payload.HitDistance = hitDistance;
	payload.ObjectIndex = objectIndex;

	const Sphere& closestSphere = m_ActiveScene->Spheres[objectIndex];

	auto origin = ray.Origin - closestSphere.Position;
	payload.WorldPosition = origin + ray.Direction * hitDistance;
	payload.WorldNormal = glm::normalize(payload.WorldPosition);
	payload.WorldPosition += closestSphere.Position;

	return payload;

	//glm::vec3 lightDir = glm::normalize(glm::vec3(-1, -1, -1));
	//float lightIntensity = glm::max(glm::dot(normal, -lightDir), 0.0f); // == cos(angle)

	//glm::vec3 sphereColor = closestSphere.Albedo;
	//sphereColor *= lightIntensity;
	//return glm::vec4(sphereColor, 1.0f);
}

Renderer::HitPayLoad Renderer::Miss(const Ray& ray)
{
	HitPayLoad payload;
	payload.HitDistance = -1.0f;
	return payload;
}

Renderer::HitPayLoad Renderer::TraceRay(const Ray& ray)
{

	// rayDirection = glm::normalize(rayDirection);

	// (bx^2 + by^2)t^2 + (2(axbx + ayby))t + (ax^2 + ay^2 - r^2) = 0
	// where
	// a = ray origin
	// b = ray direction
	// r = radius
	// t = hit distance

	//if (scene.Spheres.size() == 0)
	//{
	//	return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	//}

	int  closestSphere = -1;
	float hitDistance = std::numeric_limits<float>::max();

	for (size_t i = 0; i < m_ActiveScene->Spheres.size(); ++i)
	{
		const Sphere& sphere = m_ActiveScene->Spheres[i];
		float radius = sphere.Radius;

		auto origin = ray.Origin - sphere.Position;

		float a = glm::dot(ray.Direction, ray.Direction);
		float b = 2.0f * glm::dot(origin, ray.Direction);
		float c = glm::dot(origin, origin) - radius * radius;

		// Quadratic forumula discriminant:
		// b^2 - 4ac

		float discriminant = b * b - 4.0f * a * c;
		if (discriminant < 0.0f)
			continue;

		// Quadratic formula:
		// (-b +- sqrt(discriminant)) / 2a

		float closestT = (-b - glm::sqrt(discriminant)) / (2.0f * a);
		//float t0 = (-b + glm::sqrt(discriminant)) / (2.0f * a); // Second hit distance (currently unused)

		if (closestT > 0.0f && closestT < hitDistance)
		{
			closestSphere = (int)i;
			hitDistance = closestT;
		}
	}

	if (closestSphere < 0)
	{
		return Miss(ray);
	}
	return ClosestHit(ray, hitDistance, closestSphere);

	//auto origin = ray.Origin - closestSphere->Position;
	//glm::vec3 hitPoint = origin + ray.Direction * hitDistance;
	//glm::vec3 normal = glm::normalize(hitPoint);

	//glm::vec3 lightDir = glm::normalize(glm::vec3(-1, -1, -1));
	//float lightIntensity = glm::max(glm::dot(normal, -lightDir), 0.0f); // == cos(angle)

	//glm::vec3 sphereColor = closestSphere->Albedo;
	//sphereColor *= lightIntensity;
	//return glm::vec4(sphereColor, 1.0f);
}