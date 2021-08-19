#include "World.h"

World::~World()
{
	ClearAllEntities();
}

void World::Update()
{
	for (unsigned int i = 0; i < Entities.Count; i++) {
		if (Entities[i]->MarkedForDeletion) {
			delete Entities[i];
			Entities.EraseAt(i);
			i--;
		}
	}

	for (unsigned int i = 0; i < Entities.Count; i++) {
		Entities[i]->Update();
	}
}

void World::LateUpdate()
{
	for (unsigned int i = 0; i < Entities.Count; i++) {
		Entities[i]->LateUpdate();
	}
}

void World::OnRender()
{
	for (unsigned int i = 0; i < Entities.Count; i++) {
		Entities[i]->OnRender();
	}
}

void World::ClearAllEntities()
{
	for (unsigned int i = 0; i < Entities.Count; i++) {
		delete Entities[i];
	}
	Entities.Clear();
}
