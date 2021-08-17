#pragma once
#include "ECS\Entity.h"
#include "ECS\Component.h"
#include <TransformComponent.h>
#include <SDL.h>

class RenderComponent : public Component
{
	public:
		RenderComponent(Entity* owner, SDL_Renderer* renderer, std::string TexturePath);
		~RenderComponent();

		void OnRender() override;
		void Update() override;
		void LateUpdate() override;
		void Start() override;
		

	private:
		SDL_Texture* m_Texture;
		SDL_Renderer* m_Renderer;
		TransformComponent* m_transform;
};

