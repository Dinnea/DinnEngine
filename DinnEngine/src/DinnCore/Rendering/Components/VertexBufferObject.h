#pragma once

namespace Dinn
{
	class VertexBufferObject
	{
	public:

		VertexBufferObject(float* vertices, std::size_t size);
		~VertexBufferObject();

		void Bind();
		void Unbind();
		void Delete();

		uint32_t ID;
	};
	using VBO = VertexBufferObject;
}
