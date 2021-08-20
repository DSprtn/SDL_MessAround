#pragma once
#include <Entity.h>
#include <EnemyEntity.h>

class Hivemind : public Entity
{
public:
	Hivemind(std::string name);


	void Update() override;
	void FireFromRandomEnemy();
	void EnemyDied(EnemyEntity* e);

	Vector<EnemyEntity*> Enemies;

protected:
	float m_outsideWindowCheckCooldown = 0.5f;
	float m_lastWindowCheck = 0;
	float m_direction = 1;
	float m_velocity = 100;
	float m_timeSinceFired = 0;
	float m_baseFireDelay = 1;
	float m_fireDelayVariance = 0.5f;
	float m_currentDelay = 1;
	int m_EnemiesWidth = 11;
	int m_EnemiesHeight = 5;
	int m_enemiesLeft = 0;
};

