#include "HelloWorld.hpp"
#include <TVDR.hpp>

int main(){
	return Tvdr::GameManager::Run(new HelloWorld);
}