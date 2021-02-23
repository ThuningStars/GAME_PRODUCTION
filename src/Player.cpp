#include "Player.h"
#include "TextureManager.h"
#include "Util.h"

Player::Player(): m_currentAnimationState(PLAYER_IDLE_RIGHT)
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/Animation.txt",
		"../Assets/sprites/Animation.png", 
		"spritesheet");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("spritesheet"));
	
	// set frame width
	setWidth(53);

	// set frame height
	setHeight(58);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);

	m_buildAnimations();
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;
	Util::DrawRect(getTransform()->position, 25, 50, glm::vec4(100, 150, 200, 255));
	

	// draw the player according to animation state
	//switch(m_currentAnimationState)
	//{
	//case PLAYER_IDLE_RIGHT:

	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("idle"),
	//		x, y, 0.12f, 0, 255, true);
	//	break;
	//case PLAYER_IDLE_LEFT:
	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("idle"),
	//		x, y, 0.12f, 0, 255, true, SDL_FLIP_HORIZONTAL);
	//	break;
	//case PLAYER_SHOOT_RIGHT:
	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("attack"),
	//		x, y, 0.12f, 0, 255, true);
	//	break;
	//case PLAYER_SHOOT_LEFT:
	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("attack"),
	//		x, y, 0.12f, 0, 255, true, SDL_FLIP_HORIZONTAL);
	//	break;
	//case PLAYER_RUN_RIGHT:
	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("run"),
	//		x, y, 0.25f, 0, 255, true);
	//	break;
	//case PLAYER_RUN_LEFT:
	//	TextureManager::Instance()->playAnimation("spritesheet", getAnimation("run"),
	//		x, y, 0.25f, 0, 255, true, SDL_FLIP_HORIZONTAL);
	//	break;
	//default:
	//	break;
	//}
	//
}

void Player::update()
{
	if(m_currentAnimationState == PLAYER_RUN_LEFT )
	{
		getRigidBody()->velocity.x = -5;
		m_move();
	}
	else if (m_currentAnimationState == PLAYER_RUN_RIGHT)
	{
		getRigidBody()->velocity.x = 5;
		m_move();
	}
	else if(m_currentAnimationState == PLAYER_IDLE_LEFT|| m_currentAnimationState == PLAYER_IDLE_RIGHT)
	{
		getRigidBody()->velocity.x = 0;
	}


}

void Player::clean()
{
}



void Player::setAnimationState(const PlayerAnimationState new_state)
{
	m_currentAnimationState = new_state;
}

void Player::m_buildAnimations()
{
	Animation idleAnimation = Animation();

	idleAnimation.name = "idle";
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle1"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle2"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle3"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle4"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle5"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("idle6"));

	setAnimation(idleAnimation);

	Animation runAnimation = Animation();

	runAnimation.name = "run";
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run1"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run2"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run3"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run4"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run5"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("run6"));

	setAnimation(runAnimation);

	Animation attackAnimation = Animation();

	runAnimation.name = "attack";
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("attack1"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("attack2"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("attack3"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("attack4"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("attack5"));

	setAnimation(attackAnimation);
}

void Player::m_move()
{
	getTransform()->position += getRigidBody()->velocity;
	
}

void Player::m_stop()
{
	getTransform()->position -= getRigidBody()->velocity;
}


