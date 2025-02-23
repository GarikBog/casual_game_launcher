
#ifndef MINE_FIELD
#include"mine_field.hpp"
#define MINE_FIELD
#endif // !FIELD

#ifndef CTIME
#include<ctime>
#define CTIME
#endif // !CTIME

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM




//SETTERS
void Field::set_sprite_coords(std::pair<float, float> coords)
{
	sprite_x = coords.first;
	sprite_y = coords.second;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_coords(float x, float y)
{
	sprite_x = x;
	sprite_y = y;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_x(float x)
{
	sprite_x = x;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_y(float y)
{
	sprite_y = y;

	sprite.setPosition(sprite_x, sprite_y);
}

void Field::set_sprite_size(int size)
{
	sprite_size = size;

	sprite.setTextureRect({ 0,0,size,size });
}

void Field::set_texture(std::string texture_file)
{
	if (!texture.loadFromFile("textures/fields/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
	}

	sprite.setTexture(texture);
}




//GETTERS
std::pair<float, float> Field::get_pos() const
{
	return {sprite_x,sprite_y};
}

float Field::get_x() const
{
	return sprite_x;
}

float Field::get_y() const
{
	return sprite_y;
}

int Field::get_size() const
{
	return sprite_size;
}

int Field::get_hidden_cells() const
{
	return hidden_cells;
}

int Field::get_total_cells() const
{
	return total_cells;
}

int Field::get_hidden_mines() const
{
	return hidden_mines;
}


//TECH
void Field::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for(int i = 0;i<cells.size();++i){
			cells[i]->draw(window);
	}
}

void Field::set_mines(int count)
{
	hidden_mines = count;

	srand((unsigned)time(0));
	int rand_cell;

	while (count > 0) {
		rand_cell = rand() % cells.size();



		if (!cells[rand_cell]->is_mine()) {
			
			cells[rand_cell]->set_mine();
			
			//std::cout << "\n\nMine set on: "<< rand_cell <<"\nMore: " << count;
			add_mine_count(rand_cell);

			--count;
		}
	}
	
}

void Field::add_mine_count(int cell)
{

	int collums_min = bool(cell / cells_collums_count) * -1;
	int collums_max = bool(cell / cells_collums_count != cells_collums_count - 1) * 1;
	int line_min = bool(cell % cells_collums_count) * -1;
	int line_max = bool(cell % cells_collums_count != cells_collums_count - 1) * 1;

	int next_cell;

	for (int j = collums_min; j <= collums_max; ++j)
	{
		for (int i = line_min; i <= line_max; ++i) {
			next_cell = (cell + j * cells_collums_count + i);
			if (next_cell >= 0 && next_cell < cells.size()) {
				cells[next_cell]->new_mine_near();
				//std::cout << "\nNew Mine Near: " << next_cell;
			}
		}
	}
}

bool Field::click(sf::Vector2i mouse_pos, bool mouse_flag)
{
	float gabarite_x = sprite_x + indent,
		gabarite_x_max = sprite_x + indent + cell_size * cells_collums_count - 1,
		gabarite_y = sprite_y + indent,
		gabarite_y_max = sprite_y + indent  + cell_size * cells_collums_count - 1;

	//std::cout << "\n\nMouse_pos: " << mouse_pos.x << ' ' << mouse_pos.y
	//	<< "\nGabatite_x: " << gabarite_x << ' ' << gabarite_x_max
	//	<< "\nGabarite_y: " << gabarite_y << ' ' << gabarite_y_max;

	if (mouse_pos.x < gabarite_x
		|| mouse_pos.y < gabarite_y
		|| mouse_pos.x > gabarite_x_max
		|| mouse_pos.y > gabarite_y_max){
		//std::cout << "\nRETURN ";
		return true;
	}

	MineCell& cell = find_cell_under_mouse(mouse_pos);

	//std::cout << "\nCell_x_max: " << cell.get_x() + cell_size
	//	<< "\nCell_y_max: " << cell.get_y() + cell_size;

	return open_cell(cell,mouse_flag);

}

void Field::open_all_mines()
{
	for (MineCell* cell : cells) {
		if (cell->is_flag() && cell->is_mine()) {
			cell->set_flag();
		}
		if (cell->is_mine()) open_cell(*cell, false);
	}
}

void Field::reset(int difficulty)
{
	create_cells(difficulty * 8);
}

MineCell& Field::find_cell_under_mouse(sf::Vector2i mouse_pos)
{


	int i = (mouse_pos.x - sprite_x - indent - 1) / cell_size,
		j =  (mouse_pos.y - sprite_y - indent - 1) / cell_size;
	
	MineCell& cell = *cells[i * cells_collums_count + j];
	
	//std::cout << "\nFind cell:" << i * cells_collums_count + j;
	
	return cell;


}

bool Field::open_cell(MineCell& cell,bool flag)
{
	if (cell.is_open()) return true;

	if (flag) {
		
		if (cell.set_flag()) {
			cell.set_texture_pos({ 792,0 });
			--hidden_mines;
		}
		else {
			cell.set_texture_pos({ 0,0 });
			++hidden_mines;

		}
		//std::cout <<'\n' << hidden_mines;
		return true;
	}

	if (cell.is_flag()) return true;
	
	if (cell.is_mine()) {

		cell.set_texture_pos({ 72,0 });
		return false;
	}
	else {
		cell.set_texture_pos({ 72 * (cell.get_mines_near()+2),0 });
		cell.open_this_cell();
		--hidden_cells;



		if (!cell.get_mines_near()) {
			int pos;
			for (int i = 0; i < cells.size(); ++i) {
				if (cells[i] == &cell) pos = i;
			}
			int collums_min = bool(pos / cells_collums_count) * -1,
				collums_max = bool(pos / cells_collums_count != cells_collums_count-1) * 1,
				line_min = bool(pos % cells_collums_count) * -1,
				line_max = bool(pos % cells_collums_count != cells_collums_count-1) * 1;

			int next_cell;
			for (int j = collums_min; j <= collums_max; ++j)
			{
				for (int i = line_min; i <= line_max; ++i) {
					next_cell = (pos + j * cells_collums_count + i);
					if (next_cell >= 0 && next_cell < cells.size()) {
						safe_open_cell(*cells[next_cell]);
					}
				}
			}
		}
		
	}

	return true;
}

void Field::safe_open_cell(MineCell& cell)
{
	if (cell.is_mine()) return;
	open_cell(cell, false);
}

void Field::create_cells(int count)
{
	for (int i = 0; i < cells.size(); ++i) delete cells[i];
	cells.clear();
	cells_collums_count = count;
	total_cells = count * count;
	hidden_cells = total_cells - total_cells * 0.2 + 1;
	cells.reserve(count);
	cell_size = sprite_size  / count ;
	indent = (sprite_size - cell_size * count)/2;


	for(int i = 0; i <count;++i)
		for (int j = 0; j < count; ++j)
		{
			MineCell* cell = new MineCell( sprite_x  + indent  +  cell_size * i , sprite_y + indent  + cell_size * j, cell_size  , "defolt.png");
			cells.push_back(cell);
		}


	set_mines((total_cells) * 0.2);

}




//OTHER
Field::Field(std::pair<float, float> position, int size, std::string field_texture, int level)
{
	set_sprite_coords(position);
	set_sprite_size(size);
	set_texture(field_texture);

	create_cells(level * 8);


}


