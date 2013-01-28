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
	//menu for MenuMusic
	//level for LevelMusic
	void playMusic(std::string music);
	void stopMusic();
protected:
	Super();

private:

	void init();
	static Super* m_instance;

	sf::RenderWindow m_window;
	sf::View m_view;
	StateManager m_stateManager;

	sf::Music mMenuMusic;
	sf::Music mLevelMusic;
	sf::Music mWinMusic;
	sf::Music mFailMusic;
};

#endif