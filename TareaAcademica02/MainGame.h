#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include <iostream>
#include "Sprite.h"
#include "GLS_Program.h"

#include <vector>
#include <random>

using namespace std;

enum class GameState { 
	PLAY, EXIT 
};

class MainGame
{
private:
	int width;
	int height;
	SDL_Window* window;
	void init();
	void processInput();
	GLS_Program program;
	void initShaders();
	float time = 0.0f;

	vector<Sprite*> sprites;
	Uint32 tiempoInicio;
	Uint32 intervalo;

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

