#pragma once
#include <bitset>
#include <queue>
namespace Dinn
{
	using Entity = std::uint32_t;
	const Entity MAX_ENTITIES = 5000;

	using ComponentType = std::uint8_t;
	const ComponentType MAX_COMPONENTS = 32;
	using Signature = std::bitset<MAX_COMPONENTS>;

	struct Transform 
	{
		glm::vec2 position;
		glm::vec2 scale;

		float rotation;
	};

	class EntityManager
	{
	public:
		EntityManager()
		{
			//init all possible entities
			for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
			{
				availableEntities.push(entity);
			}
		}

		Entity CreateEntity() 
		{
			DN_CORE_ASSERT(livingEntityCount < MAX_ENTITIES, "Too many entities in existence");

			Entity id = availableEntities.front();
			availableEntities.pop();
			++livingEntityCount;

			return id;
		}

		void DestroyEntity(Entity entity) 
		{
			DN_CORE_ASSERT(livingEntityCount < MAX_ENTITIES, "Entity out of range.");

			signatures[entity].reset();

			availableEntities.push(entity);
			--livingEntityCount;
		}

		void SetSignature(Entity entity, Signature signature) 
		{
			DN_CORE_ASSERT(livingEntityCount < MAX_ENTITIES, "Entity out of range.");
			signatures[entity] = signature;
		}

		Signature GetSignture(Entity entity)
		{
			DN_CORE_ASSERT(livingEntityCount < MAX_ENTITIES, "Entity out of range.");
			return signatures[entity];
		}

	private:
		std::queue<Entity> availableEntities;
		std::array<Signature, MAX_ENTITIES> signatures;

		uint32_t livingEntityCount{};
	};
}
