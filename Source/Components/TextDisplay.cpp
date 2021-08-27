#include "TextDisplay.h"
#include <SDL_surface.h>
#include <SDL_ttf.h>
#include "GameAssets.h"
#include "Engine.h"
#include <exception>

TextDisplay::TextDisplay(Entity* owner, std::string font, SDL_Colour colour) : Component(owner)
{
	m_colour = colour;
	m_font = GameAssets::GetFont(font);
	m_texture = nullptr;
}

TextDisplay::~TextDisplay()
{
	if (m_texture != nullptr) {
		SDL_DestroyTexture(m_texture);
	}
}

void TextDisplay::OnRender()
{
	if (m_texture != nullptr) {
		SDL_Rect* rect = &m_Owner->Transform->Rect;
		rect->x = m_Owner->Transform->PositionX - rect->w / 2;
		rect->y = m_Owner->Transform->PositionY - rect->h / 2;
		SDL_RenderCopy(Engine::Instance->Renderer, m_texture, NULL, &m_Owner->Transform->Rect);
	}
}

void TextDisplay::SetText(std::string text)
{
	if (m_font == nullptr) {
		throw std::exception("No font provided!");
	}

	SDL_DestroyTexture(m_texture);
	SDL_Surface* surf = TTF_RenderText_Blended(m_font, text.c_str(), m_colour);
	m_texture = SDL_CreateTextureFromSurface(Engine::Instance->Renderer, surf);
	SDL_FreeSurface(surf);
}
