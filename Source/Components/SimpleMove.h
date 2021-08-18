#pragma once
#include <Component.h>
#include <TransformComponent.h>

class SimpleMove : public Component
{
	public:

		SimpleMove(Entity* owner, float speed);
		virtual ~SimpleMove();


		float Speed = 10;

		void Update() override;
		void LateUpdate() override;
		void Start() override;
		void OnRender() override;

	private:
		TransformComponent* m_transform;
};

