#ifndef TTT_OBJECTS
#include"TTT_Objects.hpp"
#define TTT_OBJECTS
#endif // !TTT_OBJECTS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



// TTT_CELL

bool TTT_Cell::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	log.add({"CELL_CLICKED",{std::to_string(id)}});

	return true;

}

void TTT_Cell::change_status(char new_status)
{
	
	if (new_status == ' ') {
		set_texture_rect({ 0,0,256,256 });
		status = new_status;

	}
	if (status == 'X' or status == 'x' or status == 'O' or status == 'o') return;
	if (new_status == 'X' or new_status == 'x') {
		set_texture_rect({ 256,0,256,256 });
	}
	else if (new_status == 'O' or new_status == 'o') {
		set_texture_rect({ 512,0,256,256 });
	}
	status = new_status;
}

char TTT_Cell::get_status() const
{
	return status;
}


TTT_Cell::TTT_Cell(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log, int id):
	ClickableObject(pos,size,scale,texture_file,log),
	id(id)
{
}
// TTT_CELL


// TTT_Field

void TTT_Field::draw(sf::RenderWindow& window)
{
	ClickableObject::draw(window);
	for (TTT_Cell* cell : cells) {
		cell->draw(window);
	}
}

bool TTT_Field::click(sf::Vector2i mouse_pos)
{
	if (ClickableObject::click(mouse_pos)) {
		for (TTT_Cell* cell : cells) {
			if (cell->click(mouse_pos)) return true;
		}
	}
	return false;
}

std::pair<bool, char> TTT_Field::check_game()
{
	// 012,345,678,036,147,258,048,246
	char c0 = cells[0]->get_status(),
		c1 = cells[1]->get_status(),
		c2 = cells[2]->get_status(),
		c3 = cells[3]->get_status(),
		c4 = cells[4]->get_status(),
		c5 = cells[5]->get_status(),
		c6 = cells[6]->get_status(),
		c7 = cells[7]->get_status(),
		c8 = cells[8]->get_status();
	if (c0 == c1 && c0 == c2 && c0 != ' ') return {true,c0};
	if (c3 == c4 && c3 == c5 && c3 != ' ') return { true,c3};
	if (c6 == c7 && c6 == c8 && c6 != ' ') return { true,c6};
	if (c0 == c3 && c0 == c6 && c0 != ' ') return { true,c0};
	if (c1 == c4 && c1 == c7 && c1 != ' ') return { true,c1 };
	if (c2 == c5 && c2 == c8 && c2 != ' ') return { true,c2 };
	if (c0 == c4 && c0 == c8 && c0 != ' ') return { true,c0 };
	if (c2 == c4 && c2 == c6 && c2 != ' ') return { true,c2 };

	bool res = true;
	for (TTT_Cell* cell : cells) {
		if (cell->get_status() == ' ') {
			res = false;
			break;
		}
	}
	return { res,' '};

}

void TTT_Field::change_cell_status(bool side,int id)
{
	cells[id]->change_status(side ? 'X' : 'O');
}

void TTT_Field::reset()
{
	for (TTT_Cell* cell : cells) {
		cell->change_status(' ');
	}
}

TTT_Field::TTT_Field(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cells_texture, Log& log) :
	ClickableObject(pos, size, scale, texture_file, log)
{
	int cell_width = scale.first / 3,
		cell_height = scale.second / 3;

	TTT_Cell* cell = nullptr;
	int id = 0;
	for (int i = 0; i < 3; ++i) 
	for(int j = 0;j<3;++j,++id){
		//std::cout <<"\n\tID:" << id;
		//std::cout << "\nX: " << pos.first + cell_width * i;
		//std::cout << "\nY: " << pos.second + cell_height * j;
		//std::cout << "\nW: " << cell_width;
		//std::cout << "\nH: " << cell_height;

		cell = new TTT_Cell({ pos.first + cell_width * i,pos.second + cell_height * j }, { 256,256 }, { cell_width,cell_height }, cells_texture, log, id);
		cells.push_back(cell);
	}
}
// TTT_Field


// TTT_Reset_Button
bool TTT_Reset_Button::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	log.add({ "RESET" });

	return true;
}

TTT_Reset_Button::TTT_Reset_Button(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log):
	ClickableObject(pos,size,scale,texture_file,log)
{
}

//TTT_Reset_Button
