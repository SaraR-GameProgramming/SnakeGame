#pragma once
#include <SFML/Graphics.hpp>



class Shape
{
protected:
	sf::Vector2f position;
	sf::Color colour;
public:
	virtual void  Render(sf::RenderWindow& window)=0;

	Shape(sf::Vector2f pos, sf::Color col);
};

