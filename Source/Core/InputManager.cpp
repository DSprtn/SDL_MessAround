#include "InputManager.h"
#include <SDL_keyboard.h>


InputManager* InputManager::Instance = nullptr;

bool InputManager::KeyDown(SDL_Scancode scanCode)
{
	return m_keyboardStates[scanCode];
}

void InputManager::Update()
{
	m_keyboardStates = SDL_GetKeyboardState(NULL);
}

InputManager::InputManager()
{
	Instance = this;
	m_keyboardStates = nullptr;
}

InputManager::~InputManager()
{
	Instance = nullptr;
}

