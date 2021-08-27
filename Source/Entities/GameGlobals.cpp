#include "GameGlobals.h"
#include "Entity.h"
#include <exception>
#include "Engine.h"

GameGlobals* GameGlobals::Instance = nullptr;
GameGlobals::GameGlobals() : Entity("GameGlobals")
{
	if (Instance != nullptr) {
		throw std::exception("Duplicate gamestate class!");
	}
	Instance = this;
	scoreboard = Engine::Instance->CurrentWorld->CreateEntity<Scoreboard>();
}
