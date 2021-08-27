#pragma once
#include <SDL_ttf.h>
#include <unordered_map>
#include <string>

class GameAssets
{
public:
	GameAssets() = delete;

	static void LoadAll();
	static TTF_Font* GetFont(std::string name);

protected:
	static std::unordered_map<std::string,TTF_Font*> m_fonts;
};

