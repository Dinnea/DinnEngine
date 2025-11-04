#include "dnpch.h"
#include "Texture.h"
#include "../../../dependencies/stb/stb_image.h" //woah this is gross, need to fix this

namespace Dinn
{
	Texture::Texture(const char* image, uint32_t type, uint32_t slot, uint32_t format, uint32_t pixelType)
	{
		this->type = type;

		int width, height, colorChannels;

		stbi_set_flip_vertically_on_load(true);

		unsigned char* bytes = stbi_load(image, &width, &height, &colorChannels, STBI_rgb_alpha);
		if (!bytes)
		{
			DN_CORE_ERROR("stbi_load failed for '{}': {}", image, stbi_failure_reason());
			throw std::runtime_error("Texture load failed");
		}
		else
			DN_CORE_ERROR("not the issue");

		glGenTextures(1, &ID);

		glActiveTexture(slot);
		Bind();

		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(type, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);

		glGenerateMipmap(type);

		stbi_image_free(bytes);
		Unbind();
	}

	Texture::~Texture()
	{
		Delete();
	}

	void Texture::SetUniform(Shader& shader, const char* uniform, uint32_t unit)
	{
		GLuint texUniform = glGetUniformLocation(shader.ID, uniform);
		glUniform1i(texUniform, unit);
	}

	void Texture::Bind()
	{
		glBindTexture(type, ID);
	}

	void Texture::Unbind()
	{
		glBindTexture(type, 0);
	}

	void Texture::Delete()
	{
		glDeleteTextures(1, &ID);
	}
}
