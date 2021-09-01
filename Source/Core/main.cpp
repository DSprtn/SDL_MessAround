#include <iostream>

#include <SDL.h>
#include "Engine.h"
#include <Component.h>
#include <Entity.h>
#include <RenderComponent.h>
#include <Timer.h>
#include <InputManager.h>
#include <SimpleMove.h>
#include <PlayerEntity.h>
#include <PhysicsSystem.h>
#include <EnemyEntity.h>
#include <Vector.h>
#include <Hivemind.h>
#include <MathHelper.h>
#include <chrono>
#include "GameAssets.h"
#include <GameGlobals.h>
#include <Shield.h>

int main(int argc, char* args[]) {
	Engine engine;
	GameAssets::LoadAll();
	GameGlobals gs;

	Entity* player = engine.CurrentWorld->CreateEntity<PlayerEntity>();
	player->Transform->SetPosition(640, 900);
	Entity* shield = engine.CurrentWorld->CreateEntity<Shield>();
	shield->Transform->SetPosition(100, 700);
	Entity* shield2 = engine.CurrentWorld->CreateEntity<Shield>();
	shield2->Transform->SetPosition(374, 700);
	Entity* shield3 = engine.CurrentWorld->CreateEntity<Shield>();
	shield3->Transform->SetPosition(648, 700);
	Entity* shield4 = engine.CurrentWorld->CreateEntity<Shield>();
	shield4->Transform->SetPosition(924, 700);
	//engine.CurrentWorld->CreateEntity<Hivemind>("Hivemind");

	const float timeScale = 1.0f;

	const int targetFramerate = 145;
	constexpr double minDeltaTime = 1.0f / targetFramerate;

	auto now = std::chrono::high_resolution_clock::now();
	auto last = std::chrono::high_resolution_clock::now();

	while (engine.IsRunning) {
		now = std::chrono::high_resolution_clock::now();
		const auto elapsed = std::chrono::high_resolution_clock::now() - last;
		const unsigned long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		Timer::DeltaTime = timeScale * ((double)microseconds / 1000000);

		last = now;
		engine.HandleEvents();
		engine.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}