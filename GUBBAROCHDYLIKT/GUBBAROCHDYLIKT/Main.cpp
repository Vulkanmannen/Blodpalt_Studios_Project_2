#include <SFML/Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"
#include <iostream>
#include "Entity.h"
#include "Flower.h"
#include "Enemy.h"
#include <vector>

int main()
{
	EntityManager::getInstance()->addEntity( new Flower( sf::Vector2f(0,0), Flower::VERTICAL) );

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garden Gnome");

	window.setFramerateLimit(60);
	sf::View view;
	view.setSize(1980, 1080);
	
	LoadingState loadState("MAPJEVEL.png");
	loadState.loadLevel();
	
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("bgb.png");
	std::vector<sf::Sprite*> backgroundVector;
	
	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			sf::Sprite* sprite = new sf::Sprite();
			sprite->setTexture(backgroundTexture);
			sprite->setPosition(-1000 + 1000 * i, -1000 + 1000 *j);

			backgroundVector.push_back(sprite);
		}
	}

	sf::Vector2f lastPosition = EntityManager::getInstance()->getArvid()->getPosition();

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

		for(std::vector<sf::Sprite*>::size_type i = 0; i < backgroundVector.size(); ++i)
		{
			window.draw(*backgroundVector[i]);
		}

		sf::Vector2f position = EntityManager::getInstance()->getArvid()->getPosition();
		if(lastPosition != position)
		{
			sf::Vector2f move = position - lastPosition;
			for(std::vector<sf::Sprite*>::size_type i = 0; i < backgroundVector.size(); ++i)
			{
				backgroundVector[i]->setPosition(backgroundVector[i]->getPosition() + sf::Vector2f(move.x * 0.5, move.y *0.5));
			}
			lastPosition = EntityManager::getInstance()->getArvid()->getPosition();
		}

		EntityManager::getInstance()->update();
		EntityManager::getInstance()->render(window);

		view.setCenter(EntityManager::getInstance()->getArvid()->getPosition());
		window.setView(view);
		window.display();
    }

    return 0;
}