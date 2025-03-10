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
	//���������� ������ ����
	for (int i = 0; i < SIZE - 1; i++)
		elements[i] = i + 1;
	//��������� ������ ������ � ����� ��� ������������
	empty_spot = SIZE - 1;
	elements[empty_spot] = 0;
	solved = 1;
	return 1;
}

int Game::Move(int direction)
{
	//todo ������� �������� �� ��� �������
	//todo ������� �������� ������ �� ��������� ������
	int start = 1;
	return start + direction;
}