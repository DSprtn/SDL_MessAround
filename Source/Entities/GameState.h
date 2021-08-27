#pragma once
#include "Entity.h"
#include <Scoreboard.h>

class GameState : public Entity
{
public:
	GameState();
	static GameState* Instance;


	Scoreboard* scoreboard;

	
};

