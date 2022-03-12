#include "Player_Attack.hpp"
#include "Player.hpp"

using namespace Tvdr;

Player_Attack::Player_Attack(Vector stPos, Player *player): GameObject("resource/staw.bmp"){
	auto size = getTextureSize();
	_player = player;
	_moveSpeed = 80.f;
	time = 0;
	SetPosition(stPos.x, stPos.y);
	SetScale(0.02f, 0.02f);
}


Player_Attack::~Player_Attack(){

}

void Player_Attack::Update(){
	auto playerPos = _player->GetPosition();
	auto pos = GetPosition();
	auto dir = Vector(0, 0);
	dir.y -= GameManager::GetDeltaTime();

	SetPosition(pos + dir.Norm() * _moveSpeed * GameManager::GetDeltaTime());
}