

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



class GameButton : public ClickableObject {

private:
	
	Game& game;

public:

	bool click(sf::Vector2i mouse_pos) override;

	void start_game();
	GameButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log,Game& game);

};



class CloseButton : public ClickableObject {

public:
	bool click(sf::Vector2i mouse_pos) override;

	CloseButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);

};


class NextPageButton : public ClickableObject {


public:
	bool click(sf::Vector2i mouse_pos) override;

	NextPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);

};


class PreviousPageButton : public ClickableObject {



public:
	bool click(sf::Vector2i mouse_pos) override;

	class PreviousPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);

};