#ifndef SELECT_PANEL
#include "select_panel.hpp"
#define SELECT_PANEL
#endif // !SELECT_PANEL

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef TECHIES
#include"Techies/techies.hpp"
#define TECHIES
#endif // !TECHIES

#ifndef DOPPELGANGERS
#include"Doppelgangers/doppengangers.hpp"
#define DOPPELGANGERS
#endif // !DOPPELGANGERS

#ifndef TICTACTOE
#include "TicTacToe/TicTacToe.hpp"
#define TICTACTOE
#endif // !TICTACTOE 

void SelectPanel::start()
{
	if (selected_game == nullptr) return;

	for (GameButton* game : game_buttons) {
		if (game != selected_game) {
			delete game;
		}

	}
	game_buttons.clear();
	selected_game->start_game();
}

void SelectPanel::update()
{
	first_game->set_pos(hidden_pos);
	second_game->set_pos(hidden_pos);
	third_game->set_pos(hidden_pos);
	fourth_game->set_pos(hidden_pos);

	first_game = game_buttons[page * 4];
	first_game->set_pos(pos_first_game_button);

	if (page * 4 + 1 > game_buttons.size() - 1)
		second_game = hidden_game_button;
	
	else {
		second_game = game_buttons[page * 4 + 1];
		second_game->set_pos(pos_second_game_button);
	}
	if (page * 4 + 2 > game_buttons.size() - 1)
		third_game = hidden_game_button;
	else {
		third_game = game_buttons[page * 4 + 2];
		third_game->set_pos(pos_third_game_button);
	}
	if (page * 4 + 3 > game_buttons.size() - 1)
		fourth_game = hidden_game_button;
	else {
		fourth_game = game_buttons[page * 4 + 3];
		fourth_game->set_pos(pos_fourth_game_button);
	}
	
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

	first_game->draw(window);
	second_game->draw(window);
	third_game->draw(window);
	fourth_game->draw(window);


}

bool SelectPanel::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	if (first_game->click(mouse_pos)) {
		selected_game = first_game;
		return true;
	}
	if (second_game->click(mouse_pos)){
		selected_game = second_game;
		return true;
	}
	if (third_game->click(mouse_pos)) {
		selected_game = third_game;
		return true;
	}
	if (fourth_game->click(mouse_pos)) {
		selected_game = fourth_game;
		return true;
	}

	return false;
}

SelectPanel::SelectPanel(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log,std::pair<int,int> hidden_pos,unsigned int games_height):
	ClickableObject(pos,size,scale,texture_file,log)
{
	this->hidden_pos = hidden_pos;

	hidden_game_button = new GameButton(hidden_pos, { 0,0 }, { 0,0 }, texture_file, log, nullptr);

	Techies* techies_game = new Techies(games_height);
	
	Doppelgagners* doppelgangers = new Doppelgagners(games_height);
	
	TicTacToe* tic_tac_toe = new TicTacToe(games_height);

	float	left_pos = pos.first + scale.first / 21.8,
		right_pos = pos.first +scale.first / 1.83,
		hight_pos = pos.second +scale.second / 20.8,
		low_pos = pos.second + scale.second / 1.82;

	std::pair<int,int> game_button_size = { scale.first/2.44,scale.second/2.47 };


	pos_first_game_button = { left_pos,hight_pos };

	pos_second_game_button = { right_pos,hight_pos };

	pos_third_game_button = { left_pos,low_pos };

	pos_fourth_game_button = { right_pos,low_pos };
	 

	game_buttons.push_back(new GameButton(hidden_pos, { 500,500 }, game_button_size, "logo/Techies.png", log, techies_game));
	game_buttons.push_back(new GameButton(hidden_pos, { 500,500 }, game_button_size, "logo/Doppelgangers.png", log, doppelgangers));
	game_buttons.push_back(new GameButton(hidden_pos, { 500,500 }, game_button_size, "logo/TicTacToe.png", log, tic_tac_toe));

	first_game = hidden_game_button;
	second_game = hidden_game_button;
	third_game = hidden_game_button;
	fourth_game = hidden_game_button;

	update();
}

SelectPanel::~SelectPanel()
{
	for (int i = 0; i < game_buttons.size(); ++i) {
		delete game_buttons[i];
	}
	delete hidden_game_button;
}



