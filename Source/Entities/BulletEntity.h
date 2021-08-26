#pragma once
#include "Entity.h"
#include "TransformComponent.h"


class BulletEntity : public Entity
{
public:
	BulletEntity(std::string name, std::string srcTag, std::string targetTag, float xVel, float yVel);
	virtual ~BulletEntity();

	void Update() override;
	void OnCollide(Entity* other) override;

private:
	float xVelocity, yVelocity;
	std::string m_targetTag;
};

