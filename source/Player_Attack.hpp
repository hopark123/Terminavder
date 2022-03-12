#pragma once

#include <TVDR.hpp>
#include "Player.hpp"

using namespace Tvdr;

class Player_Attack : public Tvdr::GameObject {
public :
	Player_Attack(Vector stPos, Player *player);
	virtual ~Player_Attack();
protected:
	virtual void Update();
private:
	float _moveSpeed;
	int		time;
	Vector _stPos;
	Player *_player;
	
	Player_Attack();
};