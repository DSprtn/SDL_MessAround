#include "World.h"

World::World()
{

}

World::~World()
{
	Entities.clear();
}

void World::Update()
{

	for (int i = 0; i < Entities.size(); i++) {
		if (Entities[i]->MarkedForDeletion) {
			Entities.erase(Entities.begin() + i);
		}
		else {
			Entities[i]->Update();
		}
	}
}

void World::OnRender()
{
	for (Entity* entity : Entities) {
		entity->OnRender();
	}
}
