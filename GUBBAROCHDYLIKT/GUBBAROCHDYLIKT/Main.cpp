#include <SFML/Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
	LoadingState loadState("MAPJEVEL.png");
	loadState.loadLevel();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		EntityManager::getInstance()->update();
		window.clear(sf::Color(255, 0, 0, 255));
		EntityManager::getInstance()->render(window);
		window.display();
    }

    return 0;
}