#include "Graphics.hpp"
#include <iostream>
Graphics *Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance() {
	if (sInstance == NULL)
		sInstance = new Graphics();
	return sInstance;
}

void Graphics::Realase() {
	delete sInstance;
	sInstance = NULL;

	sInitialized = false;
}

bool Graphics::Initialized() {
	return sInitialized;
}

Graphics::Graphics() {
	_renderer = NULL;
	sInitialized = Init();
}

Graphics::~Graphics() {
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

bool Graphics::Init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL InitialIzetion Error:%s\n", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (mWindow == NULL) {
		printf("window creation ERROR : %s\n", SDL_GetError());
		return false;
	}

	_renderer = SDL_CreateRenderer(mWindow, -1, 0);
	if (mWindow == NULL) {
		printf("renderer creation ERROR : %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void Graphics::ClearRenderer(){
	SDL_RenderClear(_renderer);
}

void Graphics::Render() {
	SDL_RenderPresent(_renderer);
	SDL_UpdateWindowSurface(mWindow);
}

SDL_Texture* Graphics::GetTextureFromSurface(SDL_Surface* surface){
	return SDL_CreateTextureFromSurface(Instance()->_renderer, surface);
}

void Graphics::RenderTexture(SDL_Texture* texture, SDL_Rect* drect, float rotate){
	auto renderer = Instance()->_renderer;
	int flip = SDL_FLIP_NONE;
	if (drect->h < 0){
		flip |= SDL_FLIP_VERTICAL;
		drect->h = -drect->h;
	}
	if (drect->w < 0){
		flip |= SDL_FLIP_HORIZONTAL;
		drect->w = -drect->w;
	}
	SDL_RenderCopyEx(renderer, texture, NULL, drect, rotate, NULL, (SDL_RendererFlip)flip);
}