#pragma once
#include "Entity.h"
#include "Component.h"
#include <TransformComponent.h>
#include <SDL.h>

class RenderComponent : public Component
{
public:
	RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string TexturePath);
	RenderComponent(Entity* owner, SDL_Renderer* renderer);

	void Update() override {};
	void OnRender() override;
	void SetTexture(SDL_Texture* tex);

private:
	SDL_Texture* m_Texture;
	SDL_Renderer* m_Renderer;
	TransformComponent* m_transform;
};

