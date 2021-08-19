#include "Collider.h"
#include <PhysicsSystem.h>


Collider::Collider(Entity* owner, TransformComponent* t) : Component(owner)
{
	Transform = t;
	PhysicsSystem::Instance->RegisterCollider(this);
}

Collider::~Collider()
{
	PhysicsSystem::Instance->UnregisterCollider(this);
}
