#include "TransformComponent.h"
#include <SDL_rect.h>

TransformComponent::TransformComponent(Entity* owner, int sizeX, int sizeY) : Component(owner)
{
	m_Owner = owner;
	PositionX = 0;
	PositionY = 0;

	Rect.w = sizeX;
	Rect.h = sizeY;
}

void TransformComponent::SetPosition(float x, float y)
{
	PositionX = x;
	PositionY = y;
}
