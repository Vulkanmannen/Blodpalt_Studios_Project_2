#include <SFML/Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"
#include <iostream>
#include "Entity.h"
#include "Flower.h"
#include "Enemy.h"


int main()
{
	EntityManager::getInstance()->addEntity( new Flower( sf::Vector2f(0,0), Flower::VERTICAL) );

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garden Gnome", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	sf::View view;
	view.setSize(1980, 1080);
	LoadingState loadState("MAPJEVEL.png");
	loadState.loadLevel();
	while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
		sf::Vector2i mouse = sf::Mouse::getPosition();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear(sf::Color(0, 0, 255, 255));

		EntityManager::getInstance()->update();
		EntityManager::getInstance()->render(window);

		view.setCenter(EntityManager::getInstance()->getArvid()->getPosition());
		window.setView(view);
		window.display();
    }

    return 0;
}