#include "Entity.h"
#include <iostream>
#include <TransformComponent.h>


Entity::Entity(std::string name)
{
	Name = name;
	MarkedForDeletion = false;
}

Entity::~Entity()
{
	for (unsigned int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			delete Components[i];
		}
	}
	delete[] Components;
}

void Entity::Update()
{
	for (unsigned int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->Update();
		}
	}
}

void Entity::LateUpdate()
{
	for (unsigned int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->LateUpdate();
		}
	}
}

void Entity::OnRender()
{
	for (unsigned int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->OnRender();
		}
	}
}

void Entity::OnCollide(Entity* B)
{
	for (unsigned int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->OnCollide(B);
		}
	}
}

void Entity::Delete() {
	MarkedForDeletion = true;
}
