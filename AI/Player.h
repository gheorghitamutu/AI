#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(Shape* shapeType);
	void HandleInput(Event event);
	void checkCollision(vector<Shape*> shapeType);
	~Player();
private:
	bool mShiftPressed = false;
	float mIncreaseSpeedBy = 1.0f;
};

