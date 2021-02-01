#include "Enemy.h"
//void Sprite::SetRect(const SDL_Rect s, const SDL_Rect d)
//{
//		m_src = s;
//		m_dst = d;
//}
//
//SDL_Rect* Sprite::GetSrc()
//{
//	return &m_src;
//}
//
//SDL_Rect* Sprite::GetDst()
//{
//	return &m_dst;
//}
//
//void Sprite::Animate()
//{
//	if (m_frame++ % m_frameMax == 0)
//		m_src.x = m_src.w * (m_sprite++ % (m_spriteMax)); // 128 * <our sprite ctr>
//}
//
//void Sprite::Update()
//{
//	this->m_dst.x -= 2;
//}

Enemy::Enemy(SDL_Point spawnLoc)
{
	cout << "Constructing Enemy " << &(*this) << endl;
	this->m_rect.x = spawnLoc.x;
	this->m_rect.y = spawnLoc.y;
	this->m_rect.w = 50;
	this->m_rect.h = 50;
}

Enemy::~Enemy()
{
	cout << "De-allocating Enemy at " << &(*this) << endl;
}

void Enemy::Update()
{
	this->m_rect.x -= 2;
}

void Enemy::Render(SDL_Renderer* rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
	SDL_RenderFillRect(rend, &m_rect);
}

SDL_Rect* Enemy::GetRect()
{
	return &m_rect;
}
