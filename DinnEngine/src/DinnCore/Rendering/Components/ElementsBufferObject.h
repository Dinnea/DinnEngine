#pragma once

namespace Dinn
{
	class ElementsBufferObject
	{
	public:
		ElementsBufferObject(uint32_t* indices, std::size_t size);

		void Bind();
		void Unbind();
		void Delete();

		uint32_t ID;
	};
	using EBO = ElementsBufferObject;
}
