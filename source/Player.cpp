#include "Player.hpp"
#include "Player_Attack.hpp"

using namespace Tvdr;

Player::Player(): GameObject("resource/smalldots.bmp"){
	auto size = GetPrintSize();
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
	if (InputManager::KeyDown(SDL_SCANCODE_SPACE)){
		auto size = GetPrintSize();
		AddChild(new Player_Attack(pos + Vector(size.x / 2, 0),this));
	}
	SetPosition(pos + dir.Norm() * _moveSpeed * GameManager::GetDeltaTime());
}
