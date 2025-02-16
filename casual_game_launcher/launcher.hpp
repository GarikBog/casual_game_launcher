

#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef GAME
#include "game.hpp"
#define GAME
#endif // !GAME

#ifndef VECTOR
#include<vector>
#define VECTOR
#endif // !VECTOR


#ifndef LAUNCHER_BUTTONS
#include "launcher_buttons.hpp"
#define LAUNCHER_BUTTONS
#endif // !BUTTONS


class GameLauncher : public Game {

private:

	std::string name = "GameLauncher";
	std::vector<Game* > games;

	Log log;
	CloseButton* close;
	NextPageButton* next_button;
	PreviousPageButton* previous_button;

	void draw(sf::RenderWindow& window);
public:

	void start();

	GameLauncher(unsigned int height);
};