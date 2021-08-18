#pragma once
#include "Entity.h"

class Entity;

class Component
{
public:
	Component(Entity* Owner);
	virtual ~Component() {};

	virtual void Update() = 0;
	virtual void LateUpdate() {};
	virtual void OnRender() {};
	virtual void OnCollide(Entity* B) {};

	Entity* m_Owner;

private:

	Component(const Component& that);
	Component& operator=(const Component& that);

};

