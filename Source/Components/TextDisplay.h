#pragma once
#include "Component.h"
#include <string>
#include <SDL_pixels.h>
#include <RenderComponent.h>
#include <SDL_ttf.h>

class TextDisplay : public Component
{
public:
	TextDisplay(Entity* owner, std::string font, SDL_Colour colour);
	virtual ~TextDisplay();

	virtual void Start() {};
	
	void OnRender() override;
	void SetText(std::string text);

protected:
	SDL_Colour m_colour;
	TTF_Font* m_font;
	SDL_Texture* m_texture;
};

