#include "HelloWorld.hpp"
#include <iostream>

HelloWorld::HelloWorld(){
	Start();
}

void HelloWorld::Start(){
	AddChild(new Tvdr::GameObject("resource/dots.bmp"));
}

void HelloWorld::Update(){
	//* input test
	if (Tvdr::InputManager::KeyDown(SDL_SCANCODE_DOWN))
		std::cout << "down press" << std::endl;
	// if (Tvdr::InputManager::GetKey(SDL_SCANCODE_DOWN))
		// std::cout << "down pressing" << std::endl;
	if (Tvdr::InputManager::KeyUP(SDL_SCANCODE_DOWN))
		std::cout << "down up" << std::endl;
	if (Tvdr::InputManager::DoubleKeyDown(SDL_SCANCODE_DOWN))
		std::cout << "Double" << std::endl;
	if (Tvdr::InputManager::MulitKeyDown(SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT))
		std::cout << "Mulit" << std::endl;
	// */

	// std::cout <<"time:"<< Tvdr::GameManager::Instance()->GetDeltaTime() << std::endl;
}


