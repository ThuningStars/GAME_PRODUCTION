#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include"SDL.h"
#include <iostream>

#include "PlayerBullet.h"
#define GRAVITY 6.0
using namespace std;

//class Sprite
//{
//private:
//	int m_frame = 0, 
//		m_frameMax = 60, 
//		m_sprite = 0, 
//		m_spriteMax = 8; 
//public:
//	SDL_Rect m_src; // Source rectangle
//	SDL_Rect m_dst; // Destiniation rectangle
//	SDL_Rect* GetSrc();
//	SDL_Rect* GetDst();
//	void SetRect(const SDL_Rect s, const SDL_Rect d);
//	void Animate();
//	void Update();
//};

class Enemy : public Sprite
{
private:
	SDL_Rect m_src; // Source rectangle
	SDL_Rect m_rect;

	double m_angle = 0.0;
	SDL_Point* m_pCenter = NULL;
	bool m_attack = false;

	int m_timer = 0;

public:
	Enemy(SDL_Point spawnLoc = { 1024, 200 });
	~Enemy();
	SDL_Rect* GetRect();// Source rectangle
	void Update(SDL_Rect src);
	void Render(SDL_Renderer* rend);
	void Render(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect src, SDL_RendererFlip flip);
	
};

class Enemy : public Sprite
{
private:
	SDL_Rect m_dst; // Source rectangle
	SDL_Rect m_rect;
public:
	Enemy(SDL_Point spawnLoc = { 1024, 200 });
	~Enemy();
	SDL_Rect* GetRect();// Source rectangle
	void Update();
	void Render(SDL_Renderer* rend);
};

#endif