#include "C:/dev/DinnEngine/DinnEngine/CMakeFiles/DinnEngine.dir/Debug/cmake_pch.hxx"
#include "VertexBufferObject.h"
#include <glad/glad.h>

namespace Dinn 
{
	VBO::VertexBufferObject(uint32_t* vertices, std::size_t size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);

		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}
	VBO::~VertexBufferObject()
	{
		Delete();
	}

	void VBO::Bind() 
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void VBO::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VBO::Delete()
	{
		glDeleteBuffers(1, &ID);
	}
}