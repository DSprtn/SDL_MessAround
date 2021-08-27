#pragma once
#include <Component.h>
#include <SDL_render.h>
#include <RenderComponent.h>

class Component;
class RenderComponent;

class AnimateByDistance : public Component
{
public:
	AnimateByDistance(Entity* owner, TransformComponent* t, Vector<std::string> Textures, float switchDistance);
	virtual ~AnimateByDistance() {};


	void Start() override {};
	void Update() override;

protected:
	Vector<SDL_Texture*> m_textures;
	TransformComponent* m_transform;
	RenderComponent* m_renderer;
	float m_switchDistance;
	float m_distanceTravelled;
	float m_lastPosX;
	int m_textureIndex = 0;


	void SwitchToNextTexture();
};

