
#ifndef OBJECTS
#include "../objects.hpp"
#define OBJECTS
#endif // !OBJECTS



class RestartButton : public ClickableObject {
public:

	bool click(sf::Vector2i mouse_pos);


	RestartButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);
};


class PointsCounter : public CounterObject {

private:
	int points = 0;


public:

	//TECH
	void update() override;
	void add_point();
	void nullify();

	PointsCounter(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
};