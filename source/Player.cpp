#include "Player.hpp"

using namespace Tvdr;

Player::Player(): GameObject("resource/smalldots.bmp"){
	auto size = getTextureSize();
	SetPosition((Graphics::SCREEN_WIDTH - size.x) / 2, 500);
	_moveSpeed = 200.f;
	SetScale(2.f, 2.f);
}

Player::~Player(){

}

void Player::Update(){
	auto pos = GetPosition();

	auto dir = Vector(0, 0);
	if (InputManager::GetKey(SDL_SCANCODE_UP))
		dir.y -= 1;
	if (InputManager::GetKey(SDL_SCANCODE_DOWN))
		dir.y += 1;
	if (InputManager::GetKey(SDL_SCANCODE_LEFT))
		dir.x -= 1;
	if (InputManager::GetKey(SDL_SCANCODE_RIGHT))
		dir.x += 1;
	
	SetPosition(pos + dir.Norm() * _moveSpeed * GameManager::GetDeltaTime());
}
