#include "tbpch.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

#include <glad/glad.h>

// namespace Tabby{

//     static const uint32_t s_MaxFrameBufferSize = 16384;

//     namespace Utils{
//         static GLenum TextureTarget(bool multisample){
//             return multisample ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
//         }
//         static void BindTexture(bool multisample, uint32_t id){
//             glBindTexture(TextureTarget(multisample),id);
//         }
//             static bool IsDepthFormat(FramebufferTextureFormat format){
//                 switch(format){
//                     case FramebufferTextureFormat::DEPTH24STENCIL8: return true;
//                 }
//                 return false;
//             }
//             static void CreateTextures(bool multisampled, uint32_t* outID, uint32_t count){
//                 glGenTextures(count, outID);
//                 glBindTexture(TextureTarget(multisampled),*outID);
//                 //glCreateTextures(TextureTarget(multisampled),count, outID);
//             }
//             static void AttachColorTexture(uint32_t id, int samples, GLenum internalformat, GLenum format, uint32_t width, uint32_t height, int index){
//                 bool multisampled = samples >1;
//                 if(multisampled){
//                     glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,samples, internalformat, width, height, GL_FALSE);
//                 }else{
//                     glTexImage2D(GL_TEXTURE_2D,0, internalformat, width, height, 0, format,GL_UNSIGNED_BYTE,nullptr);

//                     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//                     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//                     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//                     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//                     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//                 }
//                 glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0+index, TextureTarget(multisampled), id,0);
//             }
//         static void AttachDepthTexture(uint32_t id, int samples, GLenum format, GLenum attachmentType, uint32_t width, uint32_t height){
//            //TODO:figure out the issue with depth testing in the framebuffer
//            //I think that the internal format is not matching with the format being passed in
//             bool multisampled = samples >1;
//             if(multisampled){
//                 glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,samples, format, width, height, GL_FALSE);
//             }else{
//                 glTexImage2D(GL_TEXTURE_2D,0, format, width, height, 0, GL_RGBA,GL_UNSIGNED_BYTE,nullptr);

//                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//             }
//             glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, TextureTarget(multisampled), id,0);
//         }
//     };

//     OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec)
//             : m_Specification(spec)
//     {
//         for(auto format : m_Specification.Attachments.Attachments){
//             if(!Utils::IsDepthFormat(format.TextureFormat))
//                 m_ColorAttachmentSpecs.emplace_back(format);
//             else
//                 m_DepthAttachmentSpec = format;
//         }
//         Invalidate();
//     }

//     OpenGLFramebuffer::~OpenGLFramebuffer()
//     {
//         glDeleteFramebuffers(1, &m_RendererID);
//         glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
//         glDeleteTextures(1, &m_DepthAttachment);
//     }

//     void OpenGLFramebuffer::Invalidate()
//     {
//         if(m_RendererID){
//             glDeleteFramebuffers(1, &m_RendererID);
//             glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
//             glDeleteTextures(1, &m_DepthAttachment);

//             m_ColorAttachments.clear();
//             m_DepthAttachment = 0;
//         }

//         glGenFramebuffers(1,&m_RendererID);
//         glBindFramebuffer(GL_FRAMEBUFFER,m_RendererID);

//         bool multisampled = m_Specification.Samples >1;

//         if(!m_ColorAttachmentSpecs.empty()){

//             m_ColorAttachments.resize(m_ColorAttachmentSpecs.size());
//             Utils::CreateTextures(multisampled, m_ColorAttachments.data(),
//                                   m_ColorAttachments.size());


//             for(size_t i =0; i < m_ColorAttachmentSpecs.size(); i++){
//                 Utils::BindTexture(multisampled, m_ColorAttachments[i]);
//                 switch(m_ColorAttachmentSpecs[i].TextureFormat){
//                     case FramebufferTextureFormat::RGBA8:
//                         Utils::AttachColorTexture(m_ColorAttachments[i],
//                                                   m_Specification.Samples, GL_RGBA8, GL_RGBA,
//                                                   m_Specification.Width,m_Specification.Height,i);
//                         break;
//                     case FramebufferTextureFormat::RED_INTEGER:
//                         Utils::AttachColorTexture(m_ColorAttachments[i],
//                                                   m_Specification.Samples, GL_R32I, GL_RED_INTEGER,
//                                                   m_Specification.Width,m_Specification.Height,i);
//                         break;
//                 }
//             }
//         }
//         if(m_DepthAttachmentSpec.TextureFormat != FramebufferTextureFormat::None){
//             Utils::CreateTextures(multisampled,&m_DepthAttachment,1);
//             Utils::BindTexture(multisampled,m_DepthAttachment);
//             switch(m_DepthAttachmentSpec.TextureFormat){
//                 case FramebufferTextureFormat::DEPTH24STENCIL8:
// //                    Utils::AttachDepthTexture(m_DepthAttachment,m_Specification.Samples,GL_DEPTH24_STENCIL8,GL_DEPTH_ATTACHMENT,
// //                                              m_Specification.Width, m_Specification.Height);
//                     Utils::AttachColorTexture(m_DepthAttachment,
//                                               m_Specification.Samples,GL_DEPTH24_STENCIL8,GL_DEPTH24_STENCIL8,
//                                               GL_DEPTH_STENCIL_ATTACHMENT,m_Specification.Width,m_Specification.Height);
//                     break;
//             }
//         }

//         if(m_ColorAttachments.size() >1){
//             TB_CORE_ASSERT(m_ColorAttachments.size() <= 4,"");
//             GLenum buffers[4] = {GL_COLOR_ATTACHMENT0,GL_COLOR_ATTACHMENT1,GL_COLOR_ATTACHMENT2,GL_COLOR_ATTACHMENT3};
//             glDrawBuffers(m_ColorAttachments.size(),buffers);

//         }else if(m_ColorAttachments.empty()){
//             glDrawBuffer(GL_NONE);
//         }

//         if(!(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)){

//             TB_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE,
//                            "Framebuffer incomplete");

//         }

//         glBindFramebuffer(GL_FRAMEBUFFER,0);
//     }

//     void OpenGLFramebuffer::Bind()
//     {
//         glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
//         glViewport(0,0, m_Specification.Width, m_Specification.Height);

// //        int value = -1;
// //        glTexImage2D(GL_FRAMEBUFFER,0, GL_RGBA8, m_Specification.Width, m_Specification.Height,0,GL_RED_INTEGER,GL_INT,&value);

//     }

//     void OpenGLFramebuffer::UnBind()
//     {
//         glBindFramebuffer(GL_FRAMEBUFFER, 0);
//     }
//     void OpenGLFramebuffer::Resize(uint32_t width, uint32_t height) {

//         if(width ==0 || height == 0|| width >  s_MaxFrameBufferSize|| height > s_MaxFrameBufferSize){
//             TB_CORE_WARN("Attempted to resize framebuffer to {0}, {1}", width, height);
//             return;
//         }

//         m_Specification.Width = width;
//         m_Specification.Height = height;
//         Invalidate();
//     }

//     int OpenGLFramebuffer::ReadPixel(uint32_t attachmentidx, int x, int y) {
//         TB_CORE_ASSERT(attachmentidx< m_ColorAttachments.size(),"");
//         glReadBuffer(GL_COLOR_ATTACHMENT0+ attachmentidx);
//         int pixelData;
//         glReadPixels(x,y,1,1,GL_RED_INTEGER,GL_INT, &pixelData);
//         return pixelData;
//     }
// }

namespace Tabby{

    static const uint32_t s_MaxFrameBufferSize = 16384;

    namespace Utils{
        static GLenum TextureTarget(bool multisample){
            return multisample ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
        }
        static void BindTexture(bool multisample, uint32_t id){
            glBindTexture(TextureTarget(multisample),id);
        }
            static bool IsDepthFormat(FramebufferTextureFormat format){
                switch(format){
                    case FramebufferTextureFormat::DEPTH24STENCIL8: return true;
                }
                return false;
            }
            static void CreateTextures(bool multisampled, uint32_t* outID, uint32_t count){
                glGenTextures(count, outID);
                glBindTexture(TextureTarget(multisampled),*outID);
                //glCreateTextures(TextureTarget(multisampled),count, outID);
            }
            static void AttachColorTexture(uint32_t id, int samples, GLenum internalformat, GLenum format, uint32_t width, uint32_t height, int index){
                bool multisampled = samples >1;
                if(multisampled){
                    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,samples, internalformat, width, height, GL_FALSE);
                }else{
                    glTexImage2D(GL_TEXTURE_2D,0, internalformat, width, height, 0, format,GL_UNSIGNED_BYTE,nullptr);

                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                }
                glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0+index, TextureTarget(multisampled), id,0);
            }
        static void AttachDepthTexture(uint32_t id, int samples, GLenum format, GLenum attachmentType, uint32_t width, uint32_t height){
           //TODO:figure out the issue with depth testing in the framebuffer
           //I think that the internal format is not matching with the format being passed in
            bool multisampled = samples >1;
            if(multisampled){
                glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,samples, format, width, height, GL_FALSE);
            }else{
                glTexImage2D(GL_TEXTURE_2D,0, format, width, height, 0, GL_RGBA,GL_UNSIGNED_BYTE,nullptr);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }
            glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, TextureTarget(multisampled), id,0);
        }
    };

    OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec)
            : m_Specification(spec)
    {
        for(auto format : m_Specification.Attachments.Attachments){
            if(!Utils::IsDepthFormat(format.TextureFormat))
                m_ColorAttachmentSpecifications.emplace_back(format);
            else
                m_DepthAttachmentSpecification = format;
        }
        Invalidate();
    }

    OpenGLFramebuffer::~OpenGLFramebuffer()
    {
        glDeleteFramebuffers(1, &m_RendererID);
        glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
        glDeleteTextures(1, &m_DepthAttachment);
    }

    void OpenGLFramebuffer::Invalidate()
    {
        if(m_RendererID){
            glDeleteFramebuffers(1, &m_RendererID);
            glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
            glDeleteTextures(1, &m_DepthAttachment);

            m_ColorAttachments.clear();
            m_DepthAttachment = 0;
        }

        glGenFramebuffers(1,&m_RendererID);
        glBindFramebuffer(GL_FRAMEBUFFER,m_RendererID);

        bool multisampled = m_Specification.Samples >1;

        if(!m_ColorAttachmentSpecifications.empty()){

            m_ColorAttachments.resize(m_ColorAttachmentSpecifications.size());
            Utils::CreateTextures(multisampled, m_ColorAttachments.data(),
                                  m_ColorAttachments.size());


            for(size_t i =0; i < m_ColorAttachmentSpecifications.size(); i++){
                Utils::BindTexture(multisampled, m_ColorAttachments[i]);
                switch(m_ColorAttachmentSpecifications[i].TextureFormat){
                    case FramebufferTextureFormat::RGBA8:
                        Utils::AttachColorTexture(m_ColorAttachments[i],
                                                  m_Specification.Samples, GL_RGBA8, GL_RGBA,
                                                  m_Specification.Width,m_Specification.Height,i);
                        break;
                    case FramebufferTextureFormat::RED_INTEGER:
                        Utils::AttachColorTexture(m_ColorAttachments[i],
                                                  m_Specification.Samples, GL_R32I, GL_RED_INTEGER,
                                                  m_Specification.Width,m_Specification.Height,i);
                        break;
                }
            }
        }
        if(m_DepthAttachmentSpecification.TextureFormat != FramebufferTextureFormat::None){
            Utils::CreateTextures(multisampled,&m_DepthAttachment,1);
            Utils::BindTexture(multisampled,m_DepthAttachment);
            switch(m_DepthAttachmentSpecification.TextureFormat){
                case FramebufferTextureFormat::DEPTH24STENCIL8:
//                    Utils::AttachDepthTexture(m_DepthAttachment,m_Specification.Samples,GL_DEPTH24_STENCIL8,GL_DEPTH_ATTACHMENT,
//                                              m_Specification.Width, m_Specification.Height);
                    Utils::AttachColorTexture(m_DepthAttachment,
                                              m_Specification.Samples,GL_DEPTH24_STENCIL8,GL_DEPTH24_STENCIL8,
                                              GL_DEPTH_STENCIL_ATTACHMENT,m_Specification.Width,m_Specification.Height);
                    break;
            }
        }

        if(m_ColorAttachments.size() >1){
            TB_CORE_ASSERT(m_ColorAttachments.size() <= 4,"");
            GLenum buffers[4] = {GL_COLOR_ATTACHMENT0,GL_COLOR_ATTACHMENT1,GL_COLOR_ATTACHMENT2,GL_COLOR_ATTACHMENT3};
            glDrawBuffers(m_ColorAttachments.size(),buffers);

        }else if(m_ColorAttachments.empty()){
            glDrawBuffer(GL_NONE);
        }

        if(!(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)){

            TB_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE,
                           "Framebuffer incomplete");

        }

        glBindFramebuffer(GL_FRAMEBUFFER,0);
    }

    void OpenGLFramebuffer::Bind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
        glViewport(0,0, m_Specification.Width, m_Specification.Height);

//        int value = -1;
//        glTexImage2D(GL_FRAMEBUFFER,0, GL_RGBA8, m_Specification.Width, m_Specification.Height,0,GL_RED_INTEGER,GL_INT,&value);

    }

    void OpenGLFramebuffer::Unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    void OpenGLFramebuffer::Resize(uint32_t width, uint32_t height) {

        if(width ==0 || height == 0|| width >  s_MaxFrameBufferSize|| height > s_MaxFrameBufferSize){
            TB_CORE_WARN("Attempted to resize framebuffer to {0}, {1}", width, height);
            return;
        }

        m_Specification.Width = width;
        m_Specification.Height = height;
        Invalidate();
    }

    int OpenGLFramebuffer::ReadPixel(uint32_t attachmentidx, int x, int y) {
        TB_CORE_ASSERT(attachmentidx< m_ColorAttachments.size(),"");
        glReadBuffer(GL_COLOR_ATTACHMENT0+ attachmentidx);
        int pixelData;
        glReadPixels(x,y,1,1,GL_RED_INTEGER,GL_INT, &pixelData);
        return pixelData;
    }
}