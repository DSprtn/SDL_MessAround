#pragma once
#include <Component.h>


class DestroyAfterLifetime : public Component
{
public:
	DestroyAfterLifetime(Entity* owner, float lifetime);
	void Update() override;

protected:
	float m_Lifetime;
	float m_elapsed;
};

