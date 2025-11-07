#include "dnpch.h"
#include "GameObject.h"

namespace Dinn 
{
	GameObject::GameObject() : transform(*this)
	{
	}

	GameObject::GameObject(std::string name) : transform(*this), name(name)
	{
	}

	GameObject::~GameObject()
	{
	}
}

