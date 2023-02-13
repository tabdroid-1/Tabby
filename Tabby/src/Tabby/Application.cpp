#include "tbpch.h"
#include "Tabby/Application.h"

#include "Tabby/Core/Log.h"
#include "Tabby/Renderer/Renderer.h"
#include "Tabby/Core/Input.h"

#include <GLFW/glfw3.h>

namespace Tabby {

    Application *Application::s_Instance = nullptr;

    Application::Application() {

        TB_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = Scope<Window>(Window::Create());
        m_Window->SetEventCallback(TB_BIND_EVENT_FN(Application::OnEvent));

        Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        PushLayer(m_ImGuiLayer);
    }

    Application::~Application() {}

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer) {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(TB_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(TB_BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if (e.Handled()) {
                break;
            }
        }
    }

    void Application::Run() {
        float time = (float) glfwGetTime(); // Platform::GetTime()
        Timestep timestep = time - m_LastFrameTime;
        m_LastFrameTime = time;

        while (m_Running) {
            if (!m_Minimized) {
                for (Layer *layer : m_LayerStack) {
                    layer->OnUpdate(timestep);
                }
            }

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_LayerStack) {
                layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent(&e)) {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e) {
        if (e.GetWidth() == 0 || e.GetHeight() == 0) {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }

}




