#pragma once
#include <ECS\Component.h>
#include <TransformComponent.h>

class SimpleKBMoveComponent : public Component
{
	public:

		SimpleKBMoveComponent(Entity* owner, float speed);
		virtual ~SimpleKBMoveComponent();


		float Speed = 10;

		virtual void Update() override;
		virtual void Start() override;
		virtual void OnRender() override;

	private:
		TransformComponent* m_transform;
};

