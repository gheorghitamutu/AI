#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
using namespace std;
using namespace sf;

class MovableShape : public CircleShape, public RectangleShape, public ConvexShape
{
public:
	MovableShape(Shape* shapeType, float radius);
	void setFillColor(Color color);
	void setPosition(Vector2f position);
	void setOrigin(Vector2f position);
	void draw(RenderWindow* window);
	void Update();
	void SetVelocity(Vector2f direction);
	void SetSpeed(float speed);
	void AddCanon(class Canon* canon);
	float getRadius();
	bool intersects(Shape* shapeType, RenderWindow* window);
	bool intersects(vector<Shape*> shapeType, RenderWindow* window);
	void drawRandomShit(RenderWindow* window, vector<Vector2f> shapePointPosition);
	Shape* GetShapeType();
	~MovableShape();

protected:
	vector<class Canon*> mCanons;
	Shape* mShapeType;
	Vector2f mVelocity;
	Vector2f mDirection;
	sf::Clock time;
	float mDeltaTime = 0.0f;
	float mSpeed;
	float mRadius;
	bool mCollision = false;
	const float PI = 3.141592654f;
private:
	bool isInside(vector<Vector2f> polygon, Vector2f point);
	bool doIntersect(Vector2f p1, Vector2f q1, Vector2f p2, Vector2f q2);
	bool onSegment(Vector2f p, Vector2f q, Vector2f r);
	int orientation(Vector2f p, Vector2f q, Vector2f r);

};

