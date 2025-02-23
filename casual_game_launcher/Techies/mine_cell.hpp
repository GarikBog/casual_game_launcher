#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


class MineCell {

private:
	// COORDS && SIZE
	float x = 0, y = 0;
	int size = 0;

	//TEXTURE
	int texture_file_pos_x = 0;
	int texture_file_pos_y = 0;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;


	//TECH
	int mines_near = 0;
	bool mine = false;
	bool open = false;
	bool flag = false;

public:

	//SETTERS
	void set_pos(float new_x, float new_y);
	void set_pos(std::pair<float, float> new_coords);

	void set_scale(float scale);
	void set_texture_size(int size);
	void set_texture_pos(std::pair<int, int> pos);
	void set_texture(std::string texture);
	
	bool set_flag();


	//GETTERS
	std::pair<float, float> get_coords() const;
	double get_x() const;
	double get_y() const;

	int get_size() const;

	int get_mines_near() const;

	
	//TECH
	void new_mine_near();
	void open_this_cell();
	void set_mine();
	bool is_open();
	bool is_mine();
	bool is_flag();
	void draw(sf::RenderWindow& window);




	//OTHER
	MineCell(float x, float y, int scale, std::string texture);

};


