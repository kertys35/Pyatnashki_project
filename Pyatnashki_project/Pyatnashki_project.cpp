#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include "Game.h"
#include "SFML/Graphics.hpp"
using namespace sf;

int main()
{
    //Создание окна
    RenderWindow window(VideoMode(600,600), L"Пятнашки");
    Event windowEvent;
    Font font;
    font.loadFromFile("Times New Roman.ttf");
    RenderStates state;
    int seed = time(NULL);
    srand(seed);
    //Текст с обозначением клавиш
    Text* text = new Text(L"F1 - Новая игра / Esc - Выход / Стрелочки - Передвижение плиток", font, 20);
    text->setFillColor(Color::Cyan);
    text->setPosition(10.0f, 10.0f);
    Game* game = new Game();
    int counter = 0; //Счетчик ходов для случайной перестановки

    while (window.isOpen())
    {
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == Event::Closed)
                window.close();
            //Обработчик нажатия клавиш
            if (windowEvent.type == Event::KeyPressed)
            {

                if (windowEvent.key.code == Keyboard::Escape)   //Выход
                    window.close();
                //Перемещение
                if (windowEvent.key.code == Keyboard::Left)
                    game->Move(LEFT);
                if (windowEvent.key.code == Keyboard::Right)
                    game->Move(RIGHT);
                if (windowEvent.key.code == Keyboard::Up)
                    game->Move(UP);
                if(windowEvent.key.code == Keyboard::Down)
                    game->Move(DOWN);
                //Новая игра
                if (windowEvent.key.code == Keyboard::F1)
                {
                    game->Initialize();
                    counter = 100;
                }
            }
        }
        //Случайно заданное поле
        if (counter > 0)
        {
            game->Move((rand() % 3));
            counter--;
        }
        window.clear();
        game->Draw(window, state);
        window.draw(*text);
        window.display();
    }

}

