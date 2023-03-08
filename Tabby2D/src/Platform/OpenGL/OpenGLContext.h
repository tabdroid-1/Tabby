#pragma once

#include "Tabby/Renderer/GraphicsContext.h"

class GLFWwindow;

namespace Tabby {

    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow *m_WindowHandle;
    };
}