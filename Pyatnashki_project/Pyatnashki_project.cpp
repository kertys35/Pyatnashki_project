#include <iostream>
#include "Game.h"
#include "SFML/Graphics.hpp"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(650, 650), "Pyatnashki");

    Event windowEvent;

    while (window.isOpen())
    {
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == Event::Closed)
                window.close();
            //Обработчик нажатия клавиш
            if (windowEvent.type == Event::KeyPressed)
            {
                if (windowEvent.key.code == Keyboard::Escape)
                    window.close();
            }
        }
        window.clear();
        window.display();
    }

}

