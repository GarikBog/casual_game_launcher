#ifndef TECHIES_GAME
#include "techies.hpp"
#define TECHIES_GAME
#endif // !TECHIES_GAME


void Techies::draw()
{
	background->draw(*window);
	field->draw(*window);


	mine_counter->update();
	mine_counter->draw(*window);


	difficulty_button->draw(*window);

	timer->update();
	timer->draw(*window);

	for (int i = 0; i < tmp_objects.size(); ++i) tmp_objects[i]->draw(*window);
}

void Techies::restart()
{


	field->reset(difficulty);


	end = false;
	run = false;

	mine_counter->reset();
	mine_counter->set_mines(field->get_hidden_mines());

	timer->reset();
	timer->stop();


	difficulty_button->set_texture_rect({ 200 * (difficulty - 1) ,0,200,75});
}

void Techies::start()
{
	window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), name);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
					for (int i = 0; i < tmp_buttons.size(); ++i) {
						if (tmp_buttons[i]->click(sf::Mouse::getPosition(*window))) {
							difficulty = 1 + i;
							restart();
							goto skip;

						}
					}
					for (int i = 0; i < tmp_buttons.size(); ++i) {
						delete tmp_buttons[i];
					}
					tmp_objects.clear();
					tmp_buttons.clear();
					if (difficulty_button->click(sf::Mouse::getPosition(*window))) {
						restart();
					}
					else{
						if (end) continue;
						if (!run) {
							run = true;
							timer->reset();

							timer->start();
						}
						if (!field->click(sf::Mouse::getPosition(*window), false)) {
							field->open_all_mines();
							timer->stop();
							run = false;
							end = true;
						}

						if (!field->get_hidden_cells()) {
							timer->stop();

							run = false;
							end = true;
						}
					}
				skip:
					for (int i = 0; i < tmp_buttons.size(); ++i) {
						delete tmp_buttons[i];
					}
					tmp_objects.clear();
					tmp_buttons.clear();
					continue;
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
					for (int i = 0; i < tmp_buttons.size(); ++i) {
						delete tmp_buttons[i];
					}
					tmp_objects.clear();
					tmp_buttons.clear();
					if (difficulty_button->click(sf::Mouse::getPosition(*window))) {

						sf::FloatRect button_pos = difficulty_button->get_collision();
						
						Button* tmp_choise_1 = new Button(
							difficulty_button->get_pos(),
							{ 200,75 },
							difficulty_button->get_scale(),
							difficulty_button->get_texture(),
							log
						),

							* tmp_choise_2 = new Button(
								{ button_pos.left,button_pos.top + difficulty_button->get_scale().second},
								{ 200,75 },
								difficulty_button->get_scale(),
								difficulty_button->get_texture(),
								log
							),

							* tmp_choise_3 = new Button(
								{ button_pos.left,button_pos.top + difficulty_button->get_scale().second * 2 },
								{ 200,75 },
								difficulty_button->get_scale(),
								difficulty_button->get_texture(),
								log
							);

						tmp_choise_1->set_texture_rect({ 0,0,200,75 });
						tmp_choise_2->set_texture_rect({ 200,0,200,75 });
						tmp_choise_3->set_texture_rect({ 400,0,200,75 });



							
						tmp_objects.push_back(tmp_choise_1);
						tmp_objects.push_back(tmp_choise_2);
						tmp_objects.push_back(tmp_choise_3);

						tmp_buttons.push_back(tmp_choise_1);
						tmp_buttons.push_back(tmp_choise_2);
						tmp_buttons.push_back(tmp_choise_3);
					}

					if (end) continue;
					if (!run) {
						run = true;
						timer->reset();

						timer->start();
					}
					field->click(sf::Mouse::getPosition(*window), true);
					mine_counter->set_mines(field->get_hidden_mines());
					if (!field->get_hidden_cells()) {
						timer->stop();
						run = false;
						end = true;
					}
                }
            }

        }

        window->clear();
		draw();
        window->display();
    }
}

Techies::Techies(unsigned int height)
{
	window_height = height;
	window_width = height * 0.86;

	field = new Field({ window_width * 0.05,window_height*0.185}, window_width * 0.9, "defolt.png", difficulty);


	background = new Object(
		{ 0,0 },
		{ 1500,1750 },
		{ window_width,window_height },
		"backgrounds/defolt.png");

	mine_counter = new MinesCounterObject(
		{ (window_width * 0.05) ,(window_height * 0.015) },
		{60,35},
		{ (window_width * 0.27),(window_height * 0.16) },
		"counters/defolt.png");

	difficulty_button = new Button(
		{ (window_width /2 - window_width * 0.16), (window_height * 0.015) },
		{ 200,75},
		{(window_width*0.32),(window_height* 0.16)},
		"difficulty/defolt.png",
		log);

	timer = new TimerObject(
		{(window_width - window_width*0.05 - window_width * 0.27),(window_height * 0.015)},
		{ 60,35 },
		{(window_width * 0.27),(window_height * 0.16) },
		"counters/defolt.png");

	mine_counter->set_mines(field->get_hidden_mines());



}

Techies::~Techies()
{
	for (int i = 0; i < tmp_objects.size(); ++i) delete tmp_objects[i];
	delete timer;
	delete difficulty_button;
	delete mine_counter;
	delete background;
	delete field;
	delete window;
}
