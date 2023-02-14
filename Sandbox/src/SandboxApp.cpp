#include "SandboxApp.h"

#include <Tabby/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp> // for glm::translate
#include <glm/gtc/type_ptr.hpp> // for glm::value_ptr

#include "Sandbox2D.h"

ExampleLayer::ExampleLayer()
        : Layer("Example"), m_CameraController(1280.0f / 720.0f, true) {

    m_VertexArray = Tabby::VertexArray::Create();

    float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f, // Left side of the screen
            0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,// Right side of the screen
            0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f // Top of screen
    };

    Tabby::Ref<Tabby::VertexBuffer> vertexBuffer = Tabby::VertexBuffer::Create(vertices, sizeof(vertices));
    Tabby::BufferLayout layout = {
            {Tabby::ShaderDataType::Float3, "a_Position"},
            {Tabby::ShaderDataType::Float4, "a_Color"}
    };
    vertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[3] = {0, 1, 2};
    Tabby::Ref<Tabby::IndexBuffer> indexBuffer = Tabby::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    m_VertexArray->SetIndexBuffer(indexBuffer);

    m_SquareVA = Tabby::VertexArray::Create();

    float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0, 0.0f,
            0.5f, 0.5f, 0.0f, 1.0, 1.0f,
            -0.5f, 0.5f, 0.0f, 0.0, 1.0f
    };

    Tabby::Ref<Tabby::VertexBuffer> squareVB = Tabby::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
    squareVB->SetLayout({
                                {Tabby::ShaderDataType::Float3, "a_Position"},
                                {Tabby::ShaderDataType::Float2, "a_TexCoord"}
                        });
    m_SquareVA->AddVertexBuffer(squareVB);

    uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};

    Tabby::Ref<Tabby::IndexBuffer> squareIB = Tabby::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
    m_SquareVA->SetIndexBuffer(squareIB);

    // Provide source code to OpenGL
    // `R` (raw_characters) precursor allows you to write multi-line string
    /** @param a_Position the position of @vertices
     * adding to a_Position will change the location of vertices */
    std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;

            void main() {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position =  u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

    // (1.0f, 0.0f, 0.0f) == Red
    // (1.0f, 0.5f, 0.15f) == Orange
    std::string fragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main() {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
                color = v_Color;
            }
        )";

    // Use std::reset to reset the shader
    m_Shader = Tabby::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

    std::string flatColorShaderVertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;

            void main() {
                v_Position = a_Position;
                gl_Position =  u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

    // (1.0f, 0.0f, 0.0f) == Red
    // (1.0f, 0.5f, 0.15f) == Orange
    std::string flatColorShaderFragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            uniform vec3 u_Color;

            void main() {
                color = vec4(u_Color, 1.0);
            }
        )";

    // Use std::reset to reset the shader
    m_FlatColorShader = Tabby::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

    // Use std::reset to reset the shader
    auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

    // Set texture
    m_Texture = Tabby::Texture2D::Create("assets/textures/Checkerboard1.png");
    m_TabbyLogoTexture = Tabby::Texture2D::Create("assets/textures/tabbyv2.png");

    // Bind and upload shader
    textureShader->Bind();
	textureShader->SetInt("u_Texture", 0);

}

void ExampleLayer::OnUpdate(Tabby::Timestep ts) {
    // Tabby::RenderCommand::GetError(); // Print any errors
    // TB_TRACE("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());

    // Update
    m_CameraSpeed = ts * 0.15;
    m_CameraController.OnUpdate(m_CameraSpeed);

    // Render
    Tabby::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1}); // Bkgd color
    Tabby::RenderCommand::Clear();

    Tabby::Renderer::BeginScene(m_CameraController.GetCamera());

    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

    // TODO: Add these two functions - Shader::SetMat4, Shader::Float4
    m_FlatColorShader->Bind();
	m_FlatColorShader->SetFloat3("u_Color", m_SquareColor);

    // Create square grid map
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
            glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
            Tabby::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
        }
    }

    auto textureShader = m_ShaderLibrary.Get("Texture");

    // Bind texture and render square
    m_Texture->Bind();
    Tabby::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
    m_TabbyLogoTexture->Bind();
    Tabby::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

    // Render triangle
    // Tabby::Renderer::Submit(m_Shader, m_VertexArray);

    Tabby::Renderer::EndScene();
}

void ExampleLayer::OnImGuiRender() {
    ImGui::Begin("Settings");
    ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void ExampleLayer::OnEvent(Tabby::Event &e) {
    m_CameraController.OnEvent(e);
}


class Sandbox : public Tabby::Application {
public:
    Sandbox() {
        // PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
    }

    ~Sandbox() {}
};

Tabby::Application *Tabby::CreateApplication() {
    return new Sandbox();
}
