#include "BulletEntity.h"
#include <Collider.h>
#include <TransformComponent.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <Timer.h>
#include <DestroyAfterLifetime.h>

BulletEntity::BulletEntity(std::string name, std::string targetTag, float yVel, float xVel) : Entity(name, 6, 23)
{
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\laser.png");
	AddComponent<Collider>(this, m_transform);
	AddComponent<DestroyAfterLifetime>(this, 1.5f);

	xVelocity = xVel;
	yVelocity = yVel;
	
	AddTag("Bullet");
	m_targetTag = targetTag;
}

BulletEntity::~BulletEntity()
{
}

void BulletEntity::Update()
{
	Entity::Update();
	m_transform->PositionX += xVelocity * Timer::DeltaTime;
	m_transform->PositionY += yVelocity * Timer::DeltaTime;
}

void BulletEntity::OnCollide(Entity* other)
{
	if (other->HasTag(m_targetTag)) {
		other->Delete();
		Delete();
	}
}
