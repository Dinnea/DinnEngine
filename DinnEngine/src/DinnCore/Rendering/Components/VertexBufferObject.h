#pragma once

namespace Dinn
{
	class VertexBufferObject
	{
	public:

		VertexBufferObject(uint32_t* vertices, std::size_t size);
		~VertexBufferObject();

		void Bind();
		void Unbind();
		void Delete();

		uint32_t ID;
	};
	using VBO = VertexBufferObject;
}

