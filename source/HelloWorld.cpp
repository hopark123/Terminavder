#include "HelloWorld.hpp"
#include <iostream>

HelloWorld::HelloWorld(){
	Start();
}

void HelloWorld::Start(){
	AddChild(new Tvdr::GameObject("resource/smalldots.bmp"));
}

void HelloWorld::Update(){

}
