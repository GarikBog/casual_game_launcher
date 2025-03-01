#ifndef TICTACTOE
#include "TicTacToe.hpp"
#define TICTACTOE
#endif // !TICTACTOE 


void TicTacToe::draw()
{
	background->draw(*window);
	field->draw(*window);
	close->draw(*window);
	reset_button->draw(*window);
	cross_score_counter->draw(*window);
	circle_score_counter->draw(*window);
	if (!game_run) {
		end_game_text->draw(*window);
	}


}

void TicTacToe::reset()
{
	field->reset();
	game_run = true;
	side = true;
	delete end_game_text;
}

void TicTacToe::process_request(Request request)
{
	if (request.data().first == "CLOSE") window->close();
	if (request.data().first == "RESET") reset();
	if (request.data().first == "GAME_ENDED") {
		if (request.data().second[0] == std::to_string('X') or request.data().second[0] == std::to_string('x')) cross_won();
		if (request.data().second[0] == std::to_string('O') or request.data().second[0] == std::to_string('o')) circle_won();
		if (request.data().second[0] == std::to_string(' ')) friendship_won();

	}
	if (request.data().first == "CELL_CLICKED") {
		field->change_cell_status(side, std::stoi(request.data().second[0]));
		side = !side;
		std::pair<bool, char> res = field->check_game();
		if (res.first) { 
			log.add({ "GAME_ENDED",{std::to_string(res.second)} });
		}
	}

}

void TicTacToe::process_log()
{
	Request next = log.get_request();
	while (next.data().first != "EMPTY") {

		process_request(next);
		next = log.get_request();
	}
}

void TicTacToe::friendship_won()
{
	game_run = false;
	end_game_text = new Object({ window_width / 40,window_height / 6.08 }, { 512,122 }, { window_width / 1.05,window_height / 1.228 }, "tech/Frendship_won.png");

}

void TicTacToe::cross_won()
{
	cross_score_counter->add_point();
	game_run = false;
	end_game_text = new Object({ window_width / 40,window_height / 6.08 }, { 512,122 }, { window_width / 1.05,window_height / 1.228 }, "tech/Cross_won.png");
	

}

void TicTacToe::circle_won()
{
	circle_score_counter->add_point();
	game_run = false;
	end_game_text = new Object({ window_width / 40,window_height / 6.08 }, { 512,122 }, { window_width / 1.05,window_height / 1.228 }, "tech/Circle_won.png");

}

void TicTacToe::start()
{
	window = new sf::RenderWindow (sf::VideoMode(window_width, window_height), name,sf::Style::None);





	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::MouseButtonReleased) {
				sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
					close->click(mouse_pos);
					reset_button->click(mouse_pos);
					if (game_run)
						field->click(mouse_pos);

					process_log();

				}
			}
		} 

		window->clear();
		draw();
		window->display();
	}

}

TicTacToe::TicTacToe(int height)
{
	window_height = height;
	window_width = window_height / 1.16;

	int buttons_top_indent = window_height / 87.5,
		score_counter_width = window_width / 5,
		buttons_height = window_height / 8.3,
		close_button_right_indent = window_width / 37.5,
		cross_score_counter_right_indent = window_width/1.66,
		circle_score_counter_left_indent = window_width / 5,
		reset_button_indent = window_width / 2.33;

	//std::cout << "\nbuttons_top_indent\t" << buttons_top_indent << "\t 20\n";
	//std::cout << "score_counter_width\t" << score_counter_width << "\t 300\n";
	//std::cout << "buttons_height\t" << buttons_height << "\t 210\n";
	//std::cout << "close_button_right_indent\t" << close_button_right_indent << "\t 40\n";
	//std::cout << "cross_score_counter_right_indent\t" << cross_score_counter_right_indent << "\t 1199\n";
	//std::cout << "circle_score_counter_left_indent\t" << circle_score_counter_left_indent << "\t 300\n";
	//std::cout << "reset_button_indent\t" << reset_button_indent << "\t 643\n";



	background = new Object({ 0,0 }, { 800,800 }, { window_width,window_height }, "background/defolt_TTT_bg.png");

	close = new CloseButton({ window_width - close_button_right_indent - buttons_height, buttons_top_indent },
		{ 256,256 },
		{ buttons_height,buttons_height },
		"tech/red_cross.png",
		log);

	field = new TTT_Field({ window_width / 40,window_height / 6.08 },
		{ 1425,1425 },
		{ window_width / 1.05,window_height / 1.228 },
		"background/defolt_TTT_bg.png", "cells/defolt_TTT_cells.png",
		log);

	circle_score_counter = new Base_counter({ circle_score_counter_left_indent ,buttons_top_indent },
		{ 60,35 },
		{ score_counter_width ,buttons_height },
		"counters/defolt.png");

	cross_score_counter = new Base_counter({ cross_score_counter_right_indent ,buttons_top_indent },
		{ 60,35 },
		{ score_counter_width ,buttons_height },
		"counters/defolt.png");

	reset_button = new TTT_Reset_Button({ reset_button_indent,buttons_top_indent },
		{ 256,256 },
		{ buttons_height ,buttons_height },
		"tech/defolt_TTT_reset.png",
		log);

}

TicTacToe::~TicTacToe()
{
	delete close;
	delete field;
	delete circle_score_counter;
	delete cross_score_counter;
	delete reset_button;


	
}
