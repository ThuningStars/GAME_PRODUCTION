#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "SDL.h"
#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include <vector>

#include "PlatformPlayer.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
#define LEVEL_WIDTH 1500
#define LEVEL_HEIGHT 768


using namespace std;

class Engine
{
private: // private properties.
	bool m_running = false;
	Uint32 m_start, m_end, m_delta, m_fps, score = 0;
	string scoreString;
	const Uint8* m_keystates;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Rect m_Platforms[6] = { {100,600,100,20},//0
								{200,500,100,20},//1
								{300,400,100,20},//2
								{400,700,100,20},//3
								{0,700,300,100},//4. Ground left
								{600, 700, 300, 100} //5 Ground right

	}; //Position X and y, width and height
	//size of the ground texture for rendering
	SDL_Rect textureSrc = { 0, 0, 225, 225 }; //NOT CURRENTLY USING THIS VARIABLE

	Mix_Music* m_pMusic;
	vector<Mix_Chunk*> m_vSounds;
	//SDL_Rect m_Camera = { 100, 0, WIDTH, HEIGHT };
	PlatformPlayer m_player;
	vector<Bullet*> m_playerbullet;
	vector<LeftBullet*> m_playerleftbullet;
	SDL_Texture* m_playerIdleTexture, * m_playerRunTexture, * m_playerAttackTexture, * m_groundTexture;
	SDL_Texture* m_yellowEnemyWalkTexture, * m_redEnemyWalkTexture;
	SDL_Texture *heartTexture;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RendererFlip flipEnemy = SDL_FLIP_NONE;
	Sprite m_yellowEnemy;
	vector<Enemy*> m_yellowEnemyCreation;
	int m_EnemyTimer;

	

	// Textures
	SDL_Texture* m_pTexture;


private: // private method prototypes.
	int Init(const char* title, int xPos, int yPos, int width, int height, int flags);
	void Clean();
	void Wake();
	void HandleEvents();
	bool KeyDown(const SDL_Scancode c);
	void CheckCollision();
	void Update();
	void Render();
	void Sleep();

public: // public method prototypes.
	int Run();
};

#endif

// Reminder: you can ONLY have declarations in headers, not logical code
