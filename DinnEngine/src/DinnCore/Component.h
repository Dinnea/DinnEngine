#pragma once

namespace Dinn
{
	struct Component
	{
	friend class GameObject;
		public:
			GameObject* GetOwner() const { return owner; }

		protected:
			explicit Component(GameObject& owner) :owner(&owner){}

		private:
			GameObject* owner;

	};
}

