#include "ResourceHandler.h"
#include <iostream>
#include <cassert>

ResourceHandler* ResourceHandler::mInstance = NULL;
ResourceHandler* ResourceHandler::getInstance()
{
	if(mInstance == NULL)
	{
		mInstance = new ResourceHandler();
	}
	return mInstance;	
}

ResourceHandler::ResourceHandler() { }
ResourceHandler::~ResourceHandler(){ }


/*********************	
 *	IMAGE FUNKTIONER *
 *********************/

std::shared_ptr<sf::Image> ResourceHandler::loadImageFromFile(const std::string &path)
{
	std::shared_ptr<sf::Image> image = std::make_shared<sf::Image>();
	image->loadFromFile(path);

	if(!image->loadFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in bild" << std::endl;
		assert(false);
	}
	return image;
}


std::shared_ptr<sf::Image> ResourceHandler::loadImage(const std::string &path)
{
	std::shared_ptr<sf::Image> image;

	if(Images.find(path) == Images.end() || Images.find(path)->second.expired()) 
	{
		image = loadImageFromFile(path);
		Images.insert(std::pair<std::string, std::weak_ptr<sf::Image> >(path, image)); 
	}
	return Images.find(path)->second.lock();;
}

void ResourceHandler::render(sf::Drawable &drawable)
{
	
}

/*********************	
 *	SOUND FUNKTIONER *
 *********************/

std::shared_ptr<sf::SoundBuffer> ResourceHandler::loadSoundFromFile(const std::string &path)
{
	std::shared_ptr<sf::SoundBuffer> buffer = std::make_shared<sf::SoundBuffer>(); 
	buffer->loadFromFile(path);

	if(!buffer->loadFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in ljud" << std::endl;
		assert(false);
	}

	return buffer;
}


std::shared_ptr<sf::SoundBuffer> ResourceHandler::loadSound(const std::string &path) 
{
	std::shared_ptr<sf::SoundBuffer> buffer;

	if(Sounds.find(path) == Sounds.end() || Sounds.find(path)->second.expired()) 
	{
		buffer = loadSoundFromFile(path);
		Sounds.insert(std::pair<std::string, std::weak_ptr<sf::SoundBuffer> >(path, buffer)); 
	}
		
	return Sounds.find(path)->second.lock();
}


/*********************	
 *	MUSIC FUNKTIONER *
 *********************/

std::shared_ptr<sf::Music> ResourceHandler::loadMusicFromFile(const std::string &path)
{
	std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
	music->openFromFile(path);

	if(!music->openFromFile(path))
	{
		std::cout << "ERROR! kan inte ladda in musik" << std::endl;
		assert(false);
	}

	return music;
}


std::shared_ptr<sf::Music> ResourceHandler::loadMusic(const std::string &path)
{
	std::shared_ptr<sf::Music> music;

	if(Music.find(path) == Music.end() || Music.find(path)->second.expired()) 
	{
		music = loadMusicFromFile(path);
		Music.insert(std::pair<std::string, std::weak_ptr<sf::SoundBuffer> >(path, music));

	}

	return  Music.find(path)->second.lock();;
}