#include "Enemy_Attack.hpp"
#include "Player.hpp"

using namespace Tvdr;

Enemy_Attack::Enemy_Attack(Vector stPos, Player *player): GameObject("resource/staw.bmp"){
	_player = player;
	_moveSpeed = 80.f;
	time = 0;
	SetScale(0.02f, 0.02f);
	auto size = GetPrintSize();
	SetPosition(stPos.x - size.x / 2, stPos.y);
}


Enemy_Attack::~Enemy_Attack(){

}

void Enemy_Attack::Update(){
	auto pos = GetPosition();

	auto dir = Vector(0, 1);

	SetPosition(pos + dir * _moveSpeed * GameManager::GetDeltaTime());
	if (pos.y < -GetPrintSize().y || Graphics::SCREEN_HEIGHT < pos.y)
		Release();
}