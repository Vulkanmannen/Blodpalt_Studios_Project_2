#include <SFML/Graphics.hpp>
#include "Super.h"
#include "WorldMapState.h"
#include "IntroScreen.h"
#include "LoadingState.h"
#include "EntityManager.h"
#include "NormalBlock.h"

int main()
{
	Super* super = Super::getInstance();
	super->getWindow();
	super->getWindow().setVerticalSyncEnabled(true);
	super->getWindow().setFramerateLimit(60);
	NormalBlock normal(sf::Vector2f(100, 100));
	//super->getStateManager().pushState(new WordMapState());
	//super->getStateManager().pushState(new IntroScreen());    
	LoadingState loadstate("MAPJEVEL.png");
	loadstate.update(*super);

	//super->getStateManager().pushState(new WordMapState());
	super->getStateManager().pushState(new IntroScreen());    

    while (super->getWindow().isOpen())
    {
        sf::Event event;
        while (super->getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                super->getWindow().close();
        }
		//EntityManager::getInstance()->update();
		//EntityManager::getInstance()->render();
		//super->update();

		normal.render();

		//super->draw();
       
    }

	super->getStateManager().clear();
	delete super;

    return 0;
}
