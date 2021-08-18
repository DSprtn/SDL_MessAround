#include "SimpleMove.h"
#include <InputManager.h>
#include <Timer.h>

SimpleMove::SimpleMove(Entity* owner, float speed) : Component(owner)
{
	Speed = speed;
	m_transform = owner->GetComponent<TransformComponent>();
}

void SimpleMove::Update()
{
	float delta = Timer::DeltaTime;

	float xMovement = 0;

	if (InputManager::Instance->KeyDown(SDL_SCANCODE_A)) {
		xMovement -= 1;
	}
	if (InputManager::Instance->KeyDown(SDL_SCANCODE_D)) {
		xMovement += 1;
	}

	m_transform->PositionX += xMovement * delta * Speed;
}
