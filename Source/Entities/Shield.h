#pragma once
#include "Entity.h"
#include "RenderComponent.h"
#include <SDL_surface.h>
#include <SDL_image.h>

class Shield : public Entity
{
public:
	Shield();
	virtual ~Shield() {};


	void OnHit(float posX, float posY, float radius);
	void OnCollide(Entity* entity) override;


	bool CollideRectPerPixel(Entity* other, float &outX, float &outY);

protected:
	RenderComponent* m_renderer;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;
};

