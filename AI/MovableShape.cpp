#include "MovableShape.h"
#include<iostream>
#include "Canon.h"
#include <math.h> 
MovableShape::MovableShape(CustomShape* shapeType) : CustomShape(shapeType->getSize(), shapeType->getPointCount())
{
	this->mShapeType = shapeType;
}

bool MovableShape::intersects(CustomShape * shapeType, RenderWindow* window)
{
	auto mShapeCountPoints = this->mShapeType->getPointCount();
	auto shapeCountPoints = shapeType->getPointCount();

	auto mShapePosition = (Vector2f)mShapeType->getPosition();
	auto shapePosition = (Vector2f)shapeType->getPosition();
	vector<Vector2f> mShapePointPosition = mShapeType->getPolygonPoints();
	for (auto& point : mShapePointPosition)
	{
		point += mShapePosition + mVelocity*mDeltaTime;
	}
	vector<Vector2f> shapePointPosition = shapeType->getPolygonPoints();
	for (auto& point : shapePointPosition)
	{
		point += shapePosition;
	}
	//drawIntersectionPoints(window, shapePointPosition);
	//drawIntersectionPoints(window, mShapePointPosition);
	for (auto& point : shapePointPosition)
	{
		if (isInside(mShapePointPosition, point))
		{
			return true;
		}
	}

	for (auto& point : mShapePointPosition) //you are  not calculating other objects velocity here!
	{
		if (isInside(shapePointPosition, point))
		{
			return true;
		}
	}
	return false;
}

bool MovableShape::intersects(vector<CustomShape*> shapeType, RenderWindow* window)
{
	for (auto& shape : shapeType)
	{
		if (intersects(shape, window))
		{
			return true;
		}
	}
	return false;
}

void MovableShape::drawIntersectionPoints(RenderWindow * window, vector<Vector2f> shapePointPosition)
{
	for (auto& point : shapePointPosition)
	{
		CircleShape circle(5.f);
		circle.setPosition((Vector2f)point);
		circle.setFillColor(Color::Yellow);
		window->draw(circle);
	}
}

void MovableShape::setFillColor(Color color)
{
	mShapeType->setFillColor(color);
}

void MovableShape::setPosition(Vector2f position)
{
	mShapeType->setPosition(position);
}

Vector2f MovableShape::getPosition()
{
	return mShapeType->getPosition();
}

void MovableShape::setOrigin(Vector2f position)
{
	mShapeType->setOrigin(position);
}

float MovableShape::getRadius()
{
	return this->mShapeType->getSize();
}

void MovableShape::draw(RenderWindow * window)
{
	window->draw(*mShapeType);
	for (auto& canon: mCanons)
	{
		canon->draw(window);
	}
}

void MovableShape::Update()
{
	this->mDeltaTime = this->time.getElapsedTime().asSeconds();
	SetVelocity(this->mDirection);
	if (!mCollision)
	{
		this->mShapeType->move(mVelocity*mDeltaTime);
	}
	else
	{
		this->mShapeType->move(Vector2f(0, 0)*mDeltaTime);
	}
	int i = 1;
	for (auto& canon : mCanons)
	{
		Vector2f pointCoords = { getRadius() * cos(2 * PI * i / (mShapeType->getPointCount())), getRadius() * sin(2 * PI * i / (mShapeType->getPointCount())) };
		auto mShapeCountPoints = mShapeType->getPointCount();
		canon->setPosition(mShapeType->getPosition() + pointCoords);
		i++;
	}
	this->time.restart().asSeconds();
}

void MovableShape::SetVelocity(Vector2f direction)
{
	this->mVelocity.x = direction.x * this->mSpeed;
	this->mVelocity.y = direction.y * this->mSpeed;
}

void MovableShape::SetSpeed(float speed)
{
	this->mSpeed = speed;
}

void MovableShape::AddCanon(Canon * canon)
{
	this->mCanons.emplace_back(canon);
}

CustomShape* MovableShape::GetShapeType()
{
	return mShapeType;
}

MovableShape::~MovableShape()
{
}

bool MovableShape::isInside(vector<Vector2f> polygon, Vector2f point)
{
	int n = polygon.size();
	if (n < 3)
	{
		return false;
	}
	Vector2f extreme = { 10000, point.y };

	int count = 0, i = 0, next;
	do
	{
		next = (i + 1) % n;
		if (doIntersect(polygon[i], polygon[next], point, extreme))
		{
			if (orientation(polygon[i], point, polygon[next]) == 0)
			{
				return onSegment(polygon[i], point, polygon[next]);
			}
			count++;
		}
		i = next;
	} while (i != 0);
	return count & 1;
}

bool MovableShape::doIntersect(Vector2f p1, Vector2f q1, Vector2f p2, Vector2f q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if ((o1 != o2 && o3 != o4) ||
		(o1 == 0 && onSegment(p1, p2, q1)) ||
		(o2 == 0 && onSegment(p1, q2, q1)) ||
		(o3 == 0 && onSegment(p2, p1, q2)) ||
		(o4 == 0 && onSegment(p2, q1, q2)))
	{
		return true;
	}
	return false;
}

bool MovableShape::onSegment(Vector2f p, Vector2f q, Vector2f r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	{
		return true;
	}
	return false;
}

int MovableShape::orientation(Vector2f p, Vector2f q, Vector2f r)
{
	float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
	{
		return 0;
	}
	return (val > 0) ? 1 : 2;
}
