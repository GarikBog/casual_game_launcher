#ifndef MINE_CELL
#include"mine_cell.hpp"
#define MINE_CELL
#endif // !MineCell


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

//SETTERS
void MineCell::set_pos(float new_x, float new_y)
{
	this->x = new_x;
	this->y = new_y;

	sprite.setPosition(x, y);
}

void MineCell::set_pos(std::pair<float, float> new_coords)
{
	x = new_coords.first, y = new_coords.second;

	sprite.setPosition(x, y);
}

void MineCell::set_scale(float scale)
{
	sprite.setScale({
		scale / sprite.getLocalBounds().width,
		scale / sprite.getLocalBounds().height
		});
}

void MineCell::set_texture_size(int size)
{
	this->size = size;

	sprite.setTextureRect({ texture_file_pos_x,texture_file_pos_y,size,size });
}

void MineCell::set_texture_pos(std::pair<int, int> pos)
{
	this->texture_file_pos_x = pos.first, this->texture_file_pos_y = pos.second;

	sprite.setTextureRect({ texture_file_pos_x ,texture_file_pos_y,size,size });
}

void MineCell::set_texture(std::string texture)
{
	this->texture.loadFromFile("textures/cells/"+texture);
	sprite.setTexture(this->texture);
}

bool MineCell::set_flag()
{
	flag? flag = false : flag = true;
	return flag;
}



//GETTERS
std::pair<float, float> MineCell::get_coords() const
{
	return {x,y};
}

double MineCell::get_x() const
{
	return x;
}

double MineCell::get_y() const
{
	return y;
}

int MineCell::get_size() const
{
	return sprite.getLocalBounds().width;
}

int MineCell::get_mines_near() const
{
	return mines_near;
}




//TECH
void MineCell::new_mine_near()
{
	
	mines_near += 1;
}

void MineCell::open_this_cell()
{
	this->open = true;
}

bool MineCell::is_open()
{
	return open;
}

void MineCell::set_mine()
{
	mine = true;

}

bool MineCell::is_mine()
{
	return mine;
}

bool MineCell::is_flag()
{
	return flag;
}

void MineCell::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}



//OTHER
MineCell::MineCell(float x, float y, int scale, std::string texture)
{
	set_pos(x, y);
	set_texture(texture);
	set_texture_size(72);
	set_scale(scale);

}

