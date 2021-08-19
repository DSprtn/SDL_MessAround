#include "World.h"

World::~World()
{
	ClearAllEntities();
}

void World::Update()
{
	for (int i = 0; i < Entities.size(); i++) {
		if (Entities[i]->MarkedForDeletion) {
			Entities.erase(Entities.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < Entities.size(); i++) {
		Entities[i]->Update();
	}
}

void World::LateUpdate()
{
	for (int i = 0; i < Entities.size(); i++) {
  		Entities[i]->LateUpdate();
	}
}

void World::OnRender()
{
	for (int i = 0; i < Entities.size(); i++) {
		Entities[i]->OnRender();
	}
}

void World::ClearAllEntities()
{
	Entities.clear();
}
