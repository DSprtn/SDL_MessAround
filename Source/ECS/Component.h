#pragma once
#include "Entity.h"

class Entity;

class Component
{
	public:

		virtual ~Component();
		Component(Entity* Owner);

		
		virtual void Update() = 0;
		virtual void Start() = 0;
		virtual void OnRender() = 0;

	protected:
		Entity* m_Owner;

	private:

		Component(const Component& that);
		Component& operator=(const Component& that);
};

