#pragma once
#include "SFML\Graphics.hpp"
#include "MovableShape.h"
using namespace sf;
class Projectile :
	public MovableShape
{
public:
	Projectile(Shape * shapeType, float radius) : MovableShape(shapeType, radius) {};
	~Projectile();
};

