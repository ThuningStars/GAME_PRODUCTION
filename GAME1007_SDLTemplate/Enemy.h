#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include"SDL.h"
#include <iostream>
#define GRAVITY 6.0
using namespace std;

class Enemy
{
private:
	
	SDL_Rect m_eRect;
	SDL_Renderer* m_eRend;
	
public:
	void Init(SDL_Renderer* r);
	~Enemy(); // Destructor
	void UpdateEnemy();
	void Render();
	SDL_Rect* getRect();
	
};

#endif