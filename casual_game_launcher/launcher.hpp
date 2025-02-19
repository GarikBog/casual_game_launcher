

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

#ifndef SELECT_PANEL
#include "select_panel.hpp"
#define SELECT_PANEL
#endif // !SELECT_PANEL

class GameLauncher : public Game {

private:

	std::string name = "GameLauncher";
	std::vector<Game* > games;
	std::pair<int, int> hidden_pos;

	int page = 0,max_page = 2;
	Log log;
	CloseButton* close;
	NextPageButton* next_button;
	PreviousPageButton* previous_button;
	SelectPanel* select_panel;

	std::vector<ClickableObject* > buttons;

	void draw(sf::RenderWindow& window);
	void update();
	void process_log();
	void process_request(Request request);
public:

	void start();

	GameLauncher(unsigned int height);
};