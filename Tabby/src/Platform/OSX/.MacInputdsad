#pragma once

#include "Tabby/Core/Input.h"

namespace Tabby {

    class MacInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(KeyCode key) override;

        virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

    };
}