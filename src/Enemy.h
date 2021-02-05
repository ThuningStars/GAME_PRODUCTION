#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "../src/DisplayObject.h"

class Enemy final : public DisplayObject
{
public:
	Enemy();
	~Enemy();

	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
	void moveForward();
	void moveBack();
	void setMaxSpeed(float speed);
	void turnRight();
	void turnLeft();

	void move();


private:
	void m_checkBounds();
	void m_reset();

	// steering behaviours
	float m_maxSpeed;
	float m_turnRate;

	void m_changeDirection();
	float m_currentHeading;
	glm::vec2 m_currentDirection;
	
	glm::vec2 m_currentPosition;
	bool turnleft, turnright;
};


#endif
