#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "CustomShape.h"
using namespace std;
using namespace sf;

class MovableShape : public CustomShape
{
public:
	MovableShape(CustomShape* shapeType);
	void setFillColor(Color color);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void setOrigin(Vector2f position);
	void draw(RenderWindow* window);
	void Update();
	void SetVelocity(Vector2f direction);
	void SetSpeed(float speed);
	void AddCanon(class Canon* canon);
	float getRadius();
	bool intersects(CustomShape* shapeType, RenderWindow* window);
	bool intersects(vector<CustomShape*> shapeType, RenderWindow* window);
	void drawIntersectionPoints(RenderWindow* window, vector<Vector2f> shapePointPosition);
	CustomShape* GetShapeType();
	~MovableShape();

protected:
	vector<class Canon*> mCanons;
	CustomShape* mShapeType;
	Vector2f mVelocity;
	Vector2f mDirection;
	sf::Clock time;
	float mDeltaTime = 0.0f;
	float mSpeed;
	bool mCollision = false;
	const float PI = 3.141592654f;
private:
	bool isInside(vector<Vector2f> polygon, Vector2f point);
	bool doIntersect(Vector2f p1, Vector2f q1, Vector2f p2, Vector2f q2);
	bool onSegment(Vector2f p, Vector2f q, Vector2f r);
	int orientation(Vector2f p, Vector2f q, Vector2f r);

};

