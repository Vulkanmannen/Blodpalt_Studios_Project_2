#include <SFML\Graphics.hpp>
#include "LoadingState.h"
#include "EntityManager.h"
#include <iostream>
#include "Entity.h"
#include "Flower.h"
#include "Enemy.h"
#include <vector>
#include "Super.h"
#include "IntroScreen.h"

int main()
{
	Super* super = Super::getInstance();

	super->getWindow();
	super->getWindow().setVerticalSyncEnabled(true);
	super->getWindow().setFramerateLimit(60);

	super->getStateManager().pushState(new IntroScreen());

	while (super->getWindow().isOpen())
    {

		sf::Event event;
        while (super->getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                super->getWindow().close();
        }

		super->update();
		super->getWindow().setView(super->getView());
		super->draw();
    }

	super->stopMusic();
	//super->getStateManager().clear();
	//delete Super::getInstance();
	//delete EntityManager::getInstance();

    return 0;
}