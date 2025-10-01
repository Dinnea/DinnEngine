#include "C:/dev/DinnEngine/DinnEngine/CMakeFiles/DinnEngine.dir/Debug/cmake_pch.hxx"
#include "VertexArrayObject.h"
#include <glad/glad.h>

namespace Dinn
{
	VAO::VertexArrayObject() 
	{
		glGenVertexArrays(1, &ID);
	}
	VAO::~VertexArrayObject()
	{
	}

	void VAO::LinkVBO(VBO& VBO, uint32_t layout)
	{
		VBO.Bind();
		glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(layout);
		VBO.Unbind();
	}

	void VAO::Bind()
	{
		glBindVertexArray(ID);
	}

	void VAO::Unbind() 
	{
		glBindVertexArray(0);
	}

	void VAO::Delete()
	{
		glDeleteVertexArrays(1, &ID);
	}
}