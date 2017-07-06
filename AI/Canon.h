#pragma once
#include <SFML/Graphics.hpp>
#include "MovableShape.h"
using namespace sf;

class Canon : public MovableShape
{
public:
	Canon(CustomShape * shapeType) : MovableShape(shapeType) {};
	void DrawCanon(RenderWindow* window);

	~Canon();
private:
};

