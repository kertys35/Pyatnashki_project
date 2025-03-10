#include "Game.h"

Game::Game()
{
	//Добавить загрузку изначальных параметров
}

int Game::Check(int result)
{
	//todo: Добавить имплементацию и сложную игровую логику
	if (result == 1)
		return 1;
	else
		if (result == 0)
			return 0;
}

int Game::Initialize()
{
	//todo: Добавить начальные значения параметров игры
	return 1;
}

int Game::Move(int direction)
{
	//todo сделать движение во все стороны
	//todo сделать движение исходя из положения плиток
	int start = 1;
	return start + direction;
}