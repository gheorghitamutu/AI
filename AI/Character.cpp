#include "Character.h"
#include<iostream>
Character::Character(Shape* shapeType)
{
	this->mShapeType = shapeType;
}

bool Character::intersects(Shape * shapeType)
{
	auto mShapeCountPoints = this->mShapeType->getPointCount();
	auto shapeCountPoints = shapeType->getPointCount();

	auto mShapePosition = mShapeType->getPosition();
	auto shapePosition = shapeType->getPosition();
	vector<Vector2f> mShapePointPosition;
	for (int i = 0; i < mShapeCountPoints; i++)
	{
		auto point = mShapeType->getPoint(i) + mShapePosition + mVelocity*mDeltaTime;
		if (i < mShapeCountPoints / 4)
		{
			point += Vector2f(2, -2);
		}
		else if (i < mShapeCountPoints / 2)
		{
			point += Vector2f(2, 2);
		}
		else if (i < 3*mShapeCountPoints / 4)
		{
			point += Vector2f(-2, 2);
		}
		else 
		{
			point += Vector2f(-2, -2);
		}
		mShapePointPosition.emplace_back(point);
	}

	vector<Vector2f> shapePointPosition;
	for (int i = 0; i < shapeCountPoints; i++)
	{
		shapePointPosition.emplace_back(shapeType->getPoint(i) + shapePosition);
	}

	for (auto& point : shapePointPosition)
	{
		if (isInside(mShapePointPosition, point))
		{
			return true;
		}
	}
	return false;
}

bool Character::intersects(vector<Shape*> shapeType)
{
	for (auto& shape : shapeType)
	{
		if (intersects(shape))
		{
			return true;
		}
	}
	return false;
}

void Character::setFillColor(Color color)
{
	mShapeType->setFillColor(color);
}

void Character::setPosition(Vector2f position)
{
	mShapeType->setPosition(position);
}

void Character::setOrigin(Vector2f position)
{
	mShapeType->setOrigin(position);
}

float Character::getRadius()
{
	return abs((mShapeType->getPoint(0).y - mShapeType->getPoint((int)(mShapeType->getPointCount() / 2)).y) / 2);
}

void Character::draw(RenderWindow * window)
{
	window->draw(*mShapeType);
}

void Character::Update()
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

	this->time.restart().asSeconds();
}

void Character::SetVelocity(Vector2f direction)
{
	this->mVelocity.x = direction.x * this->mSpeed;
	this->mVelocity.y = direction.y * this->mSpeed;
}

Shape* Character::GetShapeType()
{
	return mShapeType;
}

Character::~Character()
{
}

bool Character::isInside(vector<Vector2f> polygon, Vector2f point)
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

bool Character::doIntersect(Vector2f p1, Vector2f q1, Vector2f p2, Vector2f q2)
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

bool Character::onSegment(Vector2f p, Vector2f q, Vector2f r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	{
		return true;
	}
	return false;
}

int Character::orientation(Vector2f p, Vector2f q, Vector2f r)
{
	float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
	{
		return 0;
	}
	return (val > 0) ? 1 : 2;
}

