#include "EnemyContainer.h"


EnemyContainer::EnemyContainer()
{
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
