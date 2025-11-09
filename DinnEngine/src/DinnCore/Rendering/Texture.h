#pragma once
#include<glad/glad.h>
#include "Components/Shader.h"
namespace Dinn
{
	class DINN_API Texture
	{
	public:
		Texture(const char* image, uint32_t type, uint32_t slot, uint32_t format, uint32_t pixelType);
		~Texture();

		void SetUniform(Shader& shader, const char* uniform, uint32_t unit);
		uint32_t ID;
		uint32_t type;

		void Bind();
		void Unbind();
		void Delete();
	};
}

