#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace sf;
class CustomShape : public sf::Drawable, public sf::Transformable
{
public:
	CustomShape(float radius, int points);
	CustomShape(float radius, int points, Color color);
	void setSize(float radius);
	void setFillColor(Color color);
	bool load(float radius, int points);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float getSize();
	vector<Vector2f> getPolygonPoints();
	int getPointCount();
	Vector2f getPosition();
	~CustomShape();
private:
	const float PI = 3.141592654f;
	//Vector2f m_position = { 0,0 };
	float mRadius;
	VertexArray m_vertices;
	Texture m_tileset;
};