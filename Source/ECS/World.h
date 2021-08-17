#pragma once
#include <vector>
#include <ECS/Entity.h>

class World
{
	public:

		World();
		~World();

		std::vector<Entity*> Entities;

		void Update();
		void LateUpdate();
		void OnRender();

		template <typename T, class... Args>
		T* CreateEntity(Args&&... args) {
			T* entity(new T(std::forward<Args>(args)...));
			Entities.push_back(entity);
			return entity;
		}


};

