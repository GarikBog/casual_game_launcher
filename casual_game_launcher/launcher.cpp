#ifndef LAUNCHER
#include "launcher.hpp"
#define LAUNCHER
#endif // !LAUNCHER

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

void GameLauncher::next_page()
{
    if (page < max_page) {
        ++page;
        select_panel->next_page();
    }
}

void GameLauncher::previous_page()
{
    if (page > 0) {
        --page;
        select_panel->previous_page();
    }
}

void GameLauncher::draw(sf::RenderWindow& window)
{
    update();

    background->draw(window);
    close->draw(window);
    next_button->draw(window);
    previous_button->draw(window);
    select_panel->draw(window);
}

void GameLauncher::update()
{
    if (page == 0) {
        previous_button->set_pos(hidden_pos);
    }
    else {
        previous_button->set_pos({ window_width / 175 , window_height / 3.75 });
    }
    if (page == max_page) {
        next_button->set_pos(hidden_pos);
    }
    else {
        next_button->set_pos(window_width - window_width / 175 - window_width / 5.83, window_height / 3.75);
    }
}

void GameLauncher::process_log()
{
    Request next = log.get_request();
    while (next.data().first != "EMPTY")
    {
        process_request(next);
        next = log.get_request();

    }
}

void GameLauncher::process_request(Request request)
{
    if (request.data().first == "CLOSE") {
        window->close();
    }
    if (request.data().first == "NEXT_PAGE") {
        next_page();
    }
    if (request.data().first == "PREVIOUS_PAGE") {
        previous_page();
    }
}

void GameLauncher::start()
{
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), name,sf::Style::None);
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
                std::cout << "\nClick";
                for (int i = 0; i < buttons.size(); ++i) {
                    buttons[i]->click(mouse_pos);
                }
                process_log();
            }
        }
        

        window->clear();
        draw(*window);
        window->display();
    }
}

GameLauncher::GameLauncher(unsigned int height)
{
	window_height = height;
	window_width = window_height / 0.85;

    int indent_width_change_page_button = window_width / 175,
        indent_height_change_page_button = window_height / 3.75,
        indent_width_close_button = window_width / 35,
        indent_height_close_button = window_height / 30,
        height_select_panel = window_height / 1.44,
        height_change_page_button = window_height / 2.14,
        width_slect_panel = window_width / 1.60,
        width_change_page_button = window_width / 5.83,
        width_close_button = window_width / 8.75,
        height_close_button = window_height / 7.5,
        indent_width_select_panel = window_width / 5.3,
        indent_height_select_panel = window_height / 6.8;
        
    hidden_pos = { window_width + 1,window_height + 1 };

	background = new Object({ 0,0 }, { 1750,1500 }, { window_width,window_height }, "Tak_nado.png");

	previous_button = new PreviousPageButton({ indent_width_change_page_button,indent_height_change_page_button },
		{ 258,700 },
		{ width_change_page_button,height_change_page_button },
		"change_page_button_left.png", log);

	next_button = new NextPageButton({ window_width - indent_width_change_page_button - width_change_page_button,indent_height_change_page_button },
		{ 258,700 },
		{ width_change_page_button,height_change_page_button },
		"change_page_button_right.png", log);

	close = new CloseButton({window_width - indent_width_close_button - width_close_button,indent_height_close_button },
		{ 165,165 },
		{ width_close_button,height_close_button },
		"close.png", log);

    select_panel = new SelectPanel{ {indent_width_select_panel,indent_height_select_panel},
        {100,100},
        {width_slect_panel,height_select_panel},
        "test",
        log,
        hidden_pos};

    buttons = { close,next_button,previous_button };
}

