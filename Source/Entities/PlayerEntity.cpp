#include "PlayerEntity.h"
#include <TransformComponent.h>
#include <SimpleMove.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <ConstrainToWindow.h>
#include <Collider.h>
#include <InputManager.h>
#include <Timer.h>
#include <BulletEntity.h>
#include <EnemyDestroyedParticle.h>


PlayerEntity::PlayerEntity(std::string Name) : Entity(Name, 64, 64)
{
	m_transform->SetPosition(400, 900);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\ship.png");
	AddComponent<SimpleMove>(this, 400);
	AddComponent<ConstrainToWindow>(this, Engine::Instance->Window, m_transform);
	AddComponent<Collider>(this, m_transform);

	m_lastTimeBulletFired = -900;
	m_fireDelay = 900; // Ms
	
	AddTag("Player");
}

void PlayerEntity::Update()
{
	Entity::Update();

	if (InputManager::Instance->KeyDown(SDL_SCANCODE_SPACE) && Timer::TicksPassed - m_lastTimeBulletFired > m_fireDelay) {
		FireWeapon();
		m_lastTimeBulletFired = Timer::TicksPassed;
	}
}

void PlayerEntity::Delete() {
	Entity::Delete();
	Engine::Instance->CurrentWorld->CreateEntity<EnemyDestroyedParticle>("Explosion", m_transform->PositionX, m_transform->PositionY, 48, 48);
}

void PlayerEntity::FireWeapon()
{
	auto bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", "Enemy", -1000.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(m_transform->PositionX,( m_transform->PositionY - 10 - m_transform->Rect.h / 2));
}
