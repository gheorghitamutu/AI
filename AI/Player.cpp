#include "Player.h"

Player::Player(CustomShape * shapeType) : MovableShape(shapeType)
{
	mSpeed = 100;
	setFillColor(sf::Color::Green);
	setPosition({ (float)(100), (float)(600) });

	for (int i = 0; i < mShapeType->getPointCount(); i++)
	{
		Canon* canon = new Canon(new CustomShape(15.f, 30));
		canon->setFillColor(Color::Yellow);
		canon->setOrigin({ canon->getRadius()/10.f, canon->getRadius()/8.f });
		AddCanon(canon);
	}
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

void Player::checkCollision(vector<CustomShape*> shapeType, RenderWindow* window)
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
