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

void GameManager::Run() {
	while (!mQuit) {
		while(SDL_PollEvent(&mEvents) != 0) {
			if (mEvents.type == SDL_QUIT) {
				mQuit = true;
			}
			mGraphics->Render();
		}
		mInputManager->Update();
		if (mInputManager->KeyDown(SDL_SCANCODE_RIGHT))
			x++;
		if (mInputManager->KeyDown(SDL_SCANCODE_LEFT))
			x--;
		if (mInputManager->KeyDown(SDL_SCANCODE_UP))
			y++;
		if (mInputManager->KeyDown(SDL_SCANCODE_DOWN))
			y--;
		std::cout << "x["<< x  <<"]y[" << y <<"]\n";
	}
}