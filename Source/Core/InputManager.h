#pragma once
#include <SDL_scancode.h>
class InputManager
{
public:
	static InputManager* Instance;

	bool KeyDown(SDL_Scancode scanCode);
	void Update();

	InputManager();
	~InputManager();

private:
	const Uint8* m_keyboardStates;
};

