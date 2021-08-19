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

int main(int argc, char* args[]) {
	
	Engine engine;

	engine.CurrentWorld->CreateEntity<PlayerEntity>("Player");
	engine.CurrentWorld->CreateEntity<Hivemind>("Hivemind");


	Uint32 now = SDL_GetTicks();
	Uint32 last = 0;

	float timeScale = 1;

	while (engine.IsRunning) {
		last = now;
		now = SDL_GetTicks() * timeScale;
		Timer::DeltaTime = ((float)(now - last) / 1000);
		Timer::TicksPassed = now;

		engine.HandleEvents();
		engine.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}