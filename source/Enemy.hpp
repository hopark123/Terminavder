#pragma once

#include <TVDR.hpp>
#include "Player.hpp"

using namespace Tvdr;

class Enemy : public Tvdr::GameObject {
public :
	Enemy(Vector stPos, Player *player);
	virtual ~Enemy();
protected:
	virtual void Update();
private:
	float _moveSpeed;
	float _dirTime;
	float _attackTime;
	Player *_player;
	Vector _dir;
	
	Enemy();
};