#include "Collider.h"
#include <PhysicsSystem.h>


Collider::Collider(Entity* owner, TransformComponent* t) : Component(owner)
{
	Transform = t;
}

Collider::~Collider()
{
	PhysicsSystem::Instance->UnregisterCollider(this);
}

void Collider::Start()
{
	PhysicsSystem::Instance->RegisterCollider(this);
}
