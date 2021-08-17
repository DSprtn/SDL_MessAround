#pragma once
#include <ECS\Entity.h>

#include <TransformComponent.h>

class PlayerEntity : public Entity
{
	public:
		PlayerEntity(std::string Name);
		~PlayerEntity();

		virtual void Update() override;

	private:
		unsigned int m_lastTimeBulletFired;
		unsigned int m_fireDelay;

		TransformComponent* m_transform;


		void FireWeapon();
};

