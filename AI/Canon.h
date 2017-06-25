#pragma once
#include <SFML/Graphics.hpp>
#include "MovableShape.h"
using namespace sf;

class Canon : public MovableShape
{
public:
	Canon(Shape * shapeType, float radius) : MovableShape(shapeType, radius) {};
	void DrawCanon(RenderWindow* window);

	~Canon();
private:
};

