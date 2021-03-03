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
	this->m_rect.w = 100;
	this->m_rect.h = 146;

	m_timer = 0;
}

Enemy::~Enemy()
{
	cout << "De-allocating Enemy at " << &(*this) << endl;
}

void Enemy::Update(SDL_Rect src)
{
	
	
	this->m_rect.x -= 0;
	
	m_timer++;
	if (FPS / m_timer == 6)
	{
		m_timer = 0;
		src.x += 200;
	}


	if (src.x == 1200)
		src.x = 0;
}

void Enemy::Render(SDL_Renderer* rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
	SDL_RenderFillRect(rend, &m_rect);
}

void Enemy::Render(SDL_Renderer* rend,SDL_Texture* texture,SDL_Rect src, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(rend, texture, &src, &m_rect, m_angle, m_pCenter, flip);
}

SDL_Rect* Enemy::GetRect()
{
	return &m_rect;
}
