#include "PhysicsSystem.h"


PhysicsSystem* PhysicsSystem::Instance = nullptr;


void PhysicsSystem::RegisterCollider(Collider* col)
{
	Colliders.push_back(col);
}

void PhysicsSystem::UnregisterCollider(Collider* col)
{
	Colliders.erase(std::find(Colliders.begin(), Colliders.end(), col));
}

void PhysicsSystem::Update()
{
	for (int i = 0; i < Colliders.size(); i++) {
		for (int j = 0; j < Colliders.size(); j++) {
			if (i != j) {
				const SDL_Rect A = Colliders[i]->m_transform->Rect;
				const SDL_Rect B = Colliders[j]->m_transform->Rect;
				
				if (SDL_HasIntersection(&A, &B)) {
					Colliders[i]->m_Owner->OnCollide(Colliders[j]->m_Owner);
					Colliders[j]->m_Owner->OnCollide(Colliders[i]->m_Owner);
				}
			}
		}
	}
}

PhysicsSystem::PhysicsSystem()
{
	Instance = this;
}

PhysicsSystem::~PhysicsSystem()
{
	Colliders.clear();
	Instance = nullptr;
}
