#include "SimpleMove.h"
#include <InputManager.h>
#include <Timer.h>

SimpleKBMoveComponent::SimpleKBMoveComponent(Entity* owner, float speed) : Component(owner)
{
	Speed = speed;
	m_transform = owner->GetComponent<TransformComponent>();
}

SimpleKBMoveComponent::~SimpleKBMoveComponent()
{
}

void SimpleKBMoveComponent::Update()
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

void SimpleKBMoveComponent::LateUpdate()
{
}

void SimpleKBMoveComponent::Start()
{
}

void SimpleKBMoveComponent::OnRender()
{
}
