#pragma once
#include "ECS\Component.h"
#include "ECS\Entity.h"

class Entity;
class Component;

class TransformComponent : public Component
{
	public:
		TransformComponent(Entity* owner);
		~TransformComponent();

		void OnRender() override;
		void Update() override;
		void Start() override;
		void SetPosition(float x, float y);

		float PositionX;
		float PositionY; 

};

