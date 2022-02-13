#include "Circle.h"

void Circle::Render(sf::RenderWindow& window)
{
	c.setRadius(radius);
	c.setPosition(position);
	c.setFillColor(colour);
	window.draw(c);
}

Circle::Circle(sf::Vector2f pos, sf::Color col, float r):
	//position(pos),
	//colour(col),
	radius(r)
{
	
}
