#pragma once


namespace Dinn 
{
	class TestRenderer
	{
	public:
		TestRenderer();
		~TestRenderer();
		void Init();
		void Draw(int width, int height);
		void Shutdown();

	private:
		uint32_t VAO = 0;
		uint32_t VBO = 0;
		uint32_t shaderProgram = 0;
	};
}

