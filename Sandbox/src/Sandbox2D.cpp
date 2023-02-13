#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp> // for glm::translate
#include <glm/gtc/type_ptr.hpp> // for glm::value_ptr

Sandbox2D::Sandbox2D() :
        Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {
}

void Sandbox2D::OnAttach() {
    m_CheckerboardTexture = Tabby::Texture2D::Create("assets/textures/Checkerboard2.png");
}

void Sandbox2D::OnDetach() {
}

void Sandbox2D::OnUpdate(Tabby::Timestep ts) {
    // // Update
    // m_CameraSpeed = ts * 0.15;
    // m_CameraController.OnUpdate(m_CameraSpeed);

    // // Render
    // Tabby::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1}); // Background color
    // Tabby::RenderCommand::Clear();

    // Tabby::Renderer2D::BeginScene(m_CameraController.GetCamera());
    // Tabby::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
    // Tabby::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, {0.2f, 0.3f, 0.8f, 1.0f});
    // Tabby::Renderer2D::EndScene();

    // Update
    m_CameraSpeed = ts * 0.30;
	m_CameraController.OnUpdate(ts);

	// Render
	Tabby::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Tabby::RenderCommand::Clear();

	Tabby::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Tabby::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Tabby::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Tabby::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Tabby::Renderer2D::EndScene();

	// TODO: Add these functions - Shader::SetMat4, Shader::SetFloat4
	// std::dynamic_pointer_cast<Tabby::OpenGLShader>(m_FlatColorShader)->Bind();
	// std::dynamic_pointer_cast<Tabby::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender() {
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(Tabby::Event &e) {
    m_CameraController.OnEvent(e);

}