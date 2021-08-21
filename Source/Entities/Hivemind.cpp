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
			auto e = Engine::Instance->CurrentWorld->CreateEntity<EnemyEntity>("Enemy", this);
			TransformComponent* t = e->GetComponent<TransformComponent>();
			t->SetPosition(150 + j * 70, 100 + i * 64);
			Enemies.Add(e);
			m_enemiesLeft++;
		}
	}
	CalculateFireFromTargets();
	CalculateEnemySpeed();
}

void Hivemind::Update()
{
	Entity::Update();

	if (m_enemiesLeft == 0) {
		Delete();
		Engine::Instance->CurrentWorld->CreateEntity<Hivemind>("HiveMind");
		return;
	}

	UpdateAllEnemyTransforms();
	FireFromValidEnemyAtRandomInterval();
}

void Hivemind::CalculateEnemySpeed()
{
	if (m_enemiesLeft > 0) {
		m_velocity = 15 / ((float)m_enemiesLeft / Enemies.Count);
	}
}

void Hivemind::UpdateAllEnemyTransforms()
{
	bool wasOutsideWindow = CollideWithWindowBounds();
	for (int i = 0; i < Enemies.Count; i++) {
		if (Enemies[i] != nullptr) {
			TransformComponent* t = Enemies[i]->Transform;
			t->SetPosition(t->PositionX + m_velocity * m_direction * Timer::DeltaTime, t->PositionY + 25 * wasOutsideWindow);
		}
	}
}

void Hivemind::FireFromValidEnemyAtRandomInterval()
{
	m_timeSinceFired += Timer::DeltaTime;
	if (m_timeSinceFired > m_currentFireDelay) {
		FireFromRandomEnemy();
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> dist(-m_fireDelayVariance, m_fireDelayVariance);
		m_timeSinceFired = 0;
		m_currentFireDelay = m_baseFireDelay + dist(mt);
	}
}

bool Hivemind::CollideWithWindowBounds()
{
	float minX = std::numeric_limits<float>::max();
	float maxX = std::numeric_limits<float>::min();

	float rectWidth = 1;

	int windowSizeX = 0;
	int windowSizeY = 0;
	SDL_GetWindowSize(Engine::Instance->Window, &windowSizeX, &windowSizeY);

	for (int i = 0; i < Enemies.Count; i++) {
		if (Enemies[i] != nullptr) {
			TransformComponent* t = Enemies[i]->Transform;
			rectWidth = t->Rect.w;
			float posX = t->PositionX;
			if (minX > posX) {
				minX = posX;
			}
			if (maxX < posX) {
				maxX = posX;
			}
		}
	}

	if (minX - rectWidth / 2 < 0 && m_direction == -1) {
		m_direction = 1;
		return true;
	}
	else if (maxX + rectWidth / 2 > windowSizeX && m_direction == 1) {
		m_direction = -1;
		return true;
	}
	return false;
}

void Hivemind::FireFromRandomEnemy()
{
	if (m_possibleFireFromTargets.Count > 0) {
		int fireIndex = 0;
		if (m_possibleFireFromTargets.Count > 1) {
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<float> dist(0, m_possibleFireFromTargets.Count);
			fireIndex = (int) dist(mt) + .5f;
		}
		m_possibleFireFromTargets[fireIndex]->FireWeapon();
	}
}

void Hivemind::CalculateFireFromTargets()
{
	m_possibleFireFromTargets.Clear();
	for (int i = 10; i > -1; i--) {
		for (int j = 4; j > -1; j--) {
			auto e = Enemies[MathHelper::GetIndexFrom2DCoord(i, j, 11, 5)];
			if (e != nullptr) {
				m_possibleFireFromTargets.Add(e);
				break;
			}
		}
	}
}

void Hivemind::EnemyDied(EnemyEntity* e)
{
	m_enemiesLeft--;
	Enemies[Enemies.GetIndex(e)] = nullptr;
	CalculateFireFromTargets();
	CalculateEnemySpeed();
}
