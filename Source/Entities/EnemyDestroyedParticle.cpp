#include "EnemyDestroyedParticle.h"
#include <TransformComponent.h>
#include <RenderComponent.h>
#include <Engine.h>
#include <DestroyAfterLifetime.h>

EnemyDestroyedParticle::EnemyDestroyedParticle(std::string name, float posX, float posY, int sizeX, int sizeY) : Entity(name, sizeX, sizeY)
{
	AddComponent<RenderComponent>(Engine::Instance->Renderer, ".\\.\\Assets\\explosion.png");
	Transform->SetPosition(posX,posY);
	AddComponent<DestroyAfterLifetime>(0.3f);
}
