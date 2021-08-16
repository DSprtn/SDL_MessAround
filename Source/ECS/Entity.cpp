#include "Entity.h"
#include <iostream>
#include <TransformComponent.h>


Entity::Entity(std::string name)
{
	Name = name;
	MarkedForDeletion = false;
	this->AddComponent<TransformComponent>(this);
}

Entity::~Entity()
{
	Components.clear();
}

void Entity::Update()
{
	for (Component* component : Components) {
		component->Update();
	}
}

void Entity::OnRender()
{
	for (Component* component : Components) {
		component->OnRender();
	}
}

void Entity::Delete() {
	MarkedForDeletion = true;
}

