#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "Sprite.h"
using namespace std;

class Rectangles
{
private:
	vector<Sprite*> rectangles;

public:
	Rectangles();
	~Rectangles();
	void draw();

	void addRectangles(Sprite* sprite);
};

