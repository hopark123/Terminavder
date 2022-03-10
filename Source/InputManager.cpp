#include "InputManager.hpp"

InputManager *InputManager::sInstance = NULL;

InputManager *InputManager::Instatnce() {
	if (sInstance == NULL)
		sInstance = new InputManager();
	return sInstance;
}

void InputManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

bool InputManager::KeyDown(SDL_Scancode scanCode) {
		return mKeyboradstates[scanCode];
}

void InputManager::Update() {
	mKeyboradstates = SDL_GetKeyboardState(NULL);
}