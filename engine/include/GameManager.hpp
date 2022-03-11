#pragma once
#include <sys/time.h>
#include <Graphics.hpp>
#include <Scene.hpp>
#include <InputManager.hpp>
namespace Tvdr{
	class GameManager{
	private:
		static GameManager *_instance;
		InputManager *_inputManager;
		bool _quit;
		Graphics *_graphics;
		SDL_Event _events;
		Scene *_curScene;
		Scene *_nxtScene;

		timeval stTime;
		timeval curTime;
		timeval lastTime;

	public:
		static GameManager *Instance();
		static void Release();
		static bool ChangeScene(Scene *scene);
		static int Run(Scene *scene);
		static long long GetTime(void);
		static float GetDeltaTime(void);

	private:
		void MainLoop();

		GameManager();
		~GameManager();
	};
}