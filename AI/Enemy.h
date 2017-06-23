#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(Shape* shapeType) : Character(shapeType) {};
	~Enemy();
};

