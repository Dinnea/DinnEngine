#include "dnpch.h"
#include "Application.h"
#include "GameObject.h"

namespace Dinn 
{
	GameObject::GameObject(unsigned int id, Scene& scene) 
		: transform(std::make_unique<Transform>(*this)), id(id), context(scene)
	{
	}

	void GameObject::Destroy()
	{
		context.Destroy(*this);
	}

	void GameObject::Update()
	{
		for (const auto& component : components)
			component->Update();
	}

	GameObject::~GameObject()
	{
		if (auto* sprite = GetComponent<Sprite>())
			context.UnregisterSprite(sprite);
		
		
		components.clear();
	}
}

