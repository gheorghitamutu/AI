#pragma once
#include "MovableShape.h"
class Enemy :
	public MovableShape
{
public:
	Enemy(CustomShape* shapeType) : MovableShape(shapeType) {};
	~Enemy();
};

