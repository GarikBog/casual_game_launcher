#ifndef OBJECTS
#include"objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef LOG
#include"log.hpp"
#define LOG
#endif // !LOG

#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS

#ifndef BUTTONS
#include "buttons.hpp"
#define BUTTONS
#endif // !BUTTONS


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    Log log;
    TestGame game(1000);

    GameButton button({ 50,50 }, { 20,20 }, { 100,100 }, "qweqw", log,game);

    GameButton* open_button_game;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                button.click(sf::Mouse::getPosition(window));
                if (log.get_request().first == "BUTTON_PRESSD") {
                    window.close();
                    button.start_game();
                }
            }
        }

        window.clear();
        button.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}