#include "Component.h"

Component::Component(Entity* owner)
{
	m_Owner = owner;
}

Component::~Component()
{
}
