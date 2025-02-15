#ifndef LAUNCHER_BUTTONS
#include "launcher_buttons.hpp"
#define LAUNCHER_BUTTONS
#endif // !BUTTONS

// GAME BUTTON
void GameButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return;

	log.add({ "BUTTON_PRESSED" });
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




// CLOSE BUTTON
void CloseButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return;

	log.add({ "CLOSE" });
}

CloseButton::CloseButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{}



// CLOSE BUTTON


// NEXT PAGE BUTTON
void NextPageButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return;

	log.add({ "NEXT_PAGE" });
}
NextPageButton::NextPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{}
// NEXT PAGE BUTTON


//PREVIOUS PAGE BUTTON
void PreviousPageButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return;

	log.add({ "PREVIOUS_PAGE" });
}
PreviousPageButton::PreviousPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{
}
//PREVIOUS PAGE BUTTON
