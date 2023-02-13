#pragma once

#include "Tabby/Core/Core.h"

#include "Tabby/Core/Window.h"

#include "Tabby/Events/ApplicationEvent.h"
#include "Tabby/Events/Event.h"
#include "Tabby/Core/LayerStack.h"

#include "ImGui/ImGuiLayer.h"

#include "Tabby/Core/Timestep.h"

namespace Tabby {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        inline Window &GetWindow() { return *m_Window; }

        inline static Application &Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);
        bool OnWindowResize(WindowResizeEvent &e);
    private:
        Ref<Window> m_Window;
        ImGuiLayer *m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
    private:
        static Application *s_Instance;
    };

// To be defined by CLIENT
    Application *CreateApplication();
}

