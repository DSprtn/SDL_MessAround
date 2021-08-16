#include "InputManager.h"
#include <SDL_keyboard.h>


InputManager* InputManager::Instance = nullptr;

InputManager* InputManager::GetInstance() {
	if (Instance == nullptr) {
		Instance = new InputManager();
	}
	return Instance;
}

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
	m_keyboardStates = nullptr;
}

InputManager::~InputManager()
{
}

