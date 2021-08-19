#include "RenderComponent.h"
#include <TextureManager.h>
#include <TransformComponent.h>
#include <iostream>


RenderComponent::RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string texturePath) : Component(owner)
{
	m_Renderer = renderer;
	m_Texture = TextureManager::GetTexture(texturePath, m_Renderer);
	Transform = m_Owner->GetComponent<TransformComponent>();
}

void RenderComponent::OnRender()
{
	if (m_Texture != nullptr) {
		SDL_Rect* rect = &Transform->Rect;
		rect->x = Transform->PositionX - rect->w / 2;
		rect->y = Transform->PositionY - rect->h / 2;
		SDL_RenderCopy(m_Renderer, m_Texture, NULL, &Transform->Rect);
	}
}
