#pragma once

#include <ECS/Component.h>
#include <TransformComponent.h>
#include <SDL.h>

class ConstrainToWindow : public Component
{

	public:
		ConstrainToWindow(Entity* owner, SDL_Window* window, TransformComponent* t);
		~ConstrainToWindow();

		void OnRender() override;
		void Update() override;
		void LateUpdate() override;
		void Start() override;
	private:

		SDL_Window* m_gameWindow;
		TransformComponent* m_transform;

};

