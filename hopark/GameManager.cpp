#include "GameManager.hpp"

GameManager *GameManager::sInstance = NULL;
GameManager *GameManager::Instance() {
	if (sInstance == NULL)
		sInstance = new GameManager();
	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

GameManager::GameManager() {
	mQuit = false;
	mGraphics = Graphics::Instance();
	
	if (!Graphics::Initialized())
		mQuit = true;
	mInputManager = InputManager::Instatnce();
}

GameManager::~GameManager() {
	Graphics::Realase();
	mGraphics = NULL;
	InputManager::Release();
	mInputManager = NULL;
}
# include <sys/time.h>
# include <unistd.h>

void GameManager::Run() {
	while (!mQuit) {
		while(SDL_PollEvent(&mEvents) != 0) {
			if (mEvents.type == SDL_QUIT) {
				mQuit = true;
			}
			mGraphics->Render();
		}
		static struct timeval	tv;

		gettimeofday(&tv, NULL);
		// std::cout <<  (tv.tv_sec * (long)1000) + (tv.tv_usec / 1000) << std::endl;
		mInputManager->Update((tv.tv_sec * (long)1000) + (tv.tv_usec / 1000));
		if (mInputManager->KeyDown(SDL_SCANCODE_DOWN))
			std::cout << "down press" << std::endl;
			// if (mInputManager->GetKey(SDL_SCANCODE_DOWN))
			// std::cout << "down pressing" << std::endl;
		if (mInputManager->KeyUP(SDL_SCANCODE_DOWN))
			std::cout << "down up" << std::endl;
		if (mInputManager->DoubleKeyDown(SDL_SCANCODE_DOWN))
			std::cout << "Double" << std::endl;
		if (mInputManager->MulitKeyDown(SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT))
			std::cout << "Mulit" << std::endl;
		// usleep(100000);
	}
}