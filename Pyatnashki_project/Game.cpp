#include "Game.h"

Game::Game()
{
	font.loadFromFile("Times New Roman.ttf");
	font.getInfo();
	Initialize();
}

int Game::Check(int result)
{
	if (result > 0)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (elements[i] > 0 && elements[i] != i + 1)
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

int Game::Initialize()
{
	//Заполнения плиток поля
	for (int i = 0; i < SIZE - 1; i++)
		elements[i] = i + 1;
	//Установка пустой плитки в конце для тестирования
	empty_spot = SIZE - 1;
	elements[empty_spot] = 0;
	solved = 1;
	return 1;
}

int Game::Move(int direction)
{
	int column = empty_spot % SIZE_LINE;
	int row = empty_spot / SIZE_LINE;

	int move_spot = -1;
	if (direction == LEFT && column > 0)
		move_spot = empty_spot - 1;

	if (direction == RIGHT && column < (SIZE_LINE-1))
		move_spot = empty_spot + 1;

	if (direction == UP && row > 0)
		move_spot = empty_spot - SIZE_LINE;

	if (direction == DOWN && row < (SIZE_LINE - 1))
		move_spot = empty_spot + SIZE_LINE;

	int temp;
	if (empty_spot >= 0 && move_spot >= 0)
	{
		temp = elements[empty_spot];
		elements[empty_spot] = elements[move_spot];
		elements[move_spot] = temp;
		empty_spot = move_spot;
	}
	solved = Check(1);
	return empty_spot;
}