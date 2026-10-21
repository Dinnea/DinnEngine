#pragma once
#include "Scene.h"
#include "Components/Component.h"
#include "Transform.h"
#include "Components/Sprite.h"

namespace Dinn
{
	class DINN_API GameObject
	{
		friend class Scene;
		
	public:
		GameObject(const GameObject&) = delete;
		GameObject& operator=(const GameObject&) = delete;
		GameObject(GameObject&&) = delete;
		GameObject& operator=(GameObject&&) = delete;

		Transform* GetTransform() const { return  transform.get(); }
		unsigned int ID() const { return id; }

		void SetActive(const bool active) { isActive = active; }
		
		bool IsActive() const { return isActive; }
		
		void Destroy();

		virtual void Update();

		~GameObject();

		template<class T, class ... Args>
		T& AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");
			
			if (auto* comp = GetComponent<T>())
			{
				DN_CORE_ERROR("Component {0} already exists on this object. Returning existing component.", typeid(T).name());
				return *comp;
			}
			
			auto componentPtr = std::make_unique<T>(*this, std::forward<Args>(args)...);
			T& ref = *componentPtr;
			
			components.push_back(std::move(componentPtr));
			
			if (isActive)
			{
				if (auto* sprite = dynamic_cast<Sprite*>(ref))
					context.RegisterSprite(sprite);
				
			}
			
			DN_CORE_INFO("Added Component: {0} to GameObject {1}", typeid(T).name(), id);
			return ref;
		}

		template<class T>
		T* GetComponent()
		{
			for (auto& component : components)
				if (auto ptr = dynamic_cast<T*>(component.get())) return ptr;

			//DN_CORE_WARN("No component of type {0} found", typeid(T).name());
			return nullptr;
		}
		
		template<class T>
		void RemoveComponent()
		{
			for (auto it = components.begin(); it != components.end(); ++it)
			{
				if (!dynamic_cast<T*>(it->get()))
					continue;
				
				if (auto* sprite = dynamic_cast<Sprite*>(it->get()))
					context.UnregisterSprite(sprite);
				
				
				components.erase(it);
				return;
			}
		}

		std::string name = "New Game Object";

	protected:
		std::unique_ptr<Transform> transform;

	private:
		GameObject(unsigned int id, Scene& scene);
		
		std::vector<std::unique_ptr<Component>> components;
		Scene& context;
		unsigned int id;
		bool isActive = false;
	};
}
