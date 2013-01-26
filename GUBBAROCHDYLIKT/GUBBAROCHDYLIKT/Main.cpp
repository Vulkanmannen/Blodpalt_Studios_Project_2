#include <SFML/Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garden Gnome");
	LoadingState loadState("MAPJEVEL.png");
	loadState.loadLevel();
    while (window.isOpen())
    {
		sf::Vector2i mouse = sf::Mouse::getPosition();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
<<<<<<< HEAD
=======
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				std::cout << mouse.x << " " << mouse.y << std::endl;
		EntityManager::getInstance()->update();
>>>>>>> 1280f3a323b6ee42a283575911eaff4d3c69dd14
		window.clear(sf::Color(255, 0, 0, 255));

		EntityManager::getInstance()->update();
		EntityManager::getInstance()->render(window);
		
		window.display();
    }

    return 0;
}