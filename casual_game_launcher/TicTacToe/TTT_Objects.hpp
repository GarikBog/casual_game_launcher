#ifndef OBJECTS
#include"../objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef LOG
#include"../log.hpp"
#define LOG
#endif // !LOG

#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS



#ifndef VECTOR
#include<vector>
#define VECTOR
#endif // !VECTOR




class TTT_Cell: public  ClickableObject {

private:

	char status = ' ';

	int id;


public:
	bool click(sf::Vector2i mouse_pos) override;

	void change_status(char new_status);

	char get_status() const;

	TTT_Cell(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log,int id);
	
};



class TTT_Field: public ClickableObject{

private:
	std::vector<TTT_Cell* > cells;


public:
	void change_cell_status(bool side,int id);

	void draw(sf::RenderWindow& window);
	bool click(sf::Vector2i mouse_pos) override;

	std::pair<bool, char> check_game();

	
	void reset();

	TTT_Field(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,std::string cells_testure, Log& log);

};



class TTT_Reset_Button : public ClickableObject {

private:



public:
	bool click(sf::Vector2i mouse_pos) override;

	TTT_Reset_Button(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);
};