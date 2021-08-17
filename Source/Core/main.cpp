#include <iostream>

#include <SDL.h>
#include "Engine.h"
#include <ECS/Component.h>
#include <ECS/Entity.h>
#include <RenderComponent.h>
#include <Util/Timer.h>
#include <Core/InputManager.h>
#include <SimpleMove.h>
#include <Entities\PlayerEntity.h>



int main(int argc, char* args[]) {
	
	Engine engine = Engine();

	InputManager* inputMgr = InputManager::GetInstance();

	Entity* Player = engine.CurrentWorld->CreateEntity<PlayerEntity>("Player");

	Uint32 now = SDL_GetTicks();
	Uint32 last = 0;
	
	while (engine.IsRunning) {
		last = now;
		now = SDL_GetTicks();
		Timer::DeltaTime = ((float)(now - last) / 1000);
		Timer::TicksPassed = now;

		engine.HandleEvents();
		inputMgr->Update();
		engine.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}