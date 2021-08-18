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
	for (int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			delete Components[i];
			Components[i] = nullptr;
		}
	}
}

void Entity::Update()
{
	for (int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->Update();
		}
	}
}

void Entity::LateUpdate()
{
	for (int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->LateUpdate();
		}
	}
}

void Entity::OnRender()
{
	for (int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->OnRender();
		}
	}
}

void Entity::OnCollide(Entity* B)
{
	for (int i = 0; i < ComponentCount; i++) {
		if (Components[i] != nullptr) {
			Components[i]->OnCollide(B);
		}
	}
}

void Entity::Delete() {
	MarkedForDeletion = true;
}
