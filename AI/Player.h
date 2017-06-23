#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(Shape* shapeType) : Character(shapeType) { mSpeed = 100; };
	void HandleInput(Event event);
	void checkCollision(vector<Shape*> shapeType);
	~Player();
private:
};

