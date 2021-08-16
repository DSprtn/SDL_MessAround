#include "TransformComponent.h"

TransformComponent::TransformComponent(Entity* owner) : Component(owner)
{
	m_Owner = owner;
	PositionX = 0;
	PositionY = 0;
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::OnRender()
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
