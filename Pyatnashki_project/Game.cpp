#include "Game.h"

Game::Game()
{

}

int Game::Check(int result)
{
	if (result == 1)
		return 1;
	else
		if (result == 0)
			return 0;
}

int Game::Initialize()
{
	return 1;
}