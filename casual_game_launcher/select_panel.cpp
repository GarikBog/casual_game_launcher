#ifndef SELECT_PANEL
#include "select_panel.hpp"
#define SELECT_PANEL
#endif // !SELECT_PANEL

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM


void SelectPanel::draw(sf::RenderWindow& window)
{
	ClickableObject::draw(window);


}

void SelectPanel::click(sf::Vector2i mouse_pos)
{
	if (ClickableObject::click(mouse_pos)) {
		std::cout << "Click";
	}
}

SelectPanel::SelectPanel(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log):
	ClickableObject(pos,size,scale,texture_file,log)
{
	first_game = nullptr;
	second_game = nullptr;
	third_game = nullptr;
	fourth_game = nullptr;

}
