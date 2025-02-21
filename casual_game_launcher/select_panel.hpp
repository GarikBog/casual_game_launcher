#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef LAUNCHER_BUTTONS
#include "launcher_buttons.hpp"
#define LAUNCHER_BUTTONS
#endif // !BUTTONS


class SelectPanel : public ClickableObject
{
private:



	std::vector<GameButton* > game_buttons;

	GameButton* first_game, * second_game, * third_game, * fourth_game;
	GameButton* hidden_game_button;

	std::pair<float, float> pos_first_game_button, pos_second_game_button, pos_third_game_button, pos_fourth_game_button;

	int page = 0;

public:

	void update();

	void set_page(int page);
	
	void next_page();

	void previous_page();

	void draw(sf::RenderWindow& window);

	bool click(sf::Vector2i mouse_pos) override;

	SelectPanel(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log,std::pair<int,int> hidden_pos);
};