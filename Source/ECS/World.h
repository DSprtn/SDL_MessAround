#pragma once
#include <vector>
#include <Entity.h>

class World
{
public:

	World() = default;
	~World();


	Entity** Entities = new Entity* [1024];

	void Update();
	void LateUpdate();
	void OnRender();
	void ClearAll();

	template <typename T, class... Args>
	T* CreateEntity(Args&&... args) {
		T* entity(new T(std::forward<Args>(args)...));
		Entities[EntityCount] = entity;
		EntityCount++;
		return entity;
	}

protected:
	unsigned int MaxEntites = 1024;
	unsigned int EntityCount = 0;

private:
	World(const World& that);
	World& operator=(const World& that);
};

