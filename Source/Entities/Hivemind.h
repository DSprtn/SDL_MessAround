#pragma once
#include <Entity.h>
#include <EnemyEntity.h>

class Hivemind : public Entity
{
public:
	Hivemind(std::string name);

	void Update() override;
	void EnemyDied(EnemyEntity* e);

	Vector<EnemyEntity*> Enemies{ 64 };

private:
	void FireFromValidEnemyAtRandomInterval();
	void FireFromRandomEnemy();
	bool CollideWithWindowBounds();
	void CalculateEnemySpeed();
	void UpdateAllEnemyTransforms();
	void CalculateFireFromTargets();

	Vector<EnemyEntity*> m_possibleFireTargets{8};

	float m_direction = 1;
	float m_velocity = 15;
	float m_timeSinceFired = 0;
	float m_baseFireDelay = 1;
	float m_fireDelayVariance = 0.5f;
	float m_currentFireDelay = 1;
	int m_enemiesLeft = 0;
};

