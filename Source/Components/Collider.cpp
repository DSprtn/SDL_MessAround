#include "Collider.h"
#include <PhysicsSystem.h>


Collider::Collider(Entity* owner, TransformComponent* t) : Component(owner)
{
	m_transform = t;
	PhysicsSystem::Instance->RegisterCollider(this);
}

Collider::~Collider()
{
	PhysicsSystem::Instance->UnregisterCollider(this);
}
