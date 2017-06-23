#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>

using namespace std;
using namespace sf;

class Character : public CircleShape, public RectangleShape, public ConvexShape
{
public:
	Character(Shape* shapeType);
	bool intersects(Shape* shapeType);
	bool intersects(vector<Shape*> shapeType);
	void setFillColor(Color color);
	void setPosition(Vector2f position);
	void setOrigin(Vector2f position);
	float getRadius();
	void draw(RenderWindow* window);
	void Update();
	void SetVelocity(Vector2f direction);
	Shape* GetShapeType();
	~Character();

protected:
	Shape* mShapeType;
	float mRadius;
	Vector2f mVelocity;
	Vector2f mDirection;
	float mSpeed;
	sf::Clock time;
	float mDeltaTime = 0.0f;
	bool mCollision = false;
private:
	bool isInside(vector<Vector2f> polygon, Vector2f point);
	bool doIntersect(Vector2f p1, Vector2f q1, Vector2f p2, Vector2f q2);
	bool onSegment(Vector2f p, Vector2f q, Vector2f r);
	int orientation(Vector2f p, Vector2f q, Vector2f r);

};

