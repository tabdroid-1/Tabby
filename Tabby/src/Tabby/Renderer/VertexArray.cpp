#include "tbpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Tabby/Platform/OpenGL/OpenGLVertexArray.h"

namespace Tabby {

    Ref <VertexArray> VertexArray::Create() {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None: TB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            case RendererAPI::API::OpenGL:return std::make_shared<OpenGLVertexArray>();
        }

        TB_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
