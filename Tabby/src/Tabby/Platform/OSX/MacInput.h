#pragma once

#include "Tabby/Core/Input.h"

namespace Tabby {

    class MacInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonImpl(const int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

    };
}