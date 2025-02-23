#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef MINE_FIELD
#include"mine_field.hpp"
#define MINE_FIELD
#endif // !FIELD


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



#ifndef OBJECTS
#include "..\objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef GAME
#include "..\game.hpp"
#define GAME
#endif // !GAME

#ifndef TECHIESOBJECTS
#include "techiesObjects.hpp"
#define TECHIESOBJECTS
#endif // !TECHIESOBJECTS


class Techies: public Game{


private:
	Log log;
	int difficulty = 1;
	bool end = false,run = false;
	std::string name = "Techies";
	Field* field;
	TimerObject* timer;
	MinesCounterObject* mine_counter;
	Button *difficulty_button;

	std::vector<Object*> tmp_objects;
	std::vector<Button*> tmp_buttons;
	void draw();

	void restart();

public:

	void start() override;


	Techies(unsigned int height);
	~Techies();
};