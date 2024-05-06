#pragma once
#include <GL/glew.h>
#include "GLTexture.h"
#include <string>
using namespace std;

class Sprite
{
	float x, y;
	float width, height;
	GLuint vboID;
	GLTexture texture;
public:
	Sprite();
	~Sprite();
	void init(float x, float y, float width, float height, string texturePath);
	void draw();
};

