#pragma once
#include "Entity.h"
#include "Component.h"
#include <TransformComponent.h>
#include <SDL.h>

class RenderComponent : public Component
{
public:
	RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string TexturePath);

	void Update() override {};
	void OnRender() override;

private:
	SDL_Texture* m_Texture;
	SDL_Renderer* m_Renderer;
	TransformComponent* Transform;
};

