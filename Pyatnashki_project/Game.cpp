#include "Game.h"

Game::Game()
{
	font.loadFromFile("Times New Roman.ttf");
	font.getInfo();
	Initialize();
}

int Game::Check(int result)
{
	//todo: ƒобавить имплементацию и сложную игровую логику
	if (result == 1)
		return 1;
	else
		if (result == 0)
			return 0;
}

int Game::Initialize()
{
	//«аполнени€ плиток пол€
	for (int i = 0; i < SIZE - 1; i++)
		elements[i] = i + 1;
	//”становка пустой плитки в конце дл€ тестировани€
	empty_spot = SIZE - 1;
	elements[empty_spot] = 0;
	solved = 1;
	return 1;
}

int Game::Move(int direction)
{
	//todo сделать движение во все стороны
	//todo сделать движение исход€ из положени€ плиток
	int start = 1;
	return start + direction;
}