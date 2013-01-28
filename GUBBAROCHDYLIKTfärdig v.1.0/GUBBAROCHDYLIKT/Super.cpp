#include "Super.h"
#include "ResourceHandler.h"

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
	m_window.create(sf::VideoMode(1920, 1080), "Garden Gnome", sf::Style::Fullscreen);
	m_view.setCenter(m_window.getPosition().x, m_window.getPosition().y);
	m_view.setSize(1920, 1080); 	
	init();
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

void Super::playMusic(std::string music)
{
	if(music == "menu")
	{
		mFailMusic.stop();
		mWinMusic.stop();
		mMenuMusic.stop();
		mLevelMusic.stop();
		mMenuMusic.play();
		mMenuMusic.setLoop(true);
	}
	if(music == "level")
	{
		mFailMusic.stop();
		mWinMusic.stop();
		mLevelMusic.stop();
		mMenuMusic.stop();
		mLevelMusic.play();
		mLevelMusic.setLoop(true);
	}
	if(music == "win")
	{
		mFailMusic.stop();
		mWinMusic.stop();
		mLevelMusic.stop();
		mMenuMusic.stop();
		mWinMusic.play();
	}
		if(music == "death")
	{
		mFailMusic.stop();
		mWinMusic.stop();
		mLevelMusic.stop();
		mMenuMusic.stop();
		mFailMusic.play();
	}
}

void Super::stopMusic(){
	mFailMusic.stop();
	mWinMusic.stop();
	mLevelMusic.stop();
	mMenuMusic.stop();
}

void Super::init()
{
	mMenuMusic.openFromFile("Music/1.0GardenGnome-TitleScreen.ogg");
	mMenuMusic.setVolume(70);

	mLevelMusic.openFromFile("Music/1.0GardenGnome-WorldMap.ogg");
	mLevelMusic.setVolume(70);

	mWinMusic.openFromFile("Music/1.0GardenGnome-LevelClear4.ogg");
	mWinMusic.setVolume(70);

	mFailMusic.openFromFile("Music/1.0GardenGnome-DeathScreen.ogg");
	mFailMusic.setVolume(70);
}