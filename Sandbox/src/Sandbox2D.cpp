#include "Sandbox2D.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp> // for glm::translate
#include <glm/gtc/type_ptr.hpp> // for glm::value_ptr

Sandbox2D::Sandbox2D() :
        Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {
}

void Sandbox2D::OnAttach() {

    TB_PROFILE_FUNCTION();

    m_CheckerboardTexture = Tabby::Texture2D::Create("assets/textures/Checkerboard2.png");
}

void Sandbox2D::OnDetach() {

    TB_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(Tabby::Timestep ts) {

    TB_PROFILE_FUNCTION();

	// Update
	{
		TB_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}

	{
		TB_PROFILE_SCOPE("Renderer Prep");
		Tabby::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Tabby::RenderCommand::Clear();
	}

	{
		TB_PROFILE_SCOPE("Renderer Draw");
		Tabby::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Tabby::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Tabby::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Tabby::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Tabby::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender() {

    TB_PROFILE_FUNCTION();

    ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(Tabby::Event &e) {
    m_CameraController.OnEvent(e);

}