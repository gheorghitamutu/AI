#pragma once
#include "MovableShape.h"
class Enemy :
	public MovableShape
{
public:
	Enemy(Shape* shapeType, float radius) : MovableShape(shapeType, radius) {};
	~Enemy();
};

