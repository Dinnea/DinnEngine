#pragma once
#include "DinnCore/Rendering/Components/Shader.h"

namespace Dinn
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		glm::vec2 position;
		glm::vec2 scale;
		float angle;
		std::shared_ptr<Shader> shaderOverride = nullptr;

	private:
		glm::mat4 model = glm::mat4(1.0f);
	};
}

