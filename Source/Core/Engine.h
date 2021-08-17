#pragma once

#include <SDL.h>
#include <ECS\World.h>

class Engine
{
	private:
		static Engine* Instance;

	public:
		Engine();
		~Engine();

		static Engine* GetInstance();

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

