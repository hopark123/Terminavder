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
		_inputManager = InputManager::Instance();
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
		gettimeofday(&Instance()->stTime, NULL);
		Instance()->_curScene = scene;
		Instance()->MainLoop();
		GameManager::Release();
		return 0;
	}

	void GameManager::MainLoop() {
		if (!_curScene)
			return;
	
		lastTime = stTime;
		while (!_quit) {
			gettimeofday(&curTime, NULL);
			_graphics->ClearRenderer();
			while(SDL_PollEvent(&_events)) {
				if (_events.type == SDL_QUIT) {
					_quit = true;
				}
			}
			_inputManager->Update((curTime.tv_sec * (long)1000) + (curTime.tv_usec / 1000));
			_curScene->UpdateAll();
			_graphics->Render();
			
			for (auto it = _releaseObject.begin(); it != _releaseObject.end();){
				auto obj = (*it);
				it = _releaseObject.erase(it);
				delete obj;
			}

			if (_nxtScene){
				delete _curScene;
				_curScene = _nxtScene;
				_nxtScene = nullptr;
			}
			lastTime = curTime;
		}
	}

	long long GameManager::GetTime() {
		return ((Instance()->curTime.tv_sec * (long)1000) + (Instance()->curTime.tv_usec / 1000) - 
				 ((Instance()->stTime.tv_sec * (long)1000) + (Instance()->stTime.tv_usec / 1000)));
	}

	float GameManager::GetDeltaTime() {
		long long deltaTime = ((Instance()->curTime.tv_sec * (long)1000) + (Instance()->curTime.tv_usec / 1000) - 
				 ((Instance()->lastTime.tv_sec * (long)1000) + (Instance()->lastTime.tv_usec / 1000)));
		return deltaTime / 1000.f;
	}
}