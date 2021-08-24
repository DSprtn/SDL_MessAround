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

Engine* Engine::Instance = nullptr;

void Engine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		CurrentWorld = new World();
		Window = SDL_CreateWindow("SpayseInvaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 1024, SDL_WINDOW_SHOWN);

		Renderer = SDL_CreateRenderer(Window, -1, 0);

		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		IsRunning = true;
		Instance = this;
	}
}

void Engine::Shutdown()
{
	delete CurrentWorld;
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	Instance = nullptr;
	std::cout << "Sayonara!" << std::endl;
}

void Engine::Update()
{
	if (CurrentWorld != nullptr) {
		CurrentWorld->Update();
	}
	m_physics.Update();
}

void Engine::LateUpdate()
{
	if (CurrentWorld != nullptr) {
		CurrentWorld->LateUpdate();
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

	m_inputManager.Update();
}


