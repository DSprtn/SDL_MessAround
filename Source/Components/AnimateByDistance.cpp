#include "AnimateByDistance.h"
#include "TextureManager.h"
#include "Engine.h"



AnimateByDistance::AnimateByDistance(Entity* owner, TransformComponent* t, Vector<std::string> textures, float switchDistance) : Component(owner)
{
	m_transform = t;
	for (int i = 0; i < textures.Count; i++) {
		m_textures.Add(TextureManager::GetTexture(textures[i], Engine::Instance->Renderer));
	}
	m_switchDistance = switchDistance;
	m_renderer = m_Owner->GetComponent<RenderComponent>();
	m_lastPosX = t->PositionX;
	m_distanceTravelled = 0;
}

void AnimateByDistance::SwitchToNextTexture()
{
	m_textureIndex++;
	if (m_textureIndex == m_textures.Count) {
		m_textureIndex = 0;
	}
	m_renderer->SetTexture(m_textures[m_textureIndex]);
}

void AnimateByDistance::Update() {
	m_distanceTravelled += std::abs(m_transform->PositionX - m_lastPosX);
	m_lastPosX = m_transform->PositionX;
	if (m_distanceTravelled > m_switchDistance) {
		SwitchToNextTexture();
		m_distanceTravelled = 0;
	}
}