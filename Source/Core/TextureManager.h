#pragma once
#include <unordered_map>
#include <SDL_image.h>
class TextureManager
{
public:
	static std::unordered_map<std::string, SDL_Texture*> TextureLookup;
	static SDL_Texture* GetTexture(std::string Path, SDL_Renderer* Renderer);
private:
	static SDL_Texture* LoadTexture(std::string Path, SDL_Renderer* Renderer);

};

