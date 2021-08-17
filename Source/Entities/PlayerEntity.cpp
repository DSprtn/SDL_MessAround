#include "PlayerEntity.h"
#include <TransformComponent.h>
#include <SimpleMove.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <ConstrainToWindow.h>
#include <Collider.h>

PlayerEntity::PlayerEntity(std::string Name) : Entity(Name)
{
	TransformComponent* t = AddComponent<TransformComponent>(this, 64, 64);
	t->SetPosition(640, 550);
	AddComponent<RenderComponent>(this, Engine::Instance->Renderer, ".\\.\\Assets\\ship.png");
	AddComponent<SimpleKBMoveComponent>(this, 400);
	AddComponent<ConstrainToWindow>(this, Engine::Instance->Window, t);
	AddComponent<Collider>(this, t);
}

PlayerEntity::~PlayerEntity()
{
	MarkedForDeletion = true;
}
