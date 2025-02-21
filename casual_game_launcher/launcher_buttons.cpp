#ifndef LAUNCHER_BUTTONS
#include "launcher_buttons.hpp"
#define LAUNCHER_BUTTONS
#endif // !BUTTONS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

// GAME BUTTON
bool GameButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	log.add({ "BUTTON_PRESSED" });
	return true;
}

void GameButton::start_game()
{
	game->start();
}

GameButton::GameButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log, Game* game) :
	ClickableObject(pos, size, scale, texture_file, log),
	game(game)
{}
// GAME BUTTON




// CLOSE BUTTON
bool CloseButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos))  return false;

	log.add({ "CLOSE" });
	return true;
}


CloseButton::CloseButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{}



// CLOSE BUTTON


// NEXT PAGE BUTTON
bool NextPageButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos))  return false;

	log.add({ "NEXT_PAGE" });
	return true;
}
NextPageButton::NextPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{}
// NEXT PAGE BUTTON


//PREVIOUS PAGE BUTTON
bool PreviousPageButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	log.add({ "PREVIOUS_PAGE" });

	return true;
}
PreviousPageButton::PreviousPageButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{
}
//PREVIOUS PAGE BUTTON
