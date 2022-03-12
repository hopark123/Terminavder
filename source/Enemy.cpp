#include "Enemy.hpp"
#include "Player.hpp"
#include "Enemy_Attack.hpp"

using namespace Tvdr;

Enemy::Enemy(Vector stPos, Player *player): GameObject("resource/pineApple.bmp"){
	auto size = GetPrintSize();
	_player = player;
	_moveSpeed = 20.f;
	_dirTime = 0;
	_attackTime = 0;
	_dir = Vector(1, 1);
	SetPosition((Graphics::SCREEN_WIDTH - size.x) / 2 + stPos.x, stPos.y);
	SetScale(0.2f, 0.2f);
}


Enemy::~Enemy(){

}

void Enemy::Update(){
	auto playerPos = _player->GetPosition();
	auto pos = GetPosition();
	
	_dirTime += GameManager::GetDeltaTime();
	_attackTime += GameManager::GetDeltaTime();
	if (playerPos.y > pos.y && pos.y < Graphics::SCREEN_HEIGHT / 4 * 3) {
		if (_dirTime >= 2) {
			_dirTime = 0;
			_dir.x = -_dir.x;
		}
		if (_attackTime >= 3) {
			auto size = GetPrintSize();
			_attackTime = 0;
			AddChild(new Enemy_Attack(pos + Vector(size.x / 2, size.y), _player));
		}
	}
	else 
		_dir.x = 0;
	SetPosition(pos + _dir.Norm() * _moveSpeed * GameManager::GetDeltaTime());
}