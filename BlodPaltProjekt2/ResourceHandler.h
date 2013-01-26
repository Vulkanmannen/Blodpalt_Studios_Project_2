#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML\Graphics\Image.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Audio\Music.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include <SFML\System\Clock.hpp>

#include <string>
#include <map>

class ResourceHandler
{
public:
	~ResourceHandler();
	
	//Singleton mönster för instansiering
	static ResourceHandler* getInstance();

	//Image funktioner
	static sf::Image* loadImageFromFile(const std::string &path);
	sf::Image* loadImage(const std::string &path);
	static void render(sf::Drawable *drawable);


	//Sound funktioner
	static sf::SoundBuffer* loadSoundFromFile(const std::string &path);
	sf::SoundBuffer* loadSound(const std::string &path);


	//Music funktioner
	static sf::Music* loadMusicFromFile(const std::string &path);
	sf::Music* loadMusic(const std::string &path);
	sf::Music* getMusicFromMap();

private:
	ResourceHandler();
	ResourceHandler operator = (const ResourceHandler& resourceHandler) { }
	ResourceHandler(const ResourceHandler& copy) { }

	//Singleton mönster för instansiering
	static ResourceHandler* mInstance;

	//std::map :ar innehållandes Images, SoundBuffers and Music
	std::map<std::string, sf::Image*> Images;
	std::map<std::string, sf::Music*> Music;
	std::map<std::string, sf::SoundBuffer*> Sounds;
	
	//används för att rensa mapparna på information
	void internalClear();
};
#endif