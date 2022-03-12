#pragma once

#include <TVDR.hpp>
#include "Player.hpp"

using namespace Tvdr;

class Enemy_Attack : public Tvdr::GameObject {
public :
	Enemy_Attack(Vector stPos, Player *player);
	virtual ~Enemy_Attack();
protected:
	virtual void Update();
private:
	float _moveSpeed;
	int		time;
	Vector _stPos;
	Player *_player;
	
	Enemy_Attack();
};