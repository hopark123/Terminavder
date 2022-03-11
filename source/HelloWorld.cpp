#include "HelloWorld.hpp"
#include <iostream>

HelloWorld::HelloWorld(){
	Start();
}

void HelloWorld::Start(){
	AddChild(new Tvdr::GameObject("resource/dots.bmp"));
}

void HelloWorld::Update(){

}
