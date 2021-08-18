#pragma once
#include <Entity.h>
#include <TransformComponent.h>


class EnemyEntity : public Entity
{
public:
	EnemyEntity(std::string name);
	virtual ~EnemyEntity();

	void FireWeapon();
	void Update() override;
	void LateUpdate() override;

private:
	TransformComponent* m_transform;
};

