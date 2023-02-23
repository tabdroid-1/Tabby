#if defined (TB_PLATFORM_WINDOWS)

#include "tbpch.h"
#include "Tabby/Core/Log.h"
#include "WindowsWindow.h"

#include "Tabby/Events/ApplicationEvent.h"
#include "Tabby/Events/MouseEvent.h"
#include "Tabby/Events/KeyEvent.h"

#include "Tabby/Renderer/GraphicsContext.h"
#include "Tabby/Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace Tabby {
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description) {
        TB_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props) { return new WindowsWindow(props); }

    WindowsWindow::WindowsWindow(const WindowProps &props) { Init(props); }

    WindowsWindow::~WindowsWindow() { Shutdown(); }

    void WindowsWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        TB_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            //TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            TB_CORE_ASSERT(success, "Could not initialize GLFW!");

            /** Enable if OpenGL version >= 4.1
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
             */
            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(m_Data.Width),
                                    static_cast<int>(m_Data.Height),
                                    m_Data.Title.c_str(), nullptr, nullptr);

        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        //Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            KeyTypedEvent event(keycode);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
            data.EventCallback(event);
        });

    }

    void WindowsWindow::Shutdown() { glfwDestroyWindow(m_Window); }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const { return m_Data.VSync; }
}

#endif // TB_PLATFORM_WINDOWS