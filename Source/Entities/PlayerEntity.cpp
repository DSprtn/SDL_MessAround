#include "PlayerEntity.h"
#include <TransformComponent.h>
#include <SimpleMove.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <ConstrainToWindow.h>
#include <Collider.h>
#include <Core/InputManager.h>
#include <Timer.h>
#include <Entities/BulletEntity.h>


PlayerEntity::PlayerEntity(std::string Name) : Entity(Name)
{
	TransformComponent* t = AddComponent<TransformComponent>(this, 64, 64);
	t->SetPosition(640, 650);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\ship.png");
	AddComponent<SimpleMove>(this, 400);
	AddComponent<ConstrainToWindow>(this, Engine::Instance->Window, t);
	AddComponent<Collider>(this, t);

	m_lastTimeBulletFired = 0;
	m_fireDelay = 1000; // Ms
	m_transform = t;
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::Update()
{
	Entity::Update();
	InputManager* inputMgr = InputManager::GetInstance();

	if (inputMgr->KeyDown(SDL_SCANCODE_SPACE) && Timer::TicksPassed - m_lastTimeBulletFired > m_fireDelay) {
		FireWeapon();
		m_lastTimeBulletFired = Timer::TicksPassed;
	}
}

void PlayerEntity::FireWeapon()
{
	BulletEntity* bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", -1000.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(m_transform->PositionX,( m_transform->PositionY - 10 - m_transform->Rect.h / 2));
}
