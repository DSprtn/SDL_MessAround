#pragma once
#include <Entity.h>
#include <TransformComponent.h>

class Hivemind;

class EnemyEntity : public Entity
{
public:

	enum class EnemyType {
		Squid,
		Cloud,
		Normal
	};


	EnemyEntity(std::string name, Hivemind* hive, EnemyType type);
	virtual ~EnemyEntity();

	void FireWeapon();
	void Delete() override;
protected:
	Hivemind* m_hive;
	int m_scoreForKill;
	EnemyType m_type;
};

