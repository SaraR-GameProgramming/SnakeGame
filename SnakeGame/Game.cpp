#include "Game.h"

#include <iostream>

// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Snake.h"


void Game::Start()
{
	// All SFML types and functions are contained in the sf namespace

   // Create an instance of the SFML RenderWindow type which represents the display
   // and initialise its size and title text
	sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Snake ICA : V8250114");
	// We can still output to the console window
	std::cout << "SnakeGame: Starting" << std::endl;

	//game walls, wall pos and colour
	sf::RectangleShape topWall (sf::Vector2f ( 800, 20));
	sf::RectangleShape bottemWall(sf::Vector2f( 800, 20));
	sf::RectangleShape leftWall(sf::Vector2f(20, 600));
	sf::RectangleShape rightWall(sf::Vector2f(20, 600));
	bottemWall.setPosition(0.0f, 580.0f);
	rightWall.setPosition(780.0f, 0.0f);
	topWall.setFillColor(sf::Color::Red);
	bottemWall.setFillColor(sf::Color::Red);
	leftWall.setFillColor(sf::Color::Red);
	rightWall.setFillColor(sf::Color::Red);

	std::vector<Snake*> snakes;

	// stores the Snake class in a vector so we can create many
	for (int i = 0; i < 1; i++)
	{
		sf::Vector2f pos;
		pos.x = (float)(rand() % 39 * 20);
		pos.y = (float)(rand() % 29 * 20);
		snakes.push_back(new Snake(pos, sf::Color::Green));

	}

	sf::Clock clock;

	// Main loop that continues until we call window.close()
	while (window.isOpen())
	{
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					snakes.front()->ChangeDirection(Edir::eWest);
					break;
				case sf::Keyboard::W:
					snakes.front()->ChangeDirection(Edir::eNorth);
					break;
				case sf::Keyboard::D:
					snakes.front()->ChangeDirection(Edir::eEast);
					break;
				case sf::Keyboard::S:
					snakes.front()->ChangeDirection(Edir::eSouth);
					break;
				default:
					break;
				}
			default:
				break;
			}
		}


		//SIM
		for (Snake* s : snakes)
		{

			s->Update();
			// collision with other snakes
			for (size_t i = 0; i < snakes.size() - 1; i++)
			{
				for (size_t j = i + 1; j < snakes.size(); j++)
				{
					if (snakes[i]->CheckCollision(*snakes[j]))
					{

						std::cout << "collision has happend with another snake" << std::endl;
						std::cout << "GameOver" << std::endl;
						window.close();


					}

				}
			
				
			}
			// this is self collision detection
			for (size_t i = 0; i <  snakes.size() ; i++)
			{
				if (snakes[i]->CheckSelfCollision(*snakes[i]))
				{
					std::cout << "snake has collided with self" << std::endl;
					std::cout << "GameOver" << std::endl;
					window.close();
				}
			}
			
			if (s->CheckCollisionWall())
			{
				window.close();
			}
				
			

			for (size_t i = 0; i < 5; i++)
			{
				if (s->SnakeEat(m_food[i]))
				{
					sf::Vector2f pos;
					std::cout << "snake has eaten" << std::endl;
					pos.x = (float)(rand() % 39 * 20);
					pos.y = (float)(rand() % 29 * 20);
					m_food[i].Spawn(pos);
					break;
				}
			}
		}
		if (rand() % 10 == 5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (!m_food[i].IsAlive())
				{
					sf::Vector2f pos;

					pos.x = (float)(rand() % 39 * 20);
					pos.y = (float)(rand() % 29 * 20);
					m_food[i].Spawn(pos);
					break;
					
				}

			}
		}



			// VISUAL
			// We must clear the window each time around the loop
			window.clear();

			// walls being rendered to become visual
			window.draw(topWall);
			window.draw(bottemWall);
			window.draw(leftWall);
			window.draw(rightWall);

			for (Snake* s : snakes)


				s->Render(window);

			{
				for (int i = 0; i < 5; i++)
				{


					if (m_food[i].IsAlive())
						m_food[i].Render(window);
				
				}

			}


			// Get the window to display its contents
			window.display();
			while (clock.getElapsedTime().asMilliseconds() < 100);
			clock.restart();

		

	}
	
	
		std::cout << "SnakeGame: Finished" << std::endl;

		for (Snake* s : snakes)
			delete s;
		// destroys snake when the program ends
	
}

