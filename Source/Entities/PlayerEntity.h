#pragma once
#include <Entity.h>
#include <TransformComponent.h>

class PlayerEntity : public Entity
{
public:
	PlayerEntity(std::string Name);

	virtual void Update() override;

	void Delete() override;

private:
	float m_timeSinceFired;
	float m_fireDelay;

	void FireWeapon();
};

