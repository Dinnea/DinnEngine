#pragma once
#include "Component.h"
#include "Transform.h"

namespace Dinn
{
	class Application;

	class GameObject
	{
	public:
		GameObject(unsigned int id);
		GameObject(const GameObject&) = delete;
		GameObject& operator=(const GameObject&) = delete;
		GameObject(GameObject&&) = delete;
		GameObject& operator=(GameObject&&) = delete;

		Transform& GetTransform() { return transform; }
		unsigned int ID() const { return id; }

		void Destroy();

		~GameObject();

		template<class T, class ... Args>
		T& AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");

			auto componentPtr = std::make_unique<T>(*this, std::forward<Args>(args)...);
			T& ref = *p;
			components.push_back(std::move(componentPtr)
		}

		template<class T>
		T* GetComponent()
		{
			for (auto& component : components)
				if (auto ptr = dynamic_cast<T*>(component.get())) return ptr;

			DN_CORE_INFO("No component of type {0} found", typeid(T).name())
			return nullptr;
		}

		std::string name = "New Game Object";


	private:
		unsigned int id;
		Transform transform;
		std::vector<std::unique_ptr<Component>> components;
		Application* context;
	};
}


