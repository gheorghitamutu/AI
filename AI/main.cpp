#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "EnemyContainer.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "AI");
	Player p1(new sf::CircleShape(50.f, 4));
	p1.setFillColor(sf::Color::Green);
	p1.setOrigin({ p1.getRadius(), p1.getRadius() });
	p1.setPosition({ (float)(window.getSize().x / 2-200), (float)(window.getSize().y / 2) });

	Enemy e1(new sf::CircleShape(50.f, 6));
	e1.setFillColor(sf::Color::Red);
	e1.setOrigin({ p1.getRadius(), p1.getRadius() });
	e1.setPosition({ (float)(window.getSize().x / 2), (float)(window.getSize().y / 2) });

	Enemy e2(new sf::CircleShape(50.f, 5));
	e2.setFillColor(sf::Color::Blue);
	e2.setOrigin({ p1.getRadius(), p1.getRadius() });
	e2.setPosition({ (float)(window.getSize().x / 2+100), (float)(window.getSize().y / 2) });

	EnemyContainer enemies;
	enemies.AddEnemy(&e1);
	enemies.AddEnemy(&e2);

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