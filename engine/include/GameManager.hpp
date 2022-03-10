#pragma once
#include <Graphics.hpp>
#include <Scene.hpp>

namespace Tvdr{
	class GameManager {
	private :
		static GameManager *_instance;
		bool _quit;
		Graphics *_graphics;
		SDL_Event _events;
		Scene* _curScene;
		Scene* _nxtScene;

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