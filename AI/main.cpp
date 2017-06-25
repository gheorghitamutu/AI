#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "EnemyContainer.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "AI");
	Event event;
	Player p1({ new sf::CircleShape(50.f, 3), 50.f });

	EnemyContainer enemies;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		p1.HandleInput(event);
		p1.Update();
		enemies.DrawEnemies(&window);
		p1.draw(&window);
		p1.checkCollision(enemies.GetShapeType(), &window);
		window.display();
	}

	return 0;
}