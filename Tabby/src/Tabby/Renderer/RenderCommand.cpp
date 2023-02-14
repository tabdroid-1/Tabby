#include "Tabby/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Tabby {

    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

    void RenderCommand::GetError() {
        GLenum e = glGetError();
        if (e > 0) {
            TB_CORE_ERROR("OpenGL error: {0}", e);
        }
    }

}

