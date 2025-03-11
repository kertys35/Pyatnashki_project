#include <iostream>
#include "Game.h"
#include "SFML/Graphics.hpp"
using namespace sf;

int main()
{
    //Создание окна
    RenderWindow window(VideoMode(700,700), L"Пятнашки");
    Event windowEvent;
    Font font;
    font.loadFromFile("Times New Roman.ttf");
    RenderStates state;
  
    //Текст с обозначением клавиш
    Text* text = new Text(L"F1 - Новая игра / Esc - Выход / Стрелочки - Передвижение плиток", font, 25);
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
                switch (windowEvent.key.code)
                {
                case Keyboard::Escape:  //Выход
                    window.close();
                    break;
                case Keyboard::Left:    //Движение влево
                    game->Move(LEFT);
                    break;
                case Keyboard::Right:   //Движение вправо
                    game->Move(RIGHT);
                    break;
                case Keyboard::Up:      //Движение вверх
                    game->Move(UP);
                    break;
                case Keyboard::Down:   //Движение вниз
                    game->Move(DOWN);
                case Keyboard::F1:      //Новая игра
                    game->Initialize();
                    counter = 100;
                    break;
                default:
                    break;
                }

            }
        }
        //Случайно заданное поле
        while(counter > 0)
        {
            srand(time(NULL));
            int random = rand() % 3;
            game->Move(random);
            counter--;

        }
        window.clear();
        game->Draw(window, state);
        window.draw(*text);
        window.display();
    }

}

