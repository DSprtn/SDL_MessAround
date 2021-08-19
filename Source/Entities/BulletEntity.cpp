#include "BulletEntity.h"
#include <Collider.h>
#include <TransformComponent.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <Timer.h>

BulletEntity::BulletEntity(std::string name, float yVel, float xVel) : Entity(name)
{
	TransformComponent* t = AddComponent<TransformComponent>(this, 6, 23);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\laser.png");
	AddComponent<Collider>(this, t);

	xVelocity = xVel;
	yVelocity = yVel;
	m_transform = t;
	AddTag("Bullet");
}

BulletEntity::~BulletEntity()
{
}

void BulletEntity::Update()
{
	Entity::Update();
	m_transform->PositionX += xVelocity * Timer::DeltaTime;
	m_transform->PositionY += yVelocity * Timer::DeltaTime;
	m_currLifetime += Timer::DeltaTime;
	if (m_currLifetime > m_maxLifetime) {
		Delete();
	}
}

void BulletEntity::OnCollide(Entity* other)
{
	if (other->HasTag("Enemy")) {
		other->Delete();
		Delete();
	}
}
