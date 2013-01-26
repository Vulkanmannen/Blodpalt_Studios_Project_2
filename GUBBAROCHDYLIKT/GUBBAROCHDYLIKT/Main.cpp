#include <SFML/Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"
#include <iostream>
#include "Entity.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garden Gnome");
	window.setFramerateLimit(60);
	sf::View view;
	view.setSize(1980, 1080);

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
		window.clear(sf::Color(255, 0, 0, 255));

		EntityManager::getInstance()->update();
		EntityManager::getInstance()->render(window);

		view.setCenter(EntityManager::getInstance()->getArvid()->getPosition());
		window.setView(view);
		window.display();
    }

    return 0;
}