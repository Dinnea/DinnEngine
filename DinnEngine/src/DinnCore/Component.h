#pragma once

namespace Dinn
{
	struct DINN_API Component
	{
	friend class GameObject;
		public:
			GameObject* GetOwner() const { return owner; }
			virtual ~Component() = default;

		protected:
			explicit Component(GameObject& owner) :owner(&owner){}

		private:
			GameObject* owner;
	};
}

