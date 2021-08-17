#include "SimpleMove.h"
#include <InputManager.h>
#include <Timer.h>

SimpleMove::SimpleMove(Entity* owner, float speed) : Component(owner)
{
	Speed = speed;
	m_transform = owner->GetComponent<TransformComponent>();
}

SimpleMove::~SimpleMove()
{
}

void SimpleMove::Update()
{
	InputManager* inputMgr = InputManager::GetInstance();
	float delta = Timer::DeltaTime;

	float xMovement = 0;

	if (inputMgr->KeyDown(SDL_SCANCODE_A)) {
		xMovement -= 1;
	}
	if (inputMgr->KeyDown(SDL_SCANCODE_D)) {
		xMovement += 1;
	}

	m_transform->PositionX += xMovement * delta * Speed;
}

void SimpleMove::LateUpdate()
{
}

void SimpleMove::Start()
{
}

void SimpleMove::OnRender()
{
}
