#include <cstdlib>
#include <ctime>
#include "game.h"

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	game currentGame;
	currentGame.gameStart();
	return 0;
}

