#pragma once
#include <Entity.h>
#include <TransformComponent.h>

class Hivemind;

class EnemyEntity : public Entity
{
public:
	EnemyEntity(std::string name, Hivemind* hive);
	virtual ~EnemyEntity();

	void FireWeapon();
	void Delete() override;
protected:
	Hivemind* m_hive;
};

