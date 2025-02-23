#ifndef TECHIESOBJECTS
#include "techiesObjects.hpp"
#define TECHIESOBJECTS
#endif // !TECHIESOBJECTS


// MinesCounterObject
void MinesCounterObject::set_mines(unsigned int count)
{
	//std::cout << "\nMines: " << count;
	mines = count;
	mine_change = true;
}

int MinesCounterObject::get_mines() const
{
	return mines;
}

void MinesCounterObject::add_mine()
{
	//std::cout << "\nMine_Add\n";
	++mines;
	mine_change = true;
	//std::cout << "\nMines: " << mines;
}

void MinesCounterObject::remove_mine()
{

	--mines;
	mine_change = true;

	//std::cout << "\nMine_Remove\n";

}

void MinesCounterObject::reset()
{
	mines = 0;
	right_cell.setTextureRect({ 60 ,0,20,35 });
	middle_cell.setTextureRect({ 60 ,0,20,35 });
	left_cell.setTextureRect({ 60 ,0,20,35 });
}

void MinesCounterObject::update()
{

	if (mines > 998 || !mine_change || mines < 0) return;
	//std::cout << mine_change << '\t' << "CHANGE!\n";
	mine_change = false;

	right_cell.setTextureRect({ 60 + (mines % 10) * 20,0,20,35 });

	if (mines < 9) return;

	middle_cell.setTextureRect({ 60 + ((mines / 10) % 10) * 20,0,20,35 });

	if (mines < 99) return;

	left_cell.setTextureRect({ 60 + ((mines / 100) % 10) * 20,0,20,35 });


}

MinesCounterObject::MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file) : 
	CounterObject(pos, size, scale, texture_file)
{
}

MinesCounterObject::MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int mines) : 
	MinesCounterObject(pos, size, scale, texture_file)
{
	set_mines(mines);
}

//MinesCounterObject


//TimerObject
void TimerObject::set_seconds(unsigned int extra_time)
{
	this->extra_time = extra_time;
	seconds += extra_time;
}

unsigned int TimerObject::get_seconds() const
{
	return seconds;
}

void TimerObject::reset()
{
	extra_time = 0;
	seconds = 0;
	timer.restart();
	update();
	right_cell.setTextureRect({ 60 ,0,20,35 });
	middle_cell.setTextureRect({ 60 ,0,20,35 });
	left_cell.setTextureRect({ 60 ,0,20,35 });
}
void TimerObject::start()
{
	run = true;
}

void TimerObject::stop()
{
	run = false;
}

void TimerObject::update()
{

	if (seconds > 998 || !run) return;

	if (seconds != int(timer.getElapsedTime().asSeconds()) + extra_time) {
		//std::cout <<seconds<<'\t' << "UPDATED!\n";
		seconds = int(timer.getElapsedTime().asSeconds()) + extra_time;

		right_cell.setTextureRect({ 60 + (seconds % 10) * 20,0,20,35 });

		if (seconds < 10) return;

		middle_cell.setTextureRect({ 60 + ((seconds / 10) % 10) * 20,0,20,35 });

		if (seconds < 100) return;

		left_cell.setTextureRect({ 60 + ((seconds / 100) % 10) * 20,0,20,35 });

	}
}

TimerObject::TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file) : CounterObject(pos, size, scale, texture_file) {
	reset();
}
TimerObject::TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int extra_time) :TimerObject(pos, size, scale, texture_file)
{
	set_seconds(extra_time);
}
//TimerObject



// BUTTON
bool Button::click(sf::Vector2i mouse_pos)
{
	return ClickableObject::click(mouse_pos);
}

Button::Button(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log):
	ClickableObject(pos,size,scale,texture_file,log)
{
}
// BUTTON