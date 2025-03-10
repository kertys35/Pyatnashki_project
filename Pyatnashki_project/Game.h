#pragma once
#include "SFML/Graphics.hpp"

//Направления движения
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3						
//Параметры поля
#define SIZE 16						//Размер поля в плитках
#define FIELD_SIZE 500;				// Размер игрового поля в пикселях
#define CELL_SIZE 120;				// Размер плитки в пикселях
using namespace sf;

class Game
{
private:
	int elements[SIZE];
	int empty_spot;
	int solved;
	Font font;
public:
	Game();
	int Check(int result);
	int Initialize();
	int Move(int direction);
};

