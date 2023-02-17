#include "tbpch.h"
#include "Tabby/Core/Input.h"

#include "Tabby/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Tabby {

    bool Input::IsKeyPressed(KeyCode key) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));

        // Check if this key is currently pressed
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonPressed(MouseCode button) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

        return state == GLFW_PRESS;
    }

    std::pair<float, float> Input::GetMousePosition() {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {static_cast<float>(xpos), static_cast<float>(ypos)};
    }

    float Input::GetMouseX() {
        auto[x, y] = GetMousePosition();
        return x;
    }


    float Input::GetMouseY() {
        auto[x, y] = GetMousePosition();
        return y;
    }

}