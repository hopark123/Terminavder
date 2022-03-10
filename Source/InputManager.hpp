#ifndef _INPUTMANAGER_
# define _INPUTMANAGER_
# include <SDL2/SDL.h>
# include <iostream>
class InputManager {
private:
	static InputManager *sInstance;
	const Uint8 *mKeyboradstates;

public :
	static InputManager *Instatnce();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);

	void Update();
private :
	InputManager();
	~InputManager();
};

#endif