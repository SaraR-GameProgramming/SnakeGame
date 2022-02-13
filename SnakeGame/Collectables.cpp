#include "Collectables.h"
void food::Render(sf::RenderWindow& window)
{
	sf::RectangleShape food(sf::Vector2f(20, 20));

	food.setFillColor(sf::Color::Yellow);
	food.setPosition(m_Pos);
	window.draw(food);
	
}

void food::Spawn(sf::Vector2f pos)
{
	m_Pos = pos;
	gameScore = 20;
	f_alive = true;
}

sf::Vector2f food::GetPos()
{
	return sf::Vector2f(m_Pos);
}

