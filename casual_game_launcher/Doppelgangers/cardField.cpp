#ifndef CARDFIELD
#include "CardField.hpp"
#define CARDFIELD
#endif // !CardField

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef CTIME
#include<ctime>
#define CTIME
#endif // !CTIME

#ifndef STRING
#include<string>
#define STRING
#endif // !STRING

#ifndef CHRONO
#include <chrono>
#define CHRONO
#endif // !CHRONO

#ifndef THREAD
#include <thread>
#define THREAD
#endif // !THREAD



bool CardField::click(sf::Vector2i mouse_pos)
{
	if (ClickableObject::click(mouse_pos)) {
		for (int i = 0; i < cards.size(); ++i) {
			Card* card = cards[i];
			if (card->click(mouse_pos)) {
				std::pair<std::string, std::vector<std::string>> request = log.get_request();
				card->open_card();
				std::cout << "\nLOG COMMAND: " << request.first;
				if (request.first != "OPEN_CARD") {
					log.add({ request });
					log.add({ "OPEN_CARD",{std::to_string(card->get_suit()),std::to_string(i)}});
				}
				
				else {
					if (request.second[0] != std::to_string(card->get_suit())) {
						log.add({ {"CLOSE_CARDS",
							{request.second[1],
							std::to_string(i)}} });
						log.add({ "TIME_DELAY" });
					}
					else {
						
						log.add({"ADD_POINT"});
					}
				}
				return true;
			}
		}

	}
	return false;
}

void CardField::recombinate()
{
	srand(time(0));
	int repeate = rand() % 200 + 5, rnd_card_f, rnd_card_s;
	for (int i = 0; i < repeate; ++i) {
		rnd_card_f = rand() % cards.size();
		rnd_card_s = rand() % cards.size();
		cards[rnd_card_f]->swap_suit(cards[rnd_card_s]);
		std::cout << "\nSWAP :" << rnd_card_f << " AND " << rnd_card_s;
	}

}

void CardField::create_cards()
{
	card_width = (width - width / 8 - width * 5 / 33) / 6;
	indent_width = (width - card_width * 6)/4;
	indent_between_width = (width - card_width * 6) / 12;
	std::cout << "CARD_WIDTH: " << card_width << "\nINDENT_WIDTH: " << indent_width << "\nINDENT_BETWEEN_WIDHT: " << indent_between_width;

	card_height = (height - height * 3 / 83 - height / 8) / 4;
	indent_height = (height - card_height * 4) / 3;
	indent_between_height = (height - card_height*4 - indent_height*2) / 3;
	std::cout << "\n\nCARD_HEIGHT: " << card_height << "\nINDENT_HEIGHT: " << indent_height << "\nINDENT_BETWEEN_HEIGHT: " << indent_between_height;



	for (int i = 0; i < 6; ++i)
		for(int j = 0;j<4;++j){
			Card* tmp_card = new Card(
				{ (x + indent_width + (card_width + indent_between_width) * i),(y + indent_height + (card_height + indent_between_height )*j )},
				{100,175},
				{card_width,card_height},
				cards_textures,
				(1  + 6 * j + i)%12 +1,
				log);
			std::cout << "\nPOS: " << (1 + 6 * j + i) % 12 + 1;
			cards.push_back(tmp_card);
		}
	
}

void CardField::draw(sf::RenderWindow& window)
{
	Object::draw(window);
	for (Card* card : cards) {
		card->draw(window);
	}
}

void CardField::open_all()
{
	for (Card* card : cards) {
		card->open_card();
	}
}

void CardField::close_all()
{
	for (Card* card : cards) {
		card->close();
	}
}

void CardField::close_cards(std::vector<std::string> closing_cards)
{
	for (std::string i : closing_cards) {
		cards[std::stoi(i)]->close();
	}
}

CardField::CardField(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cards_textures,Log& log) :
	ClickableObject(pos, size, scale, texture_file,log),
	cards_textures(cards_textures)
{
	create_cards();
	recombinate();
}
