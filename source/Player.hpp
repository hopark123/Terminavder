#pragma once

#include <TVDR.hpp>

class Player : public Tvdr::GameObject{
public:
	Player();
	virtual ~Player();
protected:
	virtual void Update();
private:
	float _moveSpeed;
};