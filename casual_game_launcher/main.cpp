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


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");


    Object test({50,50},{50,50},{50,50},"Your texture path");



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        test.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}