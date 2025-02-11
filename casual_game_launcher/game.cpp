#ifndef GAME
#include "game.hpp"
#define GAME
#endif // !GAME


Game::~Game()
{
	delete window;
	delete background;
}
