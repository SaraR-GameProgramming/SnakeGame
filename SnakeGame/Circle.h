#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"
class Circle:public Shape
{
private:
	sf::CircleShape c;
	//sf::Vector2f position;
	//sf::Color colour;
	float radius;

	
public:
	void Render(sf::RenderWindow& window);
	Circle(sf::Vector2f pos, sf::Color col, float r);
};

