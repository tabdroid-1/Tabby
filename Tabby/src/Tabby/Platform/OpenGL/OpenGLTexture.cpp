#include "tbpch.h"
#include "OpenGLTexture.h"

#include "stb_image/stb_image.h"

namespace Tabby {

    OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{
		m_InternalFormat = GL_RGBA8;
		m_DataFormat = GL_RGBA;

        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}


    OpenGLTexture2D::OpenGLTexture2D(const std::string &path) : m_Path(path) {


        // GLenum internalFormat = (channels == 4) ? GL_RGBA8 : (channels == 3) ? GL_RGB8 : 0;
        // GLenum dataFormat = (channels == 4) ? GL_RGBA : (channels == 3) ? GL_RGB : 0;
        // TB_CORE_ASSERT((internalFormat & dataFormat), "Format not supported!");
        // m_InternalFormat = internalFormat;
        // m_DataFormat = dataFormat;
        
        int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		TB_CORE_ASSERT(data, "Failed to load image!");
		m_Width = width;
		m_Height = height;

		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}

		m_InternalFormat = internalFormat;
		m_DataFormat = dataFormat;

        TB_CORE_ASSERT(internalFormat & dataFormat, "Format not supported!");

        // Upload to GPU
        glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D() {
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::SetData(void* data, uint32_t size)
	{
		uint32_t bpp = m_DataFormat == GL_RGBA ? 4 : 3;
		TB_CORE_ASSERT(size == m_Width * m_Height * bpp, "Data must be entire texture!");
		// glTexSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
        
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
        glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);

	}

    void OpenGLTexture2D::Bind(uint32_t slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);  // might break somethings
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}
