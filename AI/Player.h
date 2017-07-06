#pragma once
#include "MovableShape.h"
#include "Canon.h"

class Player :
	public MovableShape
{
public:
	Player(CustomShape* shapeType);
	void HandleInput(Event event);
	void checkCollision(vector<CustomShape*> shapeType, RenderWindow* window);
	~Player();
private:
	float mIncreaseSpeedBy = 1.0f;
	bool mShiftPressed = false;
};

