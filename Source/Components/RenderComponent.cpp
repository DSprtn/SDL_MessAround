#include "RenderComponent.h"
#include <TextureManager.h>
#include <TransformComponent.h>
#include <iostream>


RenderComponent::RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string texturePath) : Component(owner)
{
	m_Renderer = renderer;
	m_transform = m_Owner->GetComponent<TransformComponent>();
	m_Texture = TextureManager::GetTexture(texturePath, m_Renderer);
	
}

RenderComponent::RenderComponent(Entity* owner, SDL_Renderer* renderer) : Component(owner)
{
	m_Renderer = renderer;
	m_transform = m_Owner->GetComponent<TransformComponent>();
	m_Texture = nullptr;
}

void RenderComponent::OnRender()
{
	if (m_Texture != nullptr) {
		SDL_Rect* rect = &m_transform->Rect;
		rect->x = m_transform->PositionX - rect->w / 2;
		rect->y = m_transform->PositionY - rect->h / 2;
		SDL_RenderCopy(m_Renderer, m_Texture, NULL, &m_transform->Rect);
	}
}

void RenderComponent::SetTexture(SDL_Texture* tex)
{
	m_Texture = tex;
}
