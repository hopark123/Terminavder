#include "GameManager.hpp"

int main() {
	GameManager *game = GameManager::Instance();

	game->Run();
	GameManager::Release();
	game = NULL;

	return 0;
}