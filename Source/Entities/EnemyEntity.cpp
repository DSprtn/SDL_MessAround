#include "EnemyEntity.h"
#include <Engine.h>
#include <RenderComponent.h>
#include <Collider.h>
#include <EnemyDestroyedParticle.h>
#include <BulletEntity.h>
#include <Hivemind.h>

EnemyEntity::EnemyEntity(std::string name, Hivemind* hive) : Entity(name, 64, 64)
{
	m_hive = hive;
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\space_invader.png");
	AddComponent<Collider>(this, Transform);
	AddTag("Enemy");
}

EnemyEntity::~EnemyEntity()
{
	if (m_hive != nullptr) {
		m_hive->EnemyDied(this);
	}
}

void EnemyEntity::FireWeapon()
{
	auto bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", "Player", 800.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(Transform->PositionX, (Transform->PositionY + Transform->Rect.h / 2));
}

void EnemyEntity::Delete()
{
	Entity::Delete();
	Engine::Instance->CurrentWorld->CreateEntity<EnemyDestroyedParticle>("Explosion", Transform->PositionX,Transform->PositionY, 48, 48);
}
