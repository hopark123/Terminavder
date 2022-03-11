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

InputManager::InputManager() : _currentTime(0), _updateInterval(1000) {
	memset(&_keyState, 0, sizeof(s_KeyState));
	_keyState.nowState = SDL_GetKeyboardState(NULL);
}

InputManager::~InputManager() {
}

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return(GetKeyState().nowState[scanCode] && GetKeyState().lastState[scanCode]);
}

bool InputManager::KeyUP(SDL_Scancode scanCode) {
	return(!GetKeyState().nowState[scanCode]);
}

bool InputManager::DoubleKeyDown(SDL_Scancode scanCode) {
	// std::cout << "@@@@current"<< sInstance->_currentTime << "get" << GetKeyState().lastUptime[scanCode] << " = [" << sInstance->_currentTime - GetKeyState().lastUptime[scanCode] << std::endl;
	if (KeyDown(scanCode) && sInstance->_currentTime - GetKeyState().lastUptime[scanCode] < sInstance->_updateInterval) {
		sInstance->_keyState.isDouble[scanCode] = true;
		return true;
	}
	return false;
}

bool InputManager::MulitKeyDown(SDL_Scancode scanCode1 , SDL_Scancode scanCode2) {
	return(GetKeyState().nowState[scanCode1] && GetKeyState().nowState[scanCode2]);
}

void InputManager::Update(uint currentTime) {
	_currentTime = currentTime;
	const Uint8 *nextState = SDL_GetKeyboardState(NULL);
	for (int i = 0 ; i < SDL_NUM_SCANCODES; i++) {
		_keyState.lastState[i] = _keyState.nowState[i];
		if (_keyState.lastState[i] && !nextState[i]) {
			_keyState.lastUptime[i] = _keyState.isDouble[i] ? 0 : _currentTime;
			_keyState.isDouble[i] = false;
			std::cout << "last" <<_keyState.lastUptime[i] << std::endl;
		}
	}
	_keyState.nowState = nextState;
}

s_KeyState const &InputManager::GetKeyState(void) {
	return sInstance->_keyState;
}