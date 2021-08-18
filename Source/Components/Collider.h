#pragma once
#include <Component.h>
#include "Entity.h"
#include <TransformComponent.h>
#include <SDL.h>

class Collider : public Component
{
public:
	Collider(Entity* owner, TransformComponent* t);
	virtual ~Collider();
	TransformComponent* m_transform;

	void Update() override {};
};

