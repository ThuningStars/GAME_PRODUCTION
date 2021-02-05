#include "Enemy.h"
#include "glm/gtx/string_cast.hpp"
#include "PlayScene.h"
#include "TextureManager.h"
#include "Util.h"

Enemy::Enemy()
{
	TextureManager::Instance()->load("../Assets/textures/enemy.png", "enemy");

	auto size = TextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(650.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setMaxSpeed(2);
	setType(ENEMY);
	m_currentHeading = 0.0f; // current facing angle
}

Enemy::~Enemy()
= default;

void Enemy::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the ship
	TextureManager::Instance()->draw("enemy", x, y, m_currentHeading, 255, true);
}

void Enemy::update()
{
	move();
	m_checkBounds();
}

void Enemy::clean()
{
}
void Enemy::setMaxSpeed(float speed)
{
	m_maxSpeed = speed;
}
void Enemy::move()
{
	m_maxSpeed = getTransform()->position.x -= 1.5;

	if (getTransform()->position.x <= 500)
	{
		-m_maxSpeed;
		turnright = true;

	}
	if (turnright == true)
	{
		m_maxSpeed = getTransform()->position.x += 3;

	}
	if (getTransform()->position.x >= 650)
	{
		turnright = false;

	}
}

void Enemy::m_checkBounds()
{
	if (getTransform()->position.x > Config::SCREEN_WIDTH)
	{
		getTransform()->position = glm::vec2(0.0f, getTransform()->position.y);
	}

	if (getTransform()->position.x < 0)
	{
		getTransform()->position = glm::vec2(800.0f, getTransform()->position.y);
	}

	if (getTransform()->position.y > Config::SCREEN_HEIGHT)
	{
		getTransform()->position = glm::vec2(getTransform()->position.x, 0.0f);
	}

	if (getTransform()->position.y < 0)
	{
		getTransform()->position = glm::vec2(getTransform()->position.x, 600.0f);
	}
}

void Enemy::m_reset()
{
}

void Enemy::m_changeDirection()
{
}
