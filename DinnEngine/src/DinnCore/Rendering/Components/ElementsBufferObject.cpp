#include "C:/dev/DinnEngine/DinnEngine/CMakeFiles/DinnEngine.dir/Debug/cmake_pch.hxx"
#include "ElementsBufferObject.h"
#include <glad/glad.h>
 namespace Dinn
 {
	 EBO::ElementsBufferObject(uint32_t* indices, std::size_t size)
	 {
		 glGenBuffers(1, &ID);
		 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		 glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	 }

	 void EBO::Bind()
	 {
		 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	 }

	 void EBO::Unbind()
	 {
		 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	 }

	 void EBO::Delete()
	 {
		 glDeleteBuffers(1, &ID);
	 }
 }