#include "Game.h"

Game::Game()
{
	//�������� �������� ����������� ����������
}

int Game::Check(int result)
{
	//todo: �������� ������������� � ������� ������� ������
	if (result == 1)
		return 1;
	else
		if (result == 0)
			return 0;
}

int Game::Initialize()
{
	//todo: �������� ��������� �������� ���������� ����
	return 1;
}

int Game::Move(int direction)
{
	//todo ������� �������� �� ��� �������
	//todo ������� �������� ������ �� ��������� ������
	int start = 1;
	return start + direction;
}