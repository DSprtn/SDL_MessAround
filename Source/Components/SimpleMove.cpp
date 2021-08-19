#include "SimpleMove.h"
#include <InputManager.h>
#include <Timer.h>

SimpleMove::SimpleMove(Entity* owner, float speed) : Component(owner)
{
	Speed = speed;
	Transform = owner->GetComponent<TransformComponent>();
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

	Transform->PositionX += xMovement * delta * Speed;
}
