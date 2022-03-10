#ifndef _GAMEMANAGER_
# define _GAMEMANAGER_

# include "Graphics.hpp"
# include "InputManager.hpp"

class GameManager {

private :
	static GameManager *sInstance;
	bool mQuit;
	Graphics *mGraphics;
	SDL_Event mEvents;
	InputManager *mInputManager;

public:
	static GameManager* Instance();
	static void Release();

	void Run();
	int x = 0, y = 0;
private :
	GameManager();
	~GameManager();
};

#endif