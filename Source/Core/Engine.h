#pragma once

#include <SDL.h>
#include <ECS\World.h>

class Engine
{
	public:
		Engine();
		~Engine();

		SDL_Window* Window;
		SDL_Renderer* Renderer;
		World* CurrentWorld;
		Uint32 FrameCount;
		bool IsRunning;

		void Init();
		void Shutdown();
		void Update();
		void OnRender();
		void HandleEvents();
};

