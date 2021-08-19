#pragma once
#include <Vector.h>
#include <Entity.h>

class World
{
public:

	World() = default;
	~World();

	Vector<Entity*> Entities;

	void Update();
	void LateUpdate();
	void OnRender();
	void ClearAllEntities();

	template <typename T, class... Args>
	T* CreateEntity(Args&&... args) {
		T* entity(new T(std::forward<Args>(args)...));
		Entities.Add(entity);
		return entity;
	}

private:
	World(const World& that);
	World& operator=(const World& that);
};

