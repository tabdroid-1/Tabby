#pragma once

#include "Tabby.h"

class Sandbox2D : public Tabby::Layer {
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    virtual void OnUpdate(Tabby::Timestep ts) override;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(Tabby::Event &e) override;
private:
    Tabby::OrthographicCameraController m_CameraController;
    float m_CameraSpeed = 1.0f;

    // Temporary
    Tabby::Ref<Tabby::VertexArray> m_SquareVA;
    Tabby::Ref<Tabby::Shader> m_FlatColorShader;
    Tabby::Ref<Tabby::Framebuffer> m_Framebuffer;

    Tabby::Ref<Tabby::Texture2D> m_CheckerboardTexture;

    glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};

};
