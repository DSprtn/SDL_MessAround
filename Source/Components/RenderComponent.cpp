#include "RenderComponent.h"
#include <TextureManager.h>
#include <TransformComponent.h>
#include <iostream>


RenderComponent::RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string texturePath, int sizeX, int sizeY) : Component(owner)
{
	m_Renderer = renderer;
	m_Texture = TextureManager::GetTexture(texturePath, m_Renderer);

	DestRect = SDL_Rect();

	DestRect.w = sizeX;
	DestRect.h = sizeY;
	m_transform = m_Owner->GetComponent<TransformComponent>();
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::OnRender()
{
	if (m_Texture != nullptr) {
		DestRect.x = m_transform->PositionX - DestRect.w / 2;
		DestRect.y = m_transform->PositionY - DestRect.h / 2;
		SDL_RenderCopy(m_Renderer, m_Texture, NULL, &DestRect);
	}
}

void RenderComponent::Update()
{
}

void RenderComponent::Start()
{
}
