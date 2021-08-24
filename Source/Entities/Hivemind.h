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
	void FireFromRandomEnemy() const;
	bool CollideWithWindowBounds();
	void CalculateEnemySpeed();
	void UpdateAllEnemyTransforms();
	void CalculateFireFromTargets();

	Vector<EnemyEntity*> m_possibleFireFromTargets{8};

	float m_direction = 1;
	float m_velocity = 15;
	float m_timeSinceFired = 0;
	const float m_baseFireDelay = 1;
	const float m_fireDelayVariance = 0.5f;
	float m_currentFireDelay = 1;
	int m_enemiesLeft = 0;
};

