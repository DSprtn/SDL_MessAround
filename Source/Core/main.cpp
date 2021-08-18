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
#include <Core/PhysicsSystem.h>
#include <EnemyEntity.h>


int main(int argc, char* args[]) {
	
	Engine engine = Engine();
	PhysicsSystem physics = PhysicsSystem();

	InputManager* inputMgr = InputManager::GetInstance();

	engine.CurrentWorld->CreateEntity<PlayerEntity>("Player");

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 5; j++) {
			Entity* e = engine.CurrentWorld->CreateEntity<EnemyEntity>("Enemy");
			TransformComponent* t = e->GetComponent<TransformComponent>();
			t->SetPosition(96 + 64 + i * 70, 200 + j * 64);
		}
	}

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
		physics.Update();
		engine.LateUpdate();
		engine.OnRender();
	}
	return 0;
}