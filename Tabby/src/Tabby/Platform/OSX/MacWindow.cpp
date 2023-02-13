#if defined (TB_PLATFORM_OSX)

#include "tbpch.h"
#include "MacWindow.h"

#include "Tabby/Core/Log.h"

#include "Tabby/Events/ApplicationEvent.h"
#include "Tabby/Events/MouseEvent.h"
#include "Tabby/Events/KeyEvent.h"

#include "Tabby/Renderer/GraphicsContext.h"
#include "Tabby/Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace Tabby {

    // static bool s_GLFWInitialized = false;
    static uint8_t s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char *description) {
        TB_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props) { 
        return new MacWindow(props); 
    }

    MacWindow::MacWindow(const WindowProps &props) { 
        Init(props); 
    }

    MacWindow::~MacWindow() { 
        Shutdown(); 
    }

    void MacWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        TB_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (s_GLFWWindowCount == 0) {
            //TODO: glfwTerminate on system shutdown
            TB_CORE_INFO("Initializing GLFW");
            int success = glfwInit();
            TB_CORE_ASSERT(success, "Could not initialize GLFW!");

            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwSetErrorCallback(GLFWErrorCallback);

            // s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr);
        ++s_GLFWWindowCount;

        m_Context = CreateScope<OpenGLContext>(m_Window);
        
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

    void MacWindow::Shutdown() { 
        glfwDestroyWindow(m_Window); 

        s_GLFWWindowCount -= 1;

        if (s_GLFWWindowCount == 0)
        {
			TB_CORE_INFO("Terminating GLFW");
			glfwTerminate();
		}
    }

    void MacWindow::OnUpdate() {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void MacWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        m_Data.VSync = enabled;
    }

    bool MacWindow::IsVSync() const { return m_Data.VSync; }
}

#endif // TB_PLATFORM_OSX