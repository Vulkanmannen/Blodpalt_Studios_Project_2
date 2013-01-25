#ifndef INCLUDED_SUPER
#define INCLUDED_SUPER

#include "StateManager.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Audio\Music.hpp>


class Super
{
public:
	static Super* getInstance();
	~Super();

	sf::RenderWindow& getWindow();
	sf::View& getView();
	StateManager& getStateManager();
	
	void update();
	void draw();

protected:
	Super();

private:
	static Super* m_instance;

	sf::RenderWindow m_window;
	sf::View m_view;
	StateManager m_stateManager;
};

#endif