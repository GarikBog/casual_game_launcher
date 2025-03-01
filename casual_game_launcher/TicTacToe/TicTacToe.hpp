#ifndef TTT_OBJECTS
#include"TTT_Objects.hpp"
#define TTT_OBJECTS
#endif // !TTT_OBJECTS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef GAME
#include "../game.hpp"
#define GAME
#endif // !GAME



class TicTacToe : public Game {


private:

	bool side = true;

	bool game_run = true;

	Log log;
	TTT_Field* field;
	CloseButton* close;
	TTT_Reset_Button* reset_button;
	Base_counter* cross_score_counter,*circle_score_counter;
	Object* end_game_text;

	void draw();

	void reset();

	void process_request(Request request);
	void process_log();

	void friendship_won();
	void cross_won();
	void circle_won();

public:

	void start() override;

	TicTacToe(int height);
	~TicTacToe() override;

};