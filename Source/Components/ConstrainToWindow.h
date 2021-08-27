#pragma once

#include <Component.h>
#include <TransformComponent.h>
#include <SDL.h>

class ConstrainToWindow : public Component
{

public:
	ConstrainToWindow(Entity* owner, SDL_Window* window, TransformComponent* t);

	void Start() override {};
	void LateUpdate() override;

private:
	SDL_Window* m_gameWindow;
	TransformComponent* Transform;

};

