#include "tbpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define GL_EXT_texture_storage

namespace Tabby {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
            : m_WindowHandle(windowHandle) {
        TB_CORE_ASSERT(windowHandle, "Window Handle is null!")
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        TB_CORE_ASSERT(status, "Failed to initialize Glad!");

        TB_CORE_INFO("OpenGL info: ");
        TB_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
        TB_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
        TB_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));

    #ifdef TB_ENABLE_ASSERTS
        TB_CORE_ASSERT(GLVersion.major == 4 || (GLVersion.major == 4 && GLVersion.minor == 1), "Tabby requires at least OpenGL version 4.1!");
	#endif
    }



    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }
}