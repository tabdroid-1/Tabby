#include "tbpch.h"
#include "Platform/OSX/MacInput.h"

#include "Tabby/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Tabby {

    Scope<Input> Input::s_Instance = CreateScope<MacInput>();

    bool MacInput::IsKeyPressedImpl(KeyCode key) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));

        // Check if this key is currently pressed
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonPressedImpl(MouseCode button) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl() {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {static_cast<float>(xpos), static_cast<float>(ypos)};
    }

    float MacInput::GetMouseXImpl() {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }


    float MacInput::GetMouseYImpl() {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }

}