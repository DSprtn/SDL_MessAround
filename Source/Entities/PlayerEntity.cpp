#include "PlayerEntity.h"
#include <TransformComponent.h>
#include <SimpleMove.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <ConstrainToWindow.h>

PlayerEntity::PlayerEntity(std::string Name) : Entity(Name)
{
	TransformComponent* t = AddComponent<TransformComponent>(this, 64, 64);
	t->SetPosition(640, 550);
	AddComponent<RenderComponent>(this, Engine::GetInstance()->Renderer, ".\\.\\Assets\\ship.png");
	AddComponent<SimpleKBMoveComponent>(this, 400);
	AddComponent<ConstrainToWindow>(this, Engine::GetInstance()->Window, t);
}

PlayerEntity::~PlayerEntity()
{
	MarkedForDeletion = true;
}
