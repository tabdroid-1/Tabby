#pragma once

#include "Tabby/Renderer/Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>


namespace Tabby {

    class OpenGLShader : public Shader {
    public:
        OpenGLShader(const std::string &filepath);
        OpenGLShader(const std::string& name, const std::string &vertexSrc, const std::string &fragmentSrc);
        ~OpenGLShader();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        // virtual void SetInt(const std::string& name, int value) override;
		// virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		// virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		// virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

        virtual void SetInt(const std::string& name, int value);
		virtual void SetFloat3(const std::string& name, const glm::vec3& value);
		virtual void SetFloat4(const std::string& name, const glm::vec4& value);
		virtual void SetMat4(const std::string& name, const glm::mat4& value);

        const virtual std::string& GetName() const override { return m_Name;}

        void UploadUniformInt(const std::string &name, const int value);

        void UploadUniformFloat(const std::string &name, const float value);
        void UploadUniformFloat2(const std::string &name, const glm::vec2 &values);
        void UploadUniformFloat3(const std::string &name, const glm::vec3 &values);
        void UploadUniformFloat4(const std::string &name, const glm::vec4 &values);

        void UploadUniformMat3(const std::string &name, const glm::mat3 &matrix);
        void UploadUniformMat4(const std::string &name, const glm::mat4 &matrix);
    private:
        std::string ReadFile(const std::string &filepath);
        std::unordered_map<GLenum, std::string> PreProcess(const std::string &source);
        void Compile(std::unordered_map<GLenum, std::string> &shaderSources);
    private:
        uint32_t m_RendererID;
        std::string m_Name;
    };

}