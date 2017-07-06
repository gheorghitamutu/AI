#include "CustomShape.h"

CustomShape::CustomShape()
{
}

CustomShape::CustomShape(float radius, int points)
{
	load(radius, points);
}

CustomShape::CustomShape(float radius, int points, Color color)
{
	load(radius, points);

}

void CustomShape::setSize(float radius)
{
	mRadius = radius;
}

void CustomShape::setFillColor(Color color)
{
	for (int i = 0; i<m_vertices.getVertexCount(); i++)
	{
		m_vertices[i].color = color;
	}
}

bool CustomShape::load(float radius, int points)
{
	mRadius = radius;
	m_vertices.setPrimitiveType(TriangleFan);
	// [0] - origin, [size-1] - same point with [1] but we need to close the polygon
	m_vertices.resize(points + 2);

	// define the position of the polygon's points
	m_vertices[0].position = { 0,0 };
	for (int i = 1; i<m_vertices.getVertexCount(); i++)
	{
		m_vertices[i].position =
			Vector2f({ (float)(int)(radius * cos(2 * PI * (i - 1) / (m_vertices.getVertexCount() - 2))),
			(float)(int)(radius *sin(2 * PI * (i - 1) / (m_vertices.getVertexCount() - 2))) });
	}

	// define the color of the polygon's points
	setFillColor(Color(255, 255, 255));
	Transformable::setOrigin(mRadius, mRadius);
	return true;
}

void CustomShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	//states.texture = ;

	// draw the vertex array
	target.draw(m_vertices, states);
}

float CustomShape::getSize()
{
	return mRadius;
}

vector<Vector2f> CustomShape::getPolygonPoints()
{
	vector<Vector2f> polygonPoint;
	for (int i = 1; i < m_vertices.getVertexCount() - 1; i++)
	{
		polygonPoint.emplace_back(m_vertices[i].position);
	}
	return polygonPoint;
}

int CustomShape::getPointCount()
{
	return m_vertices.getVertexCount() - 1;
}

Vector2f CustomShape::getPosition()
{
	return Transformable::getPosition() - Vector2f(mRadius, mRadius);
}

CustomShape::~CustomShape()
{
}