#pragma once
#include <ECS\Component.h>
#include "ECS\Entity.h"
#include <TransformComponent.h>
#include <SDL.h>

class Collider : public Component
{
	public:
		Collider(Entity* owner, TransformComponent* t);
		~Collider();
		TransformComponent* m_transform;

		void Update() override {};
};

