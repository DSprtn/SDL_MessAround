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
	other->Delete();
	Delete();
}
