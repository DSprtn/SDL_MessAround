#include "World.h"

World::~World()
{
	ClearAllEntities();
}

void World::Update()
{
	CleanupDeletedEntities();
	AddInstantiatedEntities();

	for (int i = 0; i < Entities.Count; i++) {
		Entities[i]->Update();
	}
}

void World::AddInstantiatedEntities()
{
	for (int i = 0; i < InstantiatedEntities.Count; i++) {
		Entities.Add(InstantiatedEntities[i]);
		InstantiatedEntities[i]->Start();
	}
	InstantiatedEntities.Clear();
}

void World::CleanupDeletedEntities()
{
	for (int i = 0; i < Entities.Count; i++) {
		if (Entities[i]->MarkedForDeletion) {
			delete Entities[i];
			Entities.EraseAt(i);
			i--;
		}
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
	for (int i = 0; i < Entities.Count; i++) {
		delete Entities[i];
	}
	Entities.Clear();
}
