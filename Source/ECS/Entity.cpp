#include "Entity.h"
#include <iostream>
#include <TransformComponent.h>


Entity::Entity(std::string name, int sizeX, int sizeY)
{
	Name = name;
	MarkedForDeletion = false;
	m_transform = AddComponent<TransformComponent>(this, sizeX, sizeY).lock().get();
}

Entity::Entity(std::string Name) : Entity(Name, 1, 1) {};

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
