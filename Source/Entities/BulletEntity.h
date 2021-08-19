#pragma once
#include <Entity.h>
#include <TransformComponent.h>

class BulletEntity : public Entity
{
public:
	BulletEntity(std::string name, float xVel, float yVel);
	virtual ~BulletEntity();

	void Update() override;
	void OnCollide(Entity* other) override;

private:
	float m_maxLifetime = 1;
	float m_currLifetime = 0;
	float xVelocity, yVelocity;
	TransformComponent* m_transform;
};

