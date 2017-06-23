#pragma once
#include "Enemy.h"
#include <vector>

class EnemyContainer
{
public:
	EnemyContainer();
	void AddEnemy(Enemy* enemy);
	void DrawEnemies(RenderWindow* window);
	vector<Shape*> GetShapeType();
	~EnemyContainer();
private:
	vector<Enemy*> enemies;
};

