#include "TransformComponent.h"
#include <SDL_rect.h>
#include <Engine.h>

TransformComponent::TransformComponent(Entity* owner, int sizeX, int sizeY) : Component(owner)
{
	m_Owner = owner;
	PositionX = 0;
	PositionY = 0;

	Rect.w = sizeX;
	Rect.h = sizeY;
}

bool TransformComponent::OutsideWindow() {
	int sizeX = 0;
	int sizeY = 0;
	SDL_GetWindowSize(Engine::Instance->Window, &sizeX, &sizeY);

	return Rect.x + Rect.w >= sizeX || Rect.y + Rect.h / 2 > sizeY || Rect.x - Rect.w <= 0 || Rect.y - Rect.h / 2 < 0;
}

void TransformComponent::SetPosition(float x, float y)
{
	PositionX = x;
	PositionY = y;
	Rect.x = PositionX - Rect.w / 2;
	Rect.y = PositionY - Rect.h / 2;
}
