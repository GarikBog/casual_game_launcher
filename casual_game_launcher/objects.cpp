#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



// OBJECT
Object::Object() {}



void Object::set_pos(std::pair<float, float> pos)
{
	x = pos.first;
	y = pos.second;

	sprite.setPosition({ x,y });
}

void Object::set_pos(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_x(float x)
{

	this->x = x;

	sprite.setPosition({ x,y });
}

void Object::set_y(float y)
{

	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_scale(std::pair<int, int> size)
{
	width = size.first;
	height = size.second;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_scale(int width, int height)
{
	this->width = width;
	this->height = height;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_width(int width)
{
	this->width = width;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_height(int height)
{
	this->height = height;

	std::cout << sprite.getLocalBounds().width << ' ' << sprite.getLocalBounds().height;
	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_texture(std::string texture_file)
{	
	this->texture_file = texture_file;
	if (!texture.loadFromFile("textures/objects/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
		this->texture_file = "textures/tech/error.jpg";
	}
	
	sprite.setTexture(texture);
}

void Object::set_texture_rect(sf::IntRect rect)
{

	sprite.setTextureRect(rect);
}

std::string Object::get_texture() const
{
	return texture_file;
}

std::pair<float, float> Object::get_pos() const
{
	return {x,y};
}

float Object::get_x() const
{
	return x;
}

float Object::get_y() const
{
	return y;
}

sf::FloatRect Object::get_collision() const
{
	return sprite.getGlobalBounds();
}

std::pair<int, int> Object::get_scale() const
{
	return {width,height};
}

int Object::get_width() const
{
	return width;
}

int Object::get_height() const
{
	return height;
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

}

Object::Object(std::pair<float, float> pos,std::pair<int,int> size, std::pair<int, int> scale, std::string texture_file)
{
	set_pos(pos);
	set_texture_rect({ 0,0,size.first,size.second });
	set_scale(scale);
	set_texture(texture_file);

}
// OBJECT




//ClickableObject
bool ClickableObject::click(sf::Vector2i mouse_pos)
{
	//std::cout << "\n\tMOUSE_POS\n" << "\t " << mouse_pos.x<<' '<<mouse_pos.y;
	//std::cout << "\nX: " << x;
	//std::cout << "\nW: " << x + sprite.getGlobalBounds().width;
	//std::cout << "\nY: " << y;
	//std::cout << "\nH: " << y + sprite.getGlobalBounds().height;

	return (
		mouse_pos.x > x &&
		mouse_pos.x < x + sprite.getGlobalBounds().width &&
		mouse_pos.y > y &&
		mouse_pos.y < y + sprite.getGlobalBounds().height
		);
}

ClickableObject::ClickableObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,Log& log): 
	Object(pos,size,scale,texture_file),
	log(log)
{
	
}
//ClickableObject




//CounterObject
void CounterObject::set_pos(std::pair<float, float> pos)
{
	x = pos.first;
	y = pos.second;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });

}

void CounterObject::set_pos(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_x(float x)
{

	this->x = x;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_y(float y)
{

	this->y = y;

	sprite.setPosition({ x,y });
	left_cell.setPosition({ x,y });
	middle_cell.setPosition({ x + width / 3,y });
	right_cell.setPosition({ x + width * 2 / 3,y });
}

void CounterObject::set_scale(std::pair<int, int> size)
{
	width = size.first;
	height = size.second;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_scale(int width, int height)
{
	this->width = width;
	this->height = height;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_width(int width)
{
	this->width = width;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_height(int height)
{
	this->height = height;

	float local_width = sprite.getLocalBounds().width, local_height = sprite.getLocalBounds().height;
	sprite.setScale({
		width / local_width,
		height / local_height });

	left_cell.setScale({
		width / local_width,
		height / local_height });


	middle_cell.setScale({
		width / local_width,
		height / local_height });

	right_cell.setScale({
		width / local_width,
		height / local_height });
}

void CounterObject::set_texture(std::string texture_file)
{
	if (!texture.loadFromFile("textures/objects/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
	}

	sprite.setTexture(texture);
	left_cell.setTexture(texture);
	middle_cell.setTexture(texture);
	right_cell.setTexture(texture);

}
void CounterObject::set_texture_rect(sf::IntRect rect)
{
	Object::set_texture_rect(rect);

	left_cell.setTextureRect({ 0,0,20,35 });
	middle_cell.setTextureRect({ 0,0,20,35 });
	right_cell.setTextureRect({ 0,0,20,35 });

}

void CounterObject::draw(sf::RenderWindow& window)
{
	update();
	Object::draw(window);
	window.draw(left_cell);
	window.draw(middle_cell);
	window.draw(right_cell);

}


CounterObject::CounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file)
{
	set_texture(texture_file);
	set_texture_rect({ 0,0,size.first,size.second });
	set_scale(scale);
	set_pos(pos);

}

//CounterObject

// CLOSE button
bool CloseButton::click(sf::Vector2i mouse_pos)
{
	if (!ClickableObject::click(mouse_pos)) return false;

	log.add({ "CLOSE" });

	return true;
}


CloseButton::CloseButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log):
	ClickableObject(pos,size,scale,texture_file,log)
{

}
// Close button


void Base_counter::set_score(unsigned int count)
{
	score = count;
	score_change = true;
}

int Base_counter::get_score() const
{
	return score;
}

void Base_counter::add_point()
{
	++score;
	score_change = true;

}

void Base_counter::remove_point()
{

	--score;
	score_change = true;



}

void Base_counter::reset()
{
	score = 0;
	right_cell.setTextureRect({ 60 ,0,20,35 });
	middle_cell.setTextureRect({ 60 ,0,20,35 });
	left_cell.setTextureRect({ 60 ,0,20,35 });
}

void Base_counter::update()
{

	if (score > 998 || !score_change || score < 0) return;
	//std::cout << point_change << '\t' << "CHANGE!\n";
	score_change = false;

	right_cell.setTextureRect({ 60 + (score % 10) * 20,0,20,35 });

	if (score < 9) return;

	middle_cell.setTextureRect({ 60 + ((score / 10) % 10) * 20,0,20,35 });

	if (score < 99) return;

	left_cell.setTextureRect({ 60 + ((score / 100) % 10) * 20,0,20,35 });


}

Base_counter::Base_counter(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file) :
	CounterObject(pos, size, scale, texture_file)
{
}
