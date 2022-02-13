#include "Shape.h"
#include "Rectangle.h"


void Rectangle::Render(sf::RenderWindow& window)
{
	
	rec.setPosition(position);
	rec.setFillColor(colour);
	rec.setOutlineColor(colour);
	rec.setSize(size);
	window.draw(rec);
}

Rectangle::Rectangle(sf::Vector2f pos, sf::Color col, sf::Vector2f size):

	//position(pos),
	//colour(col),
	size(size)
	
{

}
