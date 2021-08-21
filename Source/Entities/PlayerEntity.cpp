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
	Transform->SetPosition(400, 900);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\ship.png");
	AddComponent<SimpleMove>(this, 400);
	AddComponent<ConstrainToWindow>(this, Engine::Instance->Window, Transform);
	AddComponent<Collider>(this, Transform);

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
	auto bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", "Enemy", -1000.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(Transform->PositionX,( Transform->PositionY - 10 - Transform->Rect.h / 2));
}
