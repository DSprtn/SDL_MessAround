#include "GameAssets.h"
#include <iostream>

std::unordered_map<std::string, TTF_Font*> GameAssets::m_fonts = std::unordered_map<std::string, TTF_Font*>();

void GameAssets::LoadAll()
{
	m_fonts["space_invaders.ttf"] = TTF_OpenFont("Assets/space_invaders.ttf", 16);
}

TTF_Font* GameAssets::GetFont(std::string name)
{
	if (m_fonts.find(name) == m_fonts.end()) {
		return nullptr;
	}
	return m_fonts[name];
}
