#include <iostream>

#include <SDL.h>
#include "Engine.h"
#include <ECS/Component.h>
#include <ECS/Entity.h>
#include <RenderComponent.h>
#include <Util/Timer.h>
#include <Core/InputManager.h>
#include <SimpleMove.h>



int main(int argc, char* args[]) {
	
	Engine engine = Engine();

	InputManager* inputMgr = InputManager::GetInstance();

	Entity* Player = engine.CurrentWorld->CreateEntity<Entity>("Player");

	Player->AddComponent<RenderComponent>(Player, engine.Renderer, ".\\.\\Assets\\ship.png", 64, 64);
	Player->AddComponent<SimpleKBMoveComponent>(Player, 400);
	Player->GetComponent<TransformComponent>()->SetPosition(640, 550);


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
		engine.OnRender();
	}
	return 0;
}