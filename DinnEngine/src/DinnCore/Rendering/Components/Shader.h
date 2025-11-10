#pragma once

namespace Dinn 
{
	std::string getFileContents(const char* filename);
	class DINN_API Shader
	{
	public:
		uint32_t ID;
		Shader(const char* vertex, const char* fragment);
		~Shader();

		void Activate();
		void Delete();

		//Add data to shader methods
		void SetMatrix4(const char* name, const glm::mat4& matrix);
	};
}
