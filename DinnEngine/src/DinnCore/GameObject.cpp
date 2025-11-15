#include "dnpch.h"
#include "Application.h"
#include "GameObject.h"
#include "Input.h"

namespace Dinn 
{
	GameObject::GameObject(unsigned int id) 
		: transform(std::make_unique<Transform>(*this)), id(id), context(&Application::Instance())
	{
	}

	void GameObject::Destroy()
	{
		context->Destroy(*this);
	}

	void GameObject::Update()
	{

		if (Input::GetKeyDown(Input::Keyboard::W))
		{
			transform->position += glm::vec2(0, 1);
		}

		if (Input::GetKeyDown(Input::Keyboard::S))
		{
			transform->position += glm::vec2(0, -1);
		}

		if (Input::GetKeyDown(Input::Keyboard::A))
		{
			transform->position += glm::vec2(-1, 0);
		}

		if (Input::GetKeyDown(Input::Keyboard::D))
		{
			transform->position += glm::vec2(1, 0);
		}
	}

	GameObject::~GameObject()
	{
		components.clear();
	}
}

