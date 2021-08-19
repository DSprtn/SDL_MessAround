#pragma once
#include <Vector.h>
#include <Entity.h>

class World
{
public:

	World() = default;
	~World();

	std::vector<std::shared_ptr<Entity>> Entities;

	void Update();
	void LateUpdate();
	void OnRender();
	void ClearAllEntities();

	template <typename T, class... Args>
	std::shared_ptr<T> CreateEntity(Args&&... args) {
		std::shared_ptr<T> shared = std::make_shared<T>(std::forward<Args>(args)...);
		Entities.push_back(shared);
		return shared;
	}

private:
	World(const World& that);
	World& operator=(const World& that);
};

