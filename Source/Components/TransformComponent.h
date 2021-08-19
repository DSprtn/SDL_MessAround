#pragma once
#include "Component.h"
#include "Entity.h"
#include <SDL.h>

class Entity;
class Component;

class TransformComponent : public Component
{
	public:
		TransformComponent(Entity* owner, int sizeX, int sizeY);

		void Update() override {};
		void SetPosition(float x, float y);
		bool OutsideWindow();

		float PositionX;
		float PositionY; 

		SDL_Rect Rect;

};

