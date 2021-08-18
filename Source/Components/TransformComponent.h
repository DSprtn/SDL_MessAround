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
		~TransformComponent();

		void OnRender() override;
		void Update() override;
		void LateUpdate() override;
		void Start() override;
		void SetPosition(float x, float y);

		float PositionX;
		float PositionY; 

		SDL_Rect Rect;

};

