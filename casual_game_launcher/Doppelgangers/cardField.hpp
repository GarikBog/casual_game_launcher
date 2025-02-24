#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef LOG
#include "../log.hpp"
#define LOG
#endif // !LOG

#ifndef OBJECTS
#include "../objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD


class CardField : public ClickableObject{

private:


	//SIZE POS
	int card_width = 0, card_height = 0,indent_width = 0,indent_height = 0,indent_between_width = 0,indent_between_height = 0;

	//TEXTURES
	std::string cards_textures;


	//TECH
	std::vector<Card*> cards;
	
public:
	
	 
	//TECH
	bool click(sf::Vector2i mouse_pos);
	void recombinate();
	void create_cards();
	void draw(sf::RenderWindow& window);
	void open_all();
	void close_all();
	void close_cards(std::vector<std::string> closing_cards);
	CardField(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cards_textures, Log& log );


};



