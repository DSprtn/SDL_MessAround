#pragma once
#include "Entity.h"
#include <Scoreboard.h>

class GameGlobals : public Entity
{
public:
	GameGlobals();
	static GameGlobals* Instance;


	Scoreboard* scoreboard;

	
};

