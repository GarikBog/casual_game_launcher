#ifndef GAME
#include "game.hpp"
#define GAME
#endif // !GAME


// GAME
Game::~Game()
{
	delete window;
	delete background;
}
// GAME


// TEST GAME
void TestGame::start()
{
    window = new sf::RenderWindow(sf::VideoMode({ window_height,window_width}), name);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        background->draw(*window);
        window->display();
    }
}
TestGame::TestGame(unsigned int height)
{
    window_height = height;
    window_width = height / 2;
    background = new Object({ 0,0 }, { 50,50 }, { window_height,window_width }, "tech/error.jpg");
}
// TEST GAME
