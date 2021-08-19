#include "DestroyAfterLifetime.h"
#include <Timer.h>

DestroyAfterLifetime::DestroyAfterLifetime(Entity* owner, float lifetime) : Component(owner)
{
	m_Lifetime = lifetime;
	m_elapsed = 0;
}

void DestroyAfterLifetime::Update()
{
	m_elapsed += Timer::DeltaTime;
	if (m_elapsed > m_Lifetime) {
		m_Owner->Delete();
	}
}
