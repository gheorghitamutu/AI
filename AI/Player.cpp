#include "Player.h"

Player::Player(Shape * shapeType) : Character(shapeType)
{
	mSpeed = 100;
	setFillColor(sf::Color::Green);
	setOrigin({ getRadius(), getRadius() });
	setPosition({ (float)(100), (float)(400 / 2) });
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

void Player::checkCollision(vector<Shape*> shapeType)
{
	if (intersects(shapeType))
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
