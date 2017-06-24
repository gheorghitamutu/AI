#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "EnemyContainer.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "AI");
	Player p1(new sf::CircleShape(50.f, 4));

	EnemyContainer enemies;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		p1.checkCollision(enemies.GetShapeType());
		p1.HandleInput(event);
		p1.Update();
		enemies.DrawEnemies(&window);
		p1.draw(&window);
		window.display();
	}

	return 0;
}