#pragma once

#include "Tabby/Core/Layer.h"

#include "Tabby/Events/ApplicationEvent.h"
#include "Tabby/Events/MouseEvent.h"
#include "Tabby/Events/KeyEvent.h"

namespace Tabby {

    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}
