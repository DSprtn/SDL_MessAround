#include "TextureManager.h"


std::unordered_map<std::string, SDL_Texture*> TextureManager::TextureLookup = std::unordered_map<std::string, SDL_Texture*>();

SDL_Texture* TextureManager::GetTexture(std::string Path, SDL_Renderer* Renderer)
{
	if (TextureLookup[Path] != nullptr) {
		return TextureLookup[Path];
	}
	return LoadTexture(Path, Renderer);
}

SDL_Texture* TextureManager::LoadTexture(std::string Path, SDL_Renderer* Renderer)
{
	const char* c = Path.c_str();
	SDL_Surface* tmpSurf = IMG_Load(c);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Renderer, tmpSurf);
	TextureLookup[c] = tex;
	SDL_FreeSurface(tmpSurf);
	return tex;
}
