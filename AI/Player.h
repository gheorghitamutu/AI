#pragma once
#include "MovableShape.h"
#include "Canon.h"

class Player :
	public MovableShape
{
public:
	Player(Shape* shapeType, float radius);
	void HandleInput(Event event);
	void checkCollision(vector<Shape*> shapeType, RenderWindow* window);
	~Player();
private:
	float mIncreaseSpeedBy = 1.0f;
	bool mShiftPressed = false;
};

