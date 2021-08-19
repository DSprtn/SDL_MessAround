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
	for (unsigned int i = 0; i < Components.Count; i++) {
		delete Components[i];
	}
}

void Entity::Update()
{
	for (unsigned int i = 0; i < Components.Count; i++) {
		Components[i]->Update();
	}
}

void Entity::LateUpdate()
{
	for (unsigned int i = 0; i < Components.Count; i++) {
		Components[i]->LateUpdate();
	}
}

void Entity::OnRender()
{
	for (unsigned int i = 0; i < Components.Count; i++) {
		Components[i]->OnRender();
	}
}

void Entity::OnCollide(Entity* B)
{
	for (unsigned int i = 0; i < Components.Count; i++) {
		Components[i]->OnCollide(B);
	}
}

void Entity::Delete() {
	MarkedForDeletion = true;
}
