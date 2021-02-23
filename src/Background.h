#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "PlayerAnimationState.h"
#include "Sprite.h"

class Background : public Sprite
{
public:
	Background();
	~Background();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters
	void setAnimationState(PlayerAnimationState new_state);

private:
	void m_buildAnimations();

	PlayerAnimationState m_currentAnimationState;
};

#endif 