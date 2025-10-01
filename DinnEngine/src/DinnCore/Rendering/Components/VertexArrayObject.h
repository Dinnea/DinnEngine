#pragma once
#include "VertexBufferObject.h"

namespace Dinn
{
	class VertexArrayObject
	{
		VertexArrayObject();
		~VertexArrayObject();

		void LinkVBO(VBO& VBO, uint32_t layout);
		void Bind();
		void Unbind();
		void Delete();

		uint32_t ID;
	};
	using VAO = VertexArrayObject;
}

