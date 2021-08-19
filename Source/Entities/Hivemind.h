#pragma once
#include <Entity.h>
#include <EnemyEntity.h>

class Hivemind : public Entity
{
public:
	Hivemind(std::string name);


	void Update() override;
	void FireFromRandomEnemy();

	Vector<std::weak_ptr<EnemyEntity>> Enemies;

protected:
	float m_timeSinceFired = 0;
	float m_baseFireDelay = 1;
	float m_fireDelayVariance = 0.5f;
	float m_currentDelay = 1;
	int m_EnemiesWidth = 11;
	int m_EnemiesHeight = 5;
};

