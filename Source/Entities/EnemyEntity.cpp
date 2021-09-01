#include "EnemyEntity.h"
#include <Engine.h>
#include <RenderComponent.h>
#include <Collider.h>
#include <EnemyDestroyedParticle.h>
#include <BulletEntity.h>
#include <Hivemind.h>
#include <AnimateByDistance.h>
#include <GameGlobals.h>

EnemyEntity::EnemyEntity(std::string name, Hivemind* hive, EnemyType type) : Entity(name, 64, 64)
{
	m_hive = hive;
	AddComponent<RenderComponent>(Engine::Instance->Renderer);
	AddComponent<Collider>(Transform);
	AddTag("Enemy");
	m_scoreForKill = 10;
	m_type = type;
	Vector<std::string> textures;
	const float distAnim = 16;
	switch (type) {
		case EnemyType::Squid:
			m_scoreForKill = 30;
			textures.Add("Assets/InvaderC1.png");
			textures.Add("Assets/InvaderC2.png");
			break;
		case EnemyType::Normal:
			textures.Add("Assets/InvaderB1.png");
			textures.Add("Assets/InvaderB2.png");
			m_scoreForKill = 20;
			break;
		case EnemyType::Cloud:
			textures.Add("Assets/InvaderA1.png");
			textures.Add("Assets/InvaderA2.png");
			m_scoreForKill = 10;
			break;
	}
	AddComponent<AnimateByDistance>(Transform, textures, distAnim);
}

EnemyEntity::~EnemyEntity()
{
	if (m_hive != nullptr) {
		m_hive->EnemyDied(this);
	}
}

void EnemyEntity::FireWeapon()
{
	auto bullet = Engine::Instance->CurrentWorld->CreateEntity<BulletEntity>("FiredBullet", "Enemy", "Player", 800.0f, 0.0f);
	auto bulletTransform = bullet->GetComponent<TransformComponent>();
	bulletTransform->SetPosition(Transform->PositionX, (Transform->PositionY + Transform->Rect.h / 2));
}

void EnemyEntity::Delete()
{
	Entity::Delete();
	Engine::Instance->CurrentWorld->CreateEntity<EnemyDestroyedParticle>("Explosion", Transform->PositionX,Transform->PositionY, 48, 48);
	GameGlobals::Instance->scoreboard->IncrementScore(m_scoreForKill);
}
