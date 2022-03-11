#pragma once
#include <sys/time.h>
#include <Graphics.hpp>
#include <Scene.hpp>
#include <InputManager.hpp>
namespace Tvdr{
	class GameManager {
	private :
		static GameManager *_instance;
		InputManager *_inputManager;
		bool _quit;
		Graphics *_graphics;
		SDL_Event _events;
		Scene* _curScene;
		Scene* _nxtScene;
		struct timeval	stTime;
		struct timeval	curTime;

	public:
		static GameManager* Instance();
		static void Release();
		static bool ChangeScene(Scene* scene);
		static int Run(Scene *scene);
	private :
		void MainLoop();

		GameManager();
		~GameManager();
	};
}