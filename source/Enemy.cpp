#include "Enemy.hpp"
#include "Player.hpp"
#include "Enemy_Attack.hpp"

using namespace Tvdr;

Enemy::Enemy(Vector stPos, Player *player): GameObject("resource/pineApple.bmp"){
	auto size = getTextureSize();
	_player = player;
	_moveSpeed = 20.f;
	time = 0;
	SetPosition((Graphics::SCREEN_WIDTH - size.x) / 2 + stPos.x, stPos.y);
	SetScale(0.2f, 0.2f);
}


Enemy::~Enemy(){

}

void Enemy::Update(){
	auto playerPos = _player->GetPosition();
	auto pos = GetPosition();
	auto dir = Vector(0, 0);
	
	time++;
	dir.y += GameManager::GetDeltaTime();
	if (playerPos.y -  pos.y >= 0 && pos.y >= Graphics::SCREEN_HEIGHT / 50) {
		if ((time / 100) % 2 == 0)
			dir.x -= GameManager::GetDeltaTime();
		else
			dir.x += GameManager::GetDeltaTime();
		if (time % 300 == 0) {
			AddChild(new Enemy_Attack(pos + dir.Norm() + Vector(0, 50), _player));
		}
	}
	SetPosition(pos + dir.Norm() * _moveSpeed * GameManager::GetDeltaTime());
}