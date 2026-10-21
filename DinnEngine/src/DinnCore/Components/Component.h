#pragma once
#include "DinnCore/GameObject.h"

namespace Dinn
{
	class GameObject;

	struct DINN_API Component
	{
		friend class GameObject;
		
		public:
			GameObject* GetOwner() const { return owner; }
			virtual ~Component(){}
			void SetActive(const bool active) { isActive = active; }
			bool IsActive() const { return IsActive() && owner->IsActive(); }

		protected:
			explicit Component(GameObject& owner) :owner(&owner){}
			virtual void Update() {}
			GameObject* owner;
		
	private:
		bool isActive = false;
	};
}
