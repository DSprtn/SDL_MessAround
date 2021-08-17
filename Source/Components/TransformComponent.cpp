#include "TransformComponent.h"
#include <SDL_rect.h>

TransformComponent::TransformComponent(Entity* owner, int sizeX, int sizeY) : Component(owner)
{
	Rect = SDL_Rect();
	m_Owner = owner;
	PositionX = 0;
	PositionY = 0;

	Rect.w = sizeX;
	Rect.h = sizeY;
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::OnRender()
{

}

void TransformComponent::LateUpdate() 
{
}

void TransformComponent::Update()
{
}

void TransformComponent::Start()
{
}

void TransformComponent::SetPosition(float x, float y)
{
	PositionX = x;
	PositionY = y;
}
