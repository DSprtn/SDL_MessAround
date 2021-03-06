#pragma once
#include <Component.h>
#include <TransformComponent.h>

class SimpleMove : public Component
{
public:

	SimpleMove(Entity* owner, float speed);

	float Speed = 10;

	void Start() override {};
	void Update() override;

private:
	TransformComponent* Transform;
};

