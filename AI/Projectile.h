#pragma once
#include "SFML\Graphics.hpp"
#include "MovableShape.h"
using namespace sf;
class Projectile :
	public MovableShape
{
public:
	Projectile(CustomShape * shapeType) : MovableShape(shapeType) {};
	~Projectile();
};

