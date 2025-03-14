#pragma once
#include "SFML/Graphics.hpp"

//����������� ��������
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3						
//��������� ����
#define SIZE_LINE 4					//������ ��������� � �������� � �������
#define SIZE 16						//������ ���� � �������
#define FIELD_SIZE 500;				// ������ �������� ���� � ��������
#define RECT_SIZE 120;				// ������ ������ � ��������
using namespace sf;

class Game
{
private:
	Transformable transform;
	int elements[SIZE];
	int empty_spot;
	int solved;
	Font font;
public:
	Game();
	int Check(int result);
	int Initialize();
	int Move(int direction);
	int Draw(RenderTarget& target, sf::RenderStates states);
};

