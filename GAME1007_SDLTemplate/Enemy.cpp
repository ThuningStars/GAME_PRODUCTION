#include "Enemy.h"
void Enemy::Init(SDL_Renderer* r)
{
	m_eRend = r;
	m_eRect = { 1025,650,50,50 };
}


Enemy::~Enemy()
{	
cout << "De-Allocating Enemy at " << &(*this) << endl;
}

void Enemy::UpdateEnemy()
{	
	this->m_eRect.x -= 2;
}

void Enemy::Render()
{	
	SDL_SetRenderDrawColor(m_eRend, 255, 255, 255, 255);
	SDL_RenderFillRect(m_eRend, getRect());
}

SDL_Rect* Enemy::getRect()
{
	return &m_eRect;
}


