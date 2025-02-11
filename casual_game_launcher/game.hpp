

#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS



class Game {
protected:
	unsigned int window_width = 0, window_height = 0;
	std::string name;

	sf::RenderWindow* window;
	Object* background;


public:



	virtual void start() = 0;

	virtual ~Game();

};