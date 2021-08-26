#pragma once
#include <Vector.h>
#include <Entity.h>

class World
{
public:
	World() = default;
	~World();

	Vector<Entity*> Entities{ 128 };
	Vector<Entity*> InstantiatedEntities{ 64 };

	void Update();
	void LateUpdate();
	void OnRender();
	void ClearAllEntities();

	template <typename T, class... Args>
	T* CreateEntity(Args&&... args) {
		T* entity(new T(std::forward<Args>(args)...));
		InstantiatedEntities.Add(entity);
		return entity;
	}

private:
	void AddInstantiatedEntities();
	void CleanupDeletedEntities();


	World(const World& that);
	World& operator=(const World& that);
};

