#include "Player.h"

Player::Player(Shape * shapeType, float radius) : MovableShape(shapeType, radius)
{
	mSpeed = 100;
	setFillColor(sf::Color::Green);
	setPosition({ (float)(100), (float)(400 / 2) });

	/*for (int i = 0; i < mShapeType->getPointCount(); i++)
	{
		Canon* canon = new Canon({ new CircleShape(10.f, 10), 10.f });
		canon->setFillColor(sf::Color::Cyan);
		canon->setOrigin({ canon->getRadius(), canon->getRadius() });
		AddCanon(canon);
	}*/
}


void Player::HandleInput(Event event)
{
		this->mDirection = { 0.0f, 0.0f };
		mSpeed = 100.f;
		mShiftPressed = false;
		mSpeed = min(mSpeed*mIncreaseSpeedBy, 300.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			mDirection.y -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			mDirection.y += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			mDirection.x -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			mDirection.x += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		{
			mDirection.x *= 2;
			mDirection.y *= 2;
			mShiftPressed = true;
		}
		if ((mDirection.x != 0 || mDirection.y != 0))
		{
			mIncreaseSpeedBy += 0.0001f;
		}
		else
		{
			mIncreaseSpeedBy = 1.0f;
			mSpeed = 100.f;
		}
}

void Player::checkCollision(vector<Shape*> shapeType, RenderWindow* window)
{
	if (intersects(shapeType, window))
	{
		mCollision = true;
		mIncreaseSpeedBy = 1.0f;
	}
	else
	{
		mCollision = false;
	}
}

Player::~Player()
{
}
