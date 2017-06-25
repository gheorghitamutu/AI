#include "Canon.h"

void Canon::DrawCanon(RenderWindow * window)
{
	window->draw(*mShapeType);
}

Canon::~Canon()
{
}
