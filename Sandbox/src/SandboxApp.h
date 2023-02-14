#include <Tabby.h>

class ExampleLayer : public Tabby::Layer {
public:
    ExampleLayer();
    void OnUpdate(Tabby::Timestep ts) override;

    virtual void OnImGuiRender() override;

    void OnEvent(Tabby::Event &e) override;

private:
    Tabby::ShaderLibrary m_ShaderLibrary;
    Tabby::Ref<Tabby::Shader> m_Shader;
    Tabby::Ref<Tabby::VertexArray> m_VertexArray;

    Tabby::Ref<Tabby::Shader> m_FlatColorShader;
    Tabby::Ref<Tabby::VertexArray> m_SquareVA;

    Tabby::Ref<Tabby::Texture2D> m_Texture, m_TabbyLogoTexture;

    Tabby::OrthographicCameraController m_CameraController;
        float m_CameraSpeed = 1.0f;

    glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};

};