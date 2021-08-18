#pragma once
#include <ECS\Entity.h>
#include <TransformComponent.h>

class BulletEntity : public Entity
{
	public:
		BulletEntity(std::string name, float xVel, float yVel);
		virtual ~BulletEntity();

		void Update() override;
		void OnCollide(Entity* other) override;

	private:
		float xVelocity, yVelocity;
		TransformComponent* m_transform;
};

