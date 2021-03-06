#include "Entity.h"
#include <iostream>
#include <TransformComponent.h>


Entity::Entity(std::string name, int sizeX, int sizeY)
{
	Name = name;
	MarkedForDeletion = false;
	Transform = AddComponent<TransformComponent>(sizeX, sizeY);
}

Entity::Entity(std::string Name) : Entity(Name, 1, 1) {}

Entity::~Entity()
{
	for (int i = 0; i < Components.Count; i++) {
		delete Components[i];
	}
}

void Entity::Start()
{
	for (int i = 0; i < Components.Count; i++) {
		Components[i]->Start();
	}
}

void Entity::Update()
{
	for (int i = 0; i < Components.Count; i++) {
		Components[i]->Update();
	}
}

void Entity::LateUpdate()
{
	for (int i = 0; i < Components.Count; i++) {
		Components[i]->LateUpdate();
	}
}

void Entity::OnRender()
{
	for (int i = 0; i < Components.Count; i++) {
		Components[i]->OnRender();
	}
}

void Entity::OnCollide(Entity* B)
{
	for (int i = 0; i < Components.Count; i++) {
		Components[i]->OnCollide(B);
	}
}

void Entity::Delete() {
	MarkedForDeletion = true;
}
