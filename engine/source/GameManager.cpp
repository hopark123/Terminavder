#include <GameManager.hpp>
#include <iostream>

namespace Tvdr {
	GameManager *GameManager::_instance = NULL;
	GameManager *GameManager::Instance() {
		if (_instance == NULL)
			_instance = new GameManager();
		return _instance;
	}

	void GameManager::Release() {
		delete _instance;
		_instance = NULL;
	}

	GameManager::GameManager() {
		_quit = false;
		_graphics = Graphics::Instance();
		_curScene = nullptr;
		_nxtScene = nullptr;
		
		if (!Graphics::Initialized())
			_quit = true;
	}

	GameManager::~GameManager() {
		Graphics::Realase();
		_graphics = NULL;
		if (_curScene)
			delete _curScene;
		if (_nxtScene)
			delete _nxtScene;
	}

	bool GameManager::ChangeScene(Scene* scene){
		auto gm = Instance();
		if (gm->_nxtScene)
			return false;
		gm->_nxtScene = scene;
		return true;
	}

	int GameManager::Run(Scene *scene) {
		if (!scene)
			return 1;
		Instance()->_curScene = scene;
		Instance()->MainLoop();
		GameManager::Release();
		return 0;
	}

	void GameManager::MainLoop() {
		if (!_curScene)
			return;
	
		while (!_quit) {
			while(SDL_PollEvent(&_events)) {
				if (_events.type == SDL_QUIT) {
					_quit = true;
				}
				_graphics->Render();
			}

			_curScene->UpdateAll();
			if (_nxtScene){
				delete _curScene;
				_curScene = _nxtScene;
				_nxtScene = nullptr;
			}
		}
	}
}