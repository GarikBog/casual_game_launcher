

#ifndef OBJECTS
#include"..\objects.hpp"
#define OBJECTS
#endif // !OBJECTS




class Button : public ClickableObject {

public:
	bool click(sf::Vector2i mouse_pos) override;

	Button(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);

};





class TimerObject : public CounterObject {

private:
	bool run = false;
	unsigned int seconds = 0, extra_time = 0;

	sf::Clock timer;


public:

	//Setters
	void set_seconds(unsigned int extra_time);

	//Getters
	unsigned int get_seconds() const;


	//Tech & Other
	void reset();
	void start();
	void stop();
	void update();

	TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	TimerObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int extra_time);
};







class MinesCounterObject : public CounterObject {
private:

	int mines = 0;
	bool mine_change = false;

public:


	//Setters

	void set_mines(unsigned int count);

	//Getters
	int get_mines() const;

	//Tech
	void add_mine();
	void remove_mine();
	void reset();
	void update();


	MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	MinesCounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int mines);

};