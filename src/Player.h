#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "PlayerAnimationState.h"
#include "Sprite.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;


	// setters
	void setAnimationState(PlayerAnimationState new_state);

	void m_stop();
private:
	void m_buildAnimations();



	void m_move();
	

	PlayerAnimationState m_currentAnimationState;
};

#endif /* defined (__PLAYER__) */