#include "dnpch.h"
#include "GameObject.h"
#include "Application.h"

namespace Dinn 
{
	GameObject::GameObject(unsigned int id) : transform(*this), id(id), context(&Application::Get())
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

