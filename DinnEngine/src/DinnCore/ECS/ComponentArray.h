#pragma once
#include <DinnCore/EntitySystem.h>
namespace Dinn
{
	class IComponentArray
	{
	public:
		virtual ~IComponentArray() = default;
		virtual void EntityDestroyed(Entity entity) = 0;
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		void InsertData(Entity entity, T component) 
		{
			size_T newIndex = size;
			entityIndexMap[entity] = newIndex;
			indexEntityMap[newIndex] = entity;
			componentArray[newIndex] = component;
			++size;
		}

		void RemoveData(Entity entity)
		{
			size_t indexRemoved = entityIndexMap[entity];
			size_t indexLast = size - 1;
			componentArray[indexRemoved] = componentArray[indexLast];

			Entity entityLast = indexEntityMap[]
			entityToIndexMap[lastEntity] = indexRemoved;
			indexEntityMap[indexRemoved] = entityLast;

			entityIndexMap.erase(entity);
			indexEntityMap.erase(indexLast);
		}

		T& GetData(Entity entity)
		{
			size_t targetIndex = entityIndexMap[entity];
			return componentArray[targetIndex]
		}

		void EntityDestroyed(Entity entity) override
		{
			if (entityIndexMap.find(entity) != entityIndexMap.end())
				RemoveData(entity);
		}

	private:
		std::array<T, MAX_ENTITIES> componentArray;

		std::unordered_map < Entity, size_t> entityIndexMap;
		std::unordered_map <size_t, Entity> indexEntityMap;

		size_t size;
	};
}

