#pragma once
#include <SDL_scancode.h>
class InputManager
{
private:
	
	static InputManager* Instance;
	const Uint8* m_keyboardStates;

public:

	static InputManager* GetInstance();

	bool KeyDown(SDL_Scancode scanCode);
	void Update();

	InputManager();
	~InputManager();
};

