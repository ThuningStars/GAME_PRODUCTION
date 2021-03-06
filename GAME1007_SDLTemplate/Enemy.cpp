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

Enemy::Enemy(int leftLimitX, int leftLimitY, int rightLimitX, int rightLimitY)
{
	m_leftX = leftLimitX - 25;
	m_leftY = leftLimitY;
	m_rightX = rightLimitX - 25;
	m_rightY = rightLimitY;
	m_speed = -1;
	cout << "Constructing Enemy " << m_leftX<<" "<< m_rightX << endl;
	
	
	this->m_rect.w = 50;
	this->m_rect.h = 73;
	this->m_rect.x = m_leftX;
	this->m_rect.y = m_leftY - m_rect.h;
	
	m_timer = 0;
}

Enemy::~Enemy()
{
	cout << "De-allocating Enemy at " << &(*this) << endl;
}

void Enemy::Update()
{
	if(m_rect.x < m_leftX)
	{
		m_speed = -m_speed;// m_speed;
		m_flip = SDL_FLIP_HORIZONTAL;
		
	}
	else if (m_rect.x > m_rightX)
	{
		m_speed = -m_speed;
		m_flip = SDL_FLIP_NONE;
	}
	m_rect.x += m_speed;
}

void Enemy::Render(SDL_Renderer* rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
	SDL_RenderFillRect(rend, &m_rect);
}

void Enemy::Render(SDL_Renderer* rend,SDL_Texture* texture,SDL_Rect src, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(rend, texture, &src, &m_rect, m_angle, m_pCenter, m_flip);
}

SDL_Rect* Enemy::GetRect()
{
	return &m_rect;
}
