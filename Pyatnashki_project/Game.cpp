#include "Game.h"

Game::Game()
{
	font.loadFromFile("Times New Roman.ttf");
	font.getInfo();
	transform.setPosition(50.0f, 50.0f);
	Initialize();
}

int Game::Check(int result)
{
	if (result > 0)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (elements[i] != i + 1)
			{
				return 0;
			}
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

int Game::Draw(RenderTarget& target, RenderStates states)
{
	states.transform *= transform.getTransform();
	
	//Отрисовка рамки
	float field = FIELD_SIZE;
	RectangleShape *shape = new RectangleShape(Vector2f(field, field));
	shape->setOutlineThickness(1.0f);
	shape->setOutlineColor(Color::Cyan);
	shape->setFillColor(Color::Transparent);

	target.draw(*shape, states);

	//Отрисовка плиток
	float rect = RECT_SIZE;
	shape->setSize(Vector2f(rect, rect));
	shape->setOutlineColor(Color::Magenta);
	shape->setOutlineThickness(1.0f);
	shape->setFillColor(Color::Transparent);

	Text *text = new Text("", font, 45);
	Text *victory = new Text(L"ВЫ ВЫИГРАЛИ!", font, 40);
	victory->setFillColor(Color::Cyan);
	victory->setPosition(100.0f, 500.0f);
	if (text != NULL)
	{


		for (int i = 0; i < SIZE; i++)
		{
			shape->setOutlineColor(Color::Magenta);
			text->setFillColor(Color::Red);
			text->setString(std::to_string(elements[i]));
			if (solved)
			{
				text->setFillColor(Color::Green);
				shape->setOutlineColor(Color::Green);
			}
			else
				if (elements[i] == i + 1)
				{
					text->setFillColor(Color::Green);
				}
			if (elements[i] > 0)
			{
				Vector2f* pos = new Vector2f(i % SIZE_LINE * rect + 10.0f, i / SIZE_LINE * rect + 10.0f);
				shape->setPosition(*pos);
				text->setPosition(pos->x + 30.0f, pos->y + 25.0f);
				target.draw(*shape, states);
				target.draw(*text, states);
				if (solved)
					target.draw(*victory, states);
			}
		}
		return 1;
	}
	else
		return 0;
}