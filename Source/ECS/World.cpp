#include "World.h"

World::~World()
{
	ClearAllEntities();
}

void World::Update()
{
	for (int i = 0; i < Entities.Count; i++) {
		if (Entities[i]->MarkedForDeletion) {
			delete Entities[i];
			Entities.EraseAt(i);
			i--;
		}
	}

	for (int i = 0; i < Entities.Count; i++) {
		Entities[i]->Update();
	}
}

void World::LateUpdate()
{
	for (int i = 0; i < Entities.Count; i++) {
  		Entities[i]->LateUpdate();
	}
}

void World::OnRender()
{
	for (int i = 0; i < Entities.Count; i++) {
		Entities[i]->OnRender();
	}
}

void World::ClearAllEntities()
{
	Entities.Clear();
}
