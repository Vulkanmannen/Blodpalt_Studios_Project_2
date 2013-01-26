#include "Super.h"

Super* Super::m_instance = NULL;
Super* Super::getInstance()
{
	if(m_instance == NULL)
	{
		m_instance = new Super;
	}
	return m_instance;
}

Super::Super()
{
	m_window.create(sf::VideoMode(1920, 1080), "Garden Gnome"/*, sf::Style::Fullscreen*/);
	m_view.setCenter(m_window.getPosition().x, m_window.getPosition().y);
	m_view.setSize(1920, 1080); 	
}


Super::~Super()
{
}



sf::RenderWindow& Super::getWindow()
{
	return m_window;
}

sf::View& Super::getView()
{
	return m_view;
}

StateManager& Super::getStateManager()
{
	return m_stateManager;
}


void Super::update()
{
	m_stateManager.update(*this);
}


void Super::draw()
{
	m_window.clear();
	m_stateManager.draw(*this);
	m_window.display();
}