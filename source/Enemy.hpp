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
	int		time;
	Vector _stPos;
	Player *_player;
	
	Enemy();
};