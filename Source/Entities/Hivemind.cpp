#include "Hivemind.h"
#include <Engine.h>
#include <EnemyEntity.h>
#include <random>
#include <Timer.h>
#include <MathHelper.h>

Hivemind::Hivemind(std::string name) : Entity(name)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			std::weak_ptr<EnemyEntity> e = Engine::Instance->CurrentWorld->CreateEntity<EnemyEntity>("Enemy");
			TransformComponent* t = e.lock()->GetComponent<TransformComponent>();
			t->SetPosition(96 + 64 + j * 70, 200 + i * 64);
			Enemies.Add(e);
		}
	}
}

void Hivemind::Update()
{
	Entity::Update();
	m_timeSinceFired += Timer::DeltaTime;

	if (m_timeSinceFired > m_currentDelay) {
		FireFromRandomEnemy();
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> dist(-m_fireDelayVariance, m_fireDelayVariance);
		m_timeSinceFired = 0;
		m_currentDelay = m_baseFireDelay + dist(mt);
	}
}

void Hivemind::FireFromRandomEnemy()
{
	std::vector<EnemyEntity*> possibleEnemies;

	for (int i = 10; i > -1; i--) {
		for (int j = 4; j > -1; j--) {
			auto e = Enemies[MathHelper::GetIndexFrom2DCoord(i, j, 11, 5)];
			if (!e.expired()) {
				possibleEnemies.push_back(e.lock().get());
				break;
			}
		}
	}

	if (possibleEnemies.size() > 0) {
		int fireIndex = 0;
		if (possibleEnemies.size() > 1) {
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<float> dist(0, possibleEnemies.size());
			fireIndex = (int) dist(mt) + .5f;
		}
		possibleEnemies[fireIndex]->FireWeapon();
	}
}
