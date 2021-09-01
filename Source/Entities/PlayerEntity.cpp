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


PlayerEntity::PlayerEntity() : Entity("Player", 64, 64)
{
	AddComponent<RenderComponent>(Engine::Instance->Renderer, "Assets/ship.png");
	AddComponent<SimpleMove>(400);
	AddComponent<ConstrainToWindow>(Engine::Instance->Window, Transform);
	AddComponent<Collider>(Transform);

	m_timeSinceFired = .7f;
	m_fireDelay = .7f;
	
	AddTag("Player");
}

void PlayerEntity::Update()
{
	Entity::Update();
	m_timeSinceFired += Timer::DeltaTime;
	if (InputManager::Instance->KeyDown(SDL_SCANCODE_SPACE) && m_timeSinceFired > m_fireDelay) {
		FireWeapon();
		m_timeSinceFired = 0;
	}
}

void PlayerEntity::Delete() { 
	Entity::Delete();
	Engine::Instance->CurrentWorld->CreateEntity<EnemyDestroyedParticle>("Explosion", Transform->PositionX, Transform->PositionY, 48, 48);
}

void PlayerEntity::FireWeapon()
{
	auto bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", "Friendly", "Enemy", -1000.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(Transform->PositionX,( Transform->PositionY - 10 - Transform->Rect.h / 2));
}
