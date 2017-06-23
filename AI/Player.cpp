#include "Player.h"

void Player::HandleInput(Event event)
{
		this->mDirection = { 0.0f, 0.0f };

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
		}
}

void Player::checkCollision(vector<Shape*> shapeType)
{
	if (intersects(shapeType))
	{
		mCollision = true;
	}
	else
	{
		mCollision = false;
	}
}

Player::~Player()
{
}
