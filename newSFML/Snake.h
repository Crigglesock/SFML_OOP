#ifndef WINDOW

#include"SFML/include/SFML/Window.hpp"
#include"SFML/include/SFML/Graphics.hpp"
#include <string>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};




#endif