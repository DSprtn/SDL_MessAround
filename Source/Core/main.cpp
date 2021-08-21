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

int main(int argc, char* args[]) {
	Engine engine;

	engine.CurrentWorld->CreateEntity<PlayerEntity>("Player");
	engine.CurrentWorld->CreateEntity<Hivemind>("Hivemind");

	float timeScale = 1.0f;

	auto now = std::chrono::high_resolution_clock::now();
	auto last = std::chrono::high_resolution_clock::now();

	while (engine.IsRunning) {
		last = now;
		now = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::high_resolution_clock::now() - last;
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

		Timer::DeltaTime = ((long double)microseconds / 1000000);

		// We should limit framerate to prevent stuttering at very low frametimes, but instead we print the current frametime for diagnostics (and to slow the game down) : ^)
		std::cout << Timer::DeltaTime << std::endl;
		engine.HandleEvents();
		engine.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}