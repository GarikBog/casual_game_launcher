#ifndef LAUNCHER
#include "launcher.hpp"
#define LAUNCHER
#endif // !LAUNCHER


void GameLauncher::draw(sf::RenderWindow& window)
{
    background->draw(window);
    close->draw(window);
    next_button->draw(window);
    previous_button->draw(window);
}

void GameLauncher::start()
{
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), name);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (log.get_request().first == "BUTTON_PRESSED") {
                    window->close();
                }
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
        indent_height = window_height / 3.75,
        indent_width_close_button = window_width / 35,
        indent_height_close_button = window_height / 30,
        height_change_page_button = window_height / 2.14,
        width_change_page_button = window_width / 6.78,
        width_close_button = window_width / 8.75,
        height_close_button = window_height / 7.5;
        


	background = new Object({ 0,0 }, { 1750,1500 }, { window_width,window_height }, "Tak_nado.png");

	previous_button = new PreviousPageButton({ indent_width_change_page_button,indent_height },
		{ 258,700 },
		{ width_change_page_button,height_change_page_button },
		"change_page_button_left.png", log);

	next_button = new NextPageButton({ window_width - indent_width_change_page_button - width_change_page_button,indent_height },
		{ 258,700 },
		{ width_change_page_button,height_change_page_button },
		"change_page_button_right.png", log);

	close = new CloseButton({window_width - indent_width_close_button - width_close_button,indent_height_close_button },
		{ 165,165 },
		{ width_close_button,height_close_button },
		"close.png", log);
}
