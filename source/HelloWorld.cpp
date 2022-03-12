#include "HelloWorld.hpp"
#include "Player.hpp"
#include <iostream>
#include "Enemy.hpp"

HelloWorld::HelloWorld(){
	Start();
}

void HelloWorld::Start(){
	Player *player = new Player();
	AddChild(player);
	
	for (int i = 0; i < 6; ++i)
		AddChild(new Enemy(Vector(i * 50, 0), player));
}

void HelloWorld::Update(){
	
}


