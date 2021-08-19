#pragma once
#include <Entity.h>
#include <TransformComponent.h>


class EnemyEntity : public Entity
{
public:
	EnemyEntity(std::string name);

	void FireWeapon();
	void Update() override;
	void LateUpdate() override;
	void Delete() override;
};

