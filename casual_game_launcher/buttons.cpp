#ifndef BUTTONS
#include "buttons.hpp"
#define BUTTONS
#endif // !BUTTONS

// GAME BUTTON
void GameButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return;

	log.add({ "BUTTON_PRESSD" });
}

void GameButton::start_game()
{
	game.start();
}

GameButton::GameButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log, Game& game) :
	ClickableObject(pos, size, scale, texture_file, log),
	game(game)
{}
// GAME BUTTON
