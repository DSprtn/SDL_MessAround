#include "GameState.h"
#include "Entity.h"
#include <exception>
#include "Engine.h"

GameState* GameState::Instance = nullptr;
GameState::GameState() : Entity("GameState")
{
	if (Instance != nullptr) {
		throw std::exception("Duplicate gamestate class!");
	}
	Instance = this;
	scoreboard = Engine::Instance->CurrentWorld->CreateEntity<Scoreboard>();
}
