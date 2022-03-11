#ifndef _INPUTMANAGER_
# define _INPUTMANAGER_
# include <SDL2/SDL.h>
# include <iostream>

namespace Tvdr{
	struct s_KeyState {
		Uint8 nowState;
		Uint8 lastState;
		uint lastUptime;
		bool isDouble;
	};

	class InputManager {
	private:
		static InputManager *_instance;
		s_KeyState _keyState[SDL_NUM_SCANCODES];
		uint _currentTime;
		uint _updateInterval;


	public :
		static InputManager *Instance();
		static void Release();

		static bool GetKey(SDL_Scancode scanCode);
		static bool KeyDown(SDL_Scancode scanCode);
		static bool KeyUP(SDL_Scancode scanCode);
		static bool DoubleKeyDown(SDL_Scancode scanCode);
		static bool MulitKeyDown(SDL_Scancode scanCode1, SDL_Scancode scanCode2);

		void Update(uint CurrentTime);
	private :
		static s_KeyState const &GetKeyState(SDL_Scancode scanCode);
		InputManager();
		~InputManager();
	};
}
#endif