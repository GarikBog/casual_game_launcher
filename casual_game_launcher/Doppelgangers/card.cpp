

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD




void Card::set_suit(int suit)
{
	this->suit = suit;
}


int Card::get_suit() const
{
	return suit;
}

bool Card::click(sf::Vector2i mouse_pos)
{
	if (!open) {
		return ClickableObject::click(mouse_pos);
	}
	return false;
}

void Card::open_card()
{
	if (!open) {
		open = true;
		set_texture_rect({ (100 * suit),0,100,175});
	}
}

void Card::close() {

	if (open) {
		open = false;
		set_texture_rect({ 0,0,100,175 });
	}

}

bool Card::is_open() const
{
	return open;
}

void Card::swap_suit(Card* card)
{
	int tmp = card->get_suit();
	card->set_suit(suit);
	suit = tmp;
}



Card::Card(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int suit, Log& log) :
	ClickableObject(pos, size, scale, texture_file,log),
	suit(suit),
	open(false)
{
}
