#include "HelloWorld.hpp"
#include "TVDR.hpp"

int main(int argc, char* args[]) {
	return Tvdr::GameManager::Run(new HelloWorld);
}