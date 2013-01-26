#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML\Graphics\Image.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Audio\Music.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>

#include <string>
#include <map>
#include <memory>

class ResourceHandler
{
public:
	~ResourceHandler();
	
	static ResourceHandler* getInstance();

	static std::shared_ptr<sf::Image> loadImageFromFile(const std::string &path);
	std::shared_ptr<sf::Image> loadImage(const std::string &path);
	static void render(sf::Drawable &drawable);


	static std::shared_ptr<sf::SoundBuffer> loadSoundFromFile(const std::string &path);
	std::shared_ptr<sf::SoundBuffer> loadSound(const std::string &path);


	static std::shared_ptr<sf::Music> loadMusicFromFile(const std::string &path);
	std::shared_ptr<sf::Music> loadMusic(const std::string &path);

private:
	static ResourceHandler* mInstance;
	ResourceHandler();

	//sf::RenderWindow &window;

	std::map<std::string, std::weak_ptr<sf::Image> >	Images;
	std::map<std::string, std::weak_ptr<sf::Music> >	Music;
	std::map<std::string, std::weak_ptr<sf::SoundBuffer> > Sounds;
};
#endif