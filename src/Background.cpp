#include"Background.h"

#include "TextureManager.h"

Background::Background()
{
	TextureManager::Instance()->load("../assets/textures/background.png", "background");
	auto size = TextureManager::Instance()->getTextureSize("background");
	setWidth(size.x);
	setHeight(size.y);
}

Background::~Background()
{
}

void Background::draw()
{
	TextureManager::Instance()->draw("background", getTransform()->position.x, getTransform()->position.y,
		0, 255, false);


}

void Background::update()
{
}

void Background::clean()
{
}

void Background::setAnimationState(PlayerAnimationState new_state)
{
}

void Background::m_buildAnimations()
{
}
