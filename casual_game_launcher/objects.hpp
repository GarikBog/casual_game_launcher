#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS


#ifndef LOG
#include"log.hpp"
#define LOG
#endif // !LOG

class Object {

protected:
	//Pos & size
	float x = 0, y = 0;
	int width = 0, height = 0;


	std::string texture_file;
	sf::Texture texture;
	sf::IntRect texture_rect;
	sf::Sprite sprite;


	Object();

public:
	//Setters
	void set_pos(std::pair<float, float> pos);
	void set_pos(float x, float y);
	void set_x(float x);
	void set_y(float y);

	void set_scale(std::pair<int, int> size);
	void set_scale(int width, int height);
	void set_width(int width);
	void set_height(int height);

	void set_texture(std::string texture_file);
	void set_texture_rect(sf::IntRect rect);

	//Getters
	std::string get_texture() const;
	std::pair<float, float> get_pos() const;
	float get_x() const;
	float get_y() const;
	sf::FloatRect get_collision() const;

	std::pair<int, int> get_scale() const;
	int get_width() const;
	int get_height() const;


	//Tech & other
	void draw(sf::RenderWindow& window);

	Object(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);
	



};


class ClickableObject : public Object {

protected:

	Log& log;

public:
	virtual bool click(sf::Vector2i mouse_pos);


	ClickableObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,Log& log);
};


class CounterObject : public Object {

protected:


	sf::Sprite left_cell, middle_cell, right_cell;


public:

	//Setters
	void set_pos(std::pair<float, float> pos);
	void set_pos(float x, float y);
	void set_x(float x);
	void set_y(float y);

	void set_scale(std::pair<int, int> size);
	void set_scale(int width, int height);
	void set_width(int width);
	void set_height(int height);

	void set_texture(std::string texture_file);
	void set_texture_rect(sf::IntRect rect);



	//Tech & other
	virtual void update() = 0;
	void draw(sf::RenderWindow& window);

	CounterObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);


};

//CLOSE BUTTON
class CloseButton : public ClickableObject {

public:
	bool click(sf::Vector2i mouse_pos) override;

	CloseButton(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, Log& log);

};
//CLOSE BUTTON


// Base_counter
class Base_counter : public CounterObject {
private:

	int score = 0;
	bool score_change = false;
public:


	//Setters

	void set_score(unsigned int count);

	//Getters
	int get_score() const;

	//Tech
	void add_point();
	void remove_point();
	void reset();
	void update() override;


	Base_counter(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file);

};
// Base_counter