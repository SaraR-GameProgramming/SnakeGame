#include "Snake.h"
#include "Collectables.h"
#include <iostream>


Snake::Snake(sf::Vector2f pos, sf::Color col): m_Col (col)
{
	m_seg.push_front(pos);
	m_direction = (Edir)(rand() % 4);

}

void Snake::ChangeDirection(Edir newDirection)
{
	m_direction = newDirection;
}

void Snake::Render(sf::RenderWindow& window)
{
	sf::RectangleShape body(sf::Vector2f(20,20));

	body.setFillColor(m_Col);
	for (sf::Vector2f pos : m_seg)
	{
		body.setPosition(pos);

		window.draw(body);
	}
}

// checking if the snake hits another snake
bool Snake::CheckCollision(Snake& other)
{

	for (auto& otherSeg : other.m_seg)
	if (m_seg.front() == otherSeg)
	{
		return true;

	}
	return false;
}

// checking if the snake and food are colliding and assigining a growsize to the snake
bool Snake::SnakeEat(food& m_food)
{
	if (m_seg.front() == m_food.GetPos())
	{
		m_growSize = 5;
		return true;
	}
	return false;
}
// checks if snake is touching any segment of itself not including the head
bool Snake::CheckSelfCollision(Snake& self)
{
	auto Seg = m_seg.begin();
	Seg++;
	for (; Seg != m_seg.end(); Seg++)
	{
		if (m_seg.front() == *Seg) 
		{
			return true;
		}
	
	}
	return false;
}
// checks if the snake has hit the wall 
bool Snake::CheckCollisionWall()
{
	if (m_seg.front().x < 20|| m_seg.front().x > 780 || m_seg.front().y < 20 || m_seg.front().y > 580)
	{
		std::cout << "snake hit a wall" << std::endl;
		std::cout << "GameOver" << std::endl;
		return true;
	}
	return false;
}

void Snake::Update()// is for Moveing the snake
{
	sf::Vector2f pos = m_seg.front();

	switch (m_direction)
	{
	case Edir::eNorth:
		pos.y-= 20/2,20/2;
		break;
	case Edir::eEast:
		pos.x += 20/2, 20/2;
		break;
	case Edir::eSouth:
		pos.y += 20/2, 20/2;
		break;
	case Edir::eWest:
		pos.x -= 20/2, 20/2;
		break;
	default:
		break;
	}

	m_seg.push_front(pos);
	if (m_growSize == 0)
	{
		m_seg.pop_back();
	}
	else
	m_growSize--;
	
}