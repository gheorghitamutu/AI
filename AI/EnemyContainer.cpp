#include "EnemyContainer.h"


EnemyContainer::EnemyContainer()
{
	Enemy* e1 = new Enemy(new sf::CircleShape(50.f, 6));
	e1->setFillColor(sf::Color::Red);
	e1->setOrigin({ e1->getRadius(), e1->getRadius() });
	e1->setPosition({ (float)(800 / 2), (float)(600 / 2) });

	Enemy* e2 = new Enemy(new sf::CircleShape(50.f, 5));
	e2->setFillColor(sf::Color::Blue);
	e2->setOrigin({ e1->getRadius(), e1->getRadius() });
	e2->setPosition({ (float)(800 / 2 + 100), (float)(600 / 2) });

	AddEnemy(e1);
	AddEnemy(e2);
}

void EnemyContainer::AddEnemy(Enemy * enemy)
{
	this->enemies.emplace_back(enemy);
}

void EnemyContainer::DrawEnemies(RenderWindow * window)
{
	for (auto& enemy : this->enemies)
	{
		enemy->draw(window);
	}
}

vector<Shape*> EnemyContainer::GetShapeType()
{
	vector<Shape*> shapes;
	for (auto& enemy : this->enemies)
	{
		shapes.emplace_back(enemy->GetShapeType());
	}
	return shapes;
}


EnemyContainer::~EnemyContainer()
{
}
