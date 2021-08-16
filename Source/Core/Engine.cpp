#include "Engine.h"
#include <iostream>
#include <SDL_image.h>
#include <TextureManager.h>


Engine::Engine() {
	IsRunning = false;
	FrameCount = 0;
	Init();
}

Engine::~Engine() {
	Shutdown();
}

void Engine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		CurrentWorld = new World();
		Window = SDL_CreateWindow("SpayseInvaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

		Renderer = SDL_CreateRenderer(Window, -1, 0);

		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		IsRunning = true;
	}
}

void Engine::Shutdown()
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	std::cout << "Sayonara!" << std::endl;
}

void Engine::Update()
{
	if (CurrentWorld != nullptr) {
		CurrentWorld->Update();
	}
}

void Engine::OnRender()
{
	SDL_RenderClear(Renderer);
	if (CurrentWorld != nullptr) {
		CurrentWorld->OnRender();
	}

	SDL_RenderPresent(Renderer);
}

void Engine::HandleEvents()
{
	SDL_Event sdlEvent;


	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			IsRunning = false;
			break;
		default:
			break;
		}
	}

}


