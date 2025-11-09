#include "dnpch.h"
#include "glad/glad.h"
#include "gtc/type_ptr.hpp"
#include "Shader.h"

namespace Dinn
{
	Shader::Shader(const char* vertexFile, const char* fragmentFile)
	{
		std::string vertexCode = getFileContents(vertexFile);
		std::string fragmentCode = getFileContents(fragmentFile);

		if (vertexCode.empty())
		{
			DN_CORE_ERROR("Failed to load vertex shader from {0}", vertexFile);
			throw std::runtime_error("Failed to load vertex shader, empty string.");
		}

		if (fragmentCode.empty())
		{
			DN_CORE_ERROR("Failed to load fragment shader from {0}", fragmentFile);
			throw std::runtime_error("Failed to load frag shader, empty string.");
		}

		const char* vertexSource = vertexCode.c_str();
		const char* fragmentSource = fragmentCode.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);

		glLinkProgram(ID);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	Shader::~Shader()
	{
		Delete();
	}

	void Shader::SetMatrix4(const char* name, const glm::mat4& matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
	}

	void Shader::Activate()
	{
		glUseProgram(ID);
	}
	void Shader::Delete()
	{
		glDeleteProgram(ID);
	}

	//TODO: move this somewhere else
	std::string getFileContents(const char* filename)
	{
		std::ifstream file(filename, std::ios::in | std::ios::binary);

		if (!file) 
		{
			DN_CORE_ERROR("Failed to read file {0}", filename);
			return {};
		}

		// final string
		std::string contents;
		//moves start to end, find file len in bytes
		file.seekg(0, std::ios::end);
		//contents string exact size of file => saving space + performance
		contents.resize(file.tellg());
		//back to start
		file.seekg(0, std::ios::beg);
		//Reads the entire file into the string’s internal memory.
		//(&contents[0] - start
		//contents.size() - finish
		file.read(&contents[0], contents.size());
		file.close();
		return (contents);
	}
}
