#include "HelloWorld.hpp"
#include "Player.hpp"
#include <iostream>

HelloWorld::HelloWorld(){
	Start();
}

void HelloWorld::Start(){
	AddChild(new Player());
}

void HelloWorld::Update(){

}


