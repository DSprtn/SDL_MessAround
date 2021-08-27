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

int main(int argc, char* args[]) {
	Engine engine;
	GameAssets::LoadAll();
	GameGlobals gs;

	engine.CurrentWorld->CreateEntity<PlayerEntity>("Player");
	engine.CurrentWorld->CreateEntity<Hivemind>("Hivemind");

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

		// Rudimentary framerate cap
		if (Timer::DeltaTime < minDeltaTime) {
			continue;
		}

		last = now;
		engine.HandleEvents();
		engine.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}