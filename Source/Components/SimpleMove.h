#pragma once
#include <ECS\Component.h>
#include <TransformComponent.h>

class SimpleKBMoveComponent : public Component
{
	public:

		SimpleKBMoveComponent(Entity* owner, float speed);
		virtual ~SimpleKBMoveComponent();


		float Speed = 10;

		void Update() override;
		void LateUpdate() override;
		void Start() override;
		void OnRender() override;

	private:
		TransformComponent* m_transform;
};

