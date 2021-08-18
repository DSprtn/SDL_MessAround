#pragma once
#include <Entity.h>
#include <TransformComponent.h>

class PlayerEntity : public Entity
{
public:
	PlayerEntity(std::string Name);
	virtual ~PlayerEntity();

	virtual void Update() override;

private:
	unsigned int m_lastTimeBulletFired;
	unsigned int m_fireDelay;

	TransformComponent* m_transform;


	void FireWeapon();
};

