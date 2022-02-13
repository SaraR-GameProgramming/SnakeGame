#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

class Rectangle:public Shape
{
private:
	sf::RectangleShape rec;
	sf::Vector2f size;

	
	
public:
	void Render(sf::RenderWindow& window);
	Rectangle(sf::Vector2f pos, sf::Color col, sf::Vector2f size);
};

