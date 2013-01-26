#include <SFML/Graphics.hpp>
#include "Super.h"
#include "WorldMapState.h"
#include "IntroScreen.h"

int main()
{
	Super* super = Super::getInstance();
	super->getWindow();
	super->getWindow().setVerticalSyncEnabled(true);
	super->getWindow().setFramerateLimit(60);


	super->getStateManager().pushState(new WordMapState());
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

		super->draw();
       
    }

	super->getStateManager().clear();
	delete super;

    return 0;
}
