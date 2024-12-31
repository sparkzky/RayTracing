#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/Timer.h"

#include "Renderer.h"
#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>

using namespace Walnut;

void CreateHappyBirthday(Scene& scene)
{
	int materialIndex = 3;
	// H
	scene.Spheres.push_back({ { 0.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 1.0f, 2.0f, 0.0f }, 0.5f, materialIndex });

	// A
	scene.Spheres.push_back({ { 4.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 4.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 4.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 4.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, 3.0f, 0.0f }, 0.5f, materialIndex });

	// P 字形
	scene.Spheres.push_back({ { 8.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 9.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 9.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, 4.0f, 0.0f }, 0.5f, materialIndex });

	// P 字形
	scene.Spheres.push_back({ { 12.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 14.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 12.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 14.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 14.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 12.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 12.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 12.0f, 4.0f, 0.0f }, 0.5f, materialIndex });

	// Y 字形
	scene.Spheres.push_back({ { 17.0f, 2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 17.0f, 0.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 17.0f, 1.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, 4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, 3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, 4.0f, 0.0f }, 0.5f, materialIndex });

	// B
	scene.Spheres.push_back({ { 0.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 2.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 0.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 1.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 1.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 1.0f, -2.0f, 0.0f }, 0.5f, materialIndex });

	// I
	scene.Spheres.push_back({ { 4.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 4.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 5.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 6.0f, -2.0f, 0.0f }, 0.5f, materialIndex });

	// R
	scene.Spheres.push_back({ { 8.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 8.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 10.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 9.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 9.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 9.0f, -5.0f, 0.0f }, 0.5f, materialIndex });

	// T
	scene.Spheres.push_back({ { 12.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 13.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 14.0f, -2.0f, 0.0f }, 0.5f, materialIndex });

	// H
	scene.Spheres.push_back({ { 16.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ {18.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 16.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 18.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 17.0f, -4.0f, 0.0f }, 0.5f, materialIndex });

	// D
	scene.Spheres.push_back({ { 20.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 20.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 20.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 20.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 20.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 21.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 21.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 22.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 22.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 22.0f, -5.0f, 0.0f }, 0.5f, materialIndex });

	// A
	scene.Spheres.push_back({ { 24.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 24.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 24.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 24.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 25.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 25.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 26.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 26.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 26.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 26.0f, -3.0f, 0.0f }, 0.5f, materialIndex });

	// Y 字形
	scene.Spheres.push_back({ { 29.0f, -4.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 29.0f, -6.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 29.0f, -5.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 30.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 30.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 28.0f, -3.0f, 0.0f }, 0.5f, materialIndex });
	scene.Spheres.push_back({ { 28.0f, -2.0f, 0.0f }, 0.5f, materialIndex });
}

class ExampleLayer : public Walnut::Layer
{
public:
	ExampleLayer()
		: m_Camera(45.0f, 0.1f, 100.0f)
	{
		Material& pinkSphere = m_Scene.Materials.emplace_back();
		pinkSphere.Albedo = { 1.0f, 0.0f, 1.0f };
		pinkSphere.Roughness = 0.0f;

		Material& floorMaterial = m_Scene.Materials.emplace_back();
		floorMaterial.Albedo = { 0.8f, 0.8f, 0.8f };
		floorMaterial.Roughness = 0.5f;

		Material& orangeSphere = m_Scene.Materials.emplace_back();
		orangeSphere.Albedo = { 0.8f, 0.5f, 0.2f };
		orangeSphere.Roughness = 0.1f;
		orangeSphere.EmissionColor = orangeSphere.Albedo;
		orangeSphere.EmissionPower = 300.0f;

		Material& mirrorSphere = m_Scene.Materials.emplace_back();
		mirrorSphere.Albedo = { 0.8f, 0.8f, 0.8f };
		mirrorSphere.Roughness = 0.0f;
		mirrorSphere.Metallic = 1.0f;

		Material& shiningSphere = m_Scene.Materials.emplace_back();
		shiningSphere.Albedo = { 0.8f, 0.5f, 0.2f };
		shiningSphere.Roughness = 0.1f;
		shiningSphere.EmissionColor = shiningSphere.Albedo;
		shiningSphere.EmissionPower = 300.0f;

		{
			Sphere sphere;
			sphere.Position = { -1.2f, -4.2f, 0.0f };
			sphere.Radius = 1.0f;
			sphere.MaterialIndex = 0;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}

		{
			Sphere sphere;
			sphere.Position = { 7.8f, -0.5f, 0.9f };
			sphere.Radius = 4.8f;
			sphere.MaterialIndex = 2;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}

		{
			Sphere sphere;
			sphere.Position = { 1.0f, -260.49f, -11.2f };
			sphere.Radius = 255.5f;
			sphere.MaterialIndex = 1;
			//sphere.Mat.Albedo = { 0.2f, 0.3f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}

		{
			Sphere sphere;
			sphere.Position = { -3.4f, -5.2f, 2.8f };
			sphere.Radius = 0.2f;
			sphere.MaterialIndex = 4;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}

		{
			Sphere sphere;
			sphere.Position = { -0.2f, -3.9f, 5.2f };
			sphere.Radius = 1.61f;
			sphere.MaterialIndex = 3;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}


	}

	virtual void OnUpdate(float ts) override
	{
		if (m_Camera.OnUpdate(ts))
			m_Renderer.ResetFrameIndex();
	}

	virtual void OnUIRender() override
	{
		ImGui::Begin("Settings");
		ImGui::Text("Last render: %.3fms", m_LastRenderTime);
		ImGui::Text("FPS: %.1f", 1000.0f / m_LastRenderTime);
		//if (ImGui::Button("Render"))
		//{
		//	Render();
		//}
		ImGui::Checkbox("Accumulate", &m_Renderer.GetSettings().Accumulate);
		ImGui::Checkbox("Slow Random", &m_Renderer.GetSettings().SlowRandom);
		ImGui::Checkbox("Limit Threads", &m_Renderer.GetSettings().LimitThreads);
		ImGui::Checkbox("Sky Color", &m_Renderer.GetSettings().EnableSkyColor);
		if (ImGui::Button("Clear Scene"))
		{
			ClearScene();
			m_Renderer.ResetFrameIndex();
		}
		if (ImGui::Button("Create Ball"))
			CreateBall();
		if (ImGui::Button("Create Material")) {
			CreateMaterial();
		}

		if (ImGui::Button("Reset"))
		{
			m_Renderer.ResetFrameIndex();
		}
		if (ImGui::Button("Celebrate"))
		{
			Celebrate();
			m_Renderer.ResetFrameIndex();
		}
		ImGui::End();

		ImGui::Begin("Scene");
		for (size_t i = 0; i < m_Scene.Spheres.size(); i++)
		{
			ImGui::PushID(i);

			Sphere& sphere = m_Scene.Spheres[i];
			ImGui::Text("Ball %d", i);
			ImGui::DragFloat3("Position", glm::value_ptr(sphere.Position), 0.1f);
			ImGui::DragFloat("Radius", &sphere.Radius, 0.1f);
			ImGui::DragInt("Material Index", &sphere.MaterialIndex, 1.0f, 0, (int)(m_Scene.Materials.size() - 1));
			//ImGui::ColorEdit3("Albedo", glm::value_ptr(sphere.Mat.Albedo));
			//ImGui::DragFloat("Roughness", &sphere.Mat.Roughness);
			//ImGui::DragFloat("Metallic", &sphere.Mat.Metallic);

			ImGui::Separator();

			ImGui::PopID();
		}
		for (size_t i = 0; i < m_Scene.Materials.size(); ++i) {
			ImGui::PushID(i);

			Material& mat = m_Scene.Materials[i];

			ImGui::Text("Material %d", i);
			ImGui::ColorEdit3("Albedo", glm::value_ptr(mat.Albedo));
			ImGui::DragFloat("Roughness", &mat.Roughness, 0.05f, 0.0f, 1.0f);
			ImGui::DragFloat("Metallic", &mat.Metallic, 0.05f, 0.0f, 1.0f);
			ImGui::ColorEdit3("Emission Color", glm::value_ptr(mat.EmissionColor));
			ImGui::DragFloat("Emission Power", &mat.EmissionPower, 0.05f, 0.0f, FLT_MAX);

			ImGui::Separator();

			ImGui::PopID();
		}
		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("Viewport");

		m_ViewportWidth = ImGui::GetContentRegionAvail().x;
		m_ViewportHeight = ImGui::GetContentRegionAvail().y;

		auto image = m_Renderer.GetFinalImage();
		if (image)
			ImGui::Image(image->GetDescriptorSet(), { (float)image->GetWidth(), (float)image->GetHeight() },
				ImVec2(0, 1), ImVec2(1, 0));

		ImGui::End();
		ImGui::PopStyleVar();

		Render();
	}

	void ClearScene()
	{
		m_Scene.Spheres.clear();
	}

	void CreateBall()
	{
		Sphere sphere;
		sphere.Position = { 0.0f,100.0f,0.0f };
		sphere.Radius = 12.31f;
		sphere.MaterialIndex = 2;
		//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
		m_Scene.Spheres.push_back(sphere);
	}

	void CreateMaterial() {
		Material& orangeSphere = m_Scene.Materials.emplace_back();
		orangeSphere.Albedo = { 0.8f, 0.5f, 0.2f };
		orangeSphere.Roughness = 0.1f;
		orangeSphere.EmissionColor = orangeSphere.Albedo;
		orangeSphere.EmissionPower = 300.0f;
	}

	void Celebrate() {
		ClearScene();
		{
			Sphere sphere;
			sphere.Position = { -1.9f, -176.2f, 0.9f };
			sphere.Radius = 165.8f;
			sphere.MaterialIndex = 1;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}

		{
			Sphere sphere;
			sphere.Position = { 8.6f, -2.9f, 19.2f };
			sphere.Radius = 2.5f;
			sphere.MaterialIndex = 2;
			//sphere.Mat.Albedo = { 1.0f, 0.0f, 1.0f };
			m_Scene.Spheres.push_back(sphere);
		}
		CreateHappyBirthday(m_Scene);
	}

	void Render()
	{
		Timer timer;

		m_Renderer.OnResize(m_ViewportWidth, m_ViewportHeight);
		m_Camera.OnResize(m_ViewportWidth, m_ViewportHeight);
		m_Renderer.Render(m_Scene, m_Camera);

		m_LastRenderTime = timer.ElapsedMillis();
	}
private:
	Renderer m_Renderer;
	Camera m_Camera;
	Scene  m_Scene;
	uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

	float m_LastRenderTime = 0.0f;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "RatTracing";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					app->Close();
				}
				ImGui::EndMenu();
			}
		});
	return app;
}