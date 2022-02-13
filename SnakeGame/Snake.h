#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Collectables.h"
enum class Edir
{
	eNorth,
	eEast,
	eSouth,
	eWest
};

class Snake
{
private:
	std::list<sf::Vector2f> m_seg;
	int m_growSize{ 0 };
	sf::Color m_Col;
	Edir m_direction{ Edir::eNorth };

public:
	
	Snake(sf::Vector2f pos, sf::Color col);
	void ChangeDirection(Edir newDirection);
	void Update();
	void Render(sf::RenderWindow& window);
	bool CheckCollision(Snake& other);
	bool SnakeEat(food& m_food);
	bool CheckSelfCollision(Snake& self);
	bool CheckCollisionWall();
};
