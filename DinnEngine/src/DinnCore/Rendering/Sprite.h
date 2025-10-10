#pragma once
#include "DinnCore/Rendering/Components/Shader.h"

namespace Dinn
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		glm::vec2 position = glm::vec2(0.0, 0.0);
		glm::vec2 scale = glm::vec2(1.0, 1.0);
		float angle = 0;
		std::shared_ptr<Shader> shaderOverride = nullptr;

	private:
		glm::mat4 model = glm::mat4(1.0f);
	};
}

