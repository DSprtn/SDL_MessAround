#pragma once

#include <SDL.h>
#include <World.h>

class Engine
{
	public:
		Engine();
		~Engine();

		static Engine* Instance;

		SDL_Window* Window;
		SDL_Renderer* Renderer;
		World* CurrentWorld;
		Uint32 FrameCount;
		bool IsRunning;

		void Init();
		void Shutdown();
		void Update();
		void LateUpdate();
		void OnRender();
		void HandleEvents();
};

