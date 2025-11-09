#include "dnpch.h"
#include "Application.h"
#include "GameObject.h"

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

	GameObject::~GameObject()
	{
		components.clear();
	}
}

