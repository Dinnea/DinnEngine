#pragma once
#include "Component.h"

namespace Dinn 
{
	struct DINN_API Transform : Component
	{
	friend class GameObject;

	public:
		Transform(GameObject& owner) : Component(owner)	{}

		glm::vec2 position = glm::vec2(0.f, 0.f);
		glm::vec2 scale = glm::vec2(1.f, 1.f);
		float angle = 0.f;
	};
}

