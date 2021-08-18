#include "World.h"

World::World()
{

}

World::~World()
{
	for (unsigned int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			delete Entities[i];
		}
	}
	delete[] Entities;
}

void World::Update()
{
	for (unsigned int i = 0; i < EntityCount; i++) {
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
	for (unsigned int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->LateUpdate();
		}
	}
}


void World::OnRender()
{
	for (unsigned int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->OnRender();
		}
	}
}

void World::ClearAll()
{
	for (unsigned int i = 0; i < EntityCount; i++) {
		if (Entities[i] != nullptr) {
			Entities[i]->MarkedForDeletion = true;
		}
	}
}
