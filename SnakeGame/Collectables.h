#pragma once
#include <SFML/Graphics.hpp>
class food
{
private:
	sf::Vector2f m_Pos;
	int gameScore{ 0 };
	bool f_alive{ false };
	// f_alive is if the food is showing or not
public:
	bool IsAlive() const { return f_alive; }
	void Render(sf::RenderWindow& window);
	void Spawn(sf::Vector2f pos);
	sf::Vector2f GetPos();
};

