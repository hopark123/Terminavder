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

InputManager::InputManager() : _currentTime(0), _updateInterval(100) {
	memset(&_keyState, 0, sizeof(s_KeyState));
	const Uint8 *nextState = SDL_GetKeyboardState(NULL);
	for (int i = 0 ; i < SDL_NUM_SCANCODES; ++i)
		_keyState[i].nowState = nextState[i];
}

InputManager::~InputManager() {
}

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return(GetKeyState(scanCode).nowState && !GetKeyState(scanCode).lastState);
}

bool InputManager::GetKey(SDL_Scancode scanCode) {
	return(GetKeyState(scanCode).nowState);
}

bool InputManager::KeyUP(SDL_Scancode scanCode) {
	return(!GetKeyState(scanCode).nowState && GetKeyState(scanCode).lastState);
}

bool InputManager::DoubleKeyDown(SDL_Scancode scanCode) {

	if (KeyDown(scanCode) && GetKeyState(scanCode).lastUptime && sInstance->_currentTime - GetKeyState(scanCode).lastUptime < sInstance->_updateInterval) {
		sInstance->_keyState[scanCode].isDouble = true;
		return true;
	}
	return false;
}

bool InputManager::MulitKeyDown(SDL_Scancode scanCode1 , SDL_Scancode scanCode2) {
	return((GetKeyState(scanCode1).nowState && KeyDown(scanCode2))
			|| GetKeyState(scanCode2).nowState && KeyDown(scanCode1));
}

void InputManager::Update(uint currentTime) {
	_currentTime = currentTime;
	const Uint8 *nextState = SDL_GetKeyboardState(NULL);
	for (int i = 0 ; i < SDL_NUM_SCANCODES; ++i) {
		_keyState[i].lastState = _keyState[i].nowState;
		_keyState[i].nowState = nextState[i];
		if (_keyState[i].lastState && !nextState[i]) {
			_keyState[i].lastUptime = _keyState[i].isDouble ? 0 : currentTime;
			_keyState[i].isDouble = false;
		}
	}
}

s_KeyState const &InputManager::GetKeyState(SDL_Scancode scanCode) {
	return sInstance->_keyState[scanCode];
}