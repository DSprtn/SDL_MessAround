#include "EnemyEntity.h"
#include <Core/Engine.h>
#include <RenderComponent.h>
#include <Collider.h>

EnemyEntity::EnemyEntity(std::string name) : Entity(name)
{
	TransformComponent* t = AddComponent<TransformComponent>(this, 64, 64);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\space_invader.png");
	AddComponent<Collider>(this, t);
	m_transform = t;
}

EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::FireWeapon()
{
}

void EnemyEntity::Update()
{
	Entity::Update();
}

void EnemyEntity::LateUpdate()
{
	Entity::LateUpdate();
}
