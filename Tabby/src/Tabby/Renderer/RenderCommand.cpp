#include "RenderCommand.h"

#include <Tabby/Platform/OpenGL/OpenGLRendererAPI.h>

#include <glad/glad.h>

namespace Tabby {

    Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();

    void RenderCommand::GetError() {
        GLenum e = glGetError();
        if (e > 0) {
            TB_CORE_ERROR("OpenGL error: {0}", e);
        }
    }

}

