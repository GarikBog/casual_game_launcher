#ifndef SELECT_PANEL
#include "select_panel.hpp"
#define SELECT_PANEL
#endif // !SELECT_PANEL

#ifndef IOSTREAM
#include<iostream>
#include "launcher.hpp"
#define IOSTREAM
#endif // !IOSTREAM


void SelectPanel::update()
{
	first_game = game_buttons[page * 4];

	if (page * 4 + 1 > game_buttons.size() - 1)
		second_game = hidden_game_button;
	else
		second_game = game_buttons[page * 4 + 1];
	if (page * 4 + 2 > game_buttons.size() - 1)
		third_game = hidden_game_button;
	else
		third_game = game_buttons[page * 4 + 2];
	if (page * 4 + 3 > game_buttons.size() - 1)
		fourth_game = hidden_game_button;
	else
		fourth_game = game_buttons[page * 4 + 3];
	
}

void SelectPanel::set_page(int page)
{
	this->page = page;


	update();

}

void SelectPanel::next_page()
{
	++page;
	update();
}

void SelectPanel::previous_page()
{
	--page;
	update();
}

void SelectPanel::draw(sf::RenderWindow& window)
{
	ClickableObject::draw(window);


}

bool SelectPanel::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;
	log.add({ "CLOSE" });

	return true;
}

SelectPanel::SelectPanel(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log,std::pair<int,int> hidden_pos):
	ClickableObject(pos,size,scale,texture_file,log)
{

	hidden_game_button = new GameButton(hidden_pos, { 0,0 }, { 0,0 }, texture_file, log, nullptr);


	first_game = nullptr;
	second_game = nullptr;
	third_game = nullptr;
	fourth_game = nullptr;

}



