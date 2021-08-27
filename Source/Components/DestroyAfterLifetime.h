#pragma once
#include <Component.h>


class DestroyAfterLifetime : public Component
{
public:
	DestroyAfterLifetime(Entity* owner, float lifetime);

	void Start() override {};
	void Update() override;

protected:
	float m_Lifetime;
	float m_elapsed;
};

