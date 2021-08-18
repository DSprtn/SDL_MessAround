#include "World.h"

World::World()
{
}

World::~World()
{
	ClearAll();
}

void World::Update()
{
	for (int i = 0; i < EntityCount; i++) {
		if (Entities[i] == nullptr) {
			continue;
		}
		if (Entities[i]->MarkedForDeletion) {
			delete Entities[i];
			Entities[i] = nullptr;
		}
		else {
			Entities[i]->Update();
		}
	}
}

void World::LateUpdate()
{
	for (int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->LateUpdate();
		}
	}
}


void World::OnRender()
{
	for (int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->OnRender();
		}
	}
}

void World::ClearAll()
{
	for (int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->MarkedForDeletion = true;
		}
	}
}
