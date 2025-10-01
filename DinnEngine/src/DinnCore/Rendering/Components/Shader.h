#pragma once

namespace Dinn 
{
	std::string getFileContents(const char* filename);
	class Shader
	{
	public:
		uint32_t ID;
		Shader(const char* vertex, const char* fragment);
		~Shader();

		void Activate();
		void Delete();
	};
}

