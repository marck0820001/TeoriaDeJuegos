#pragma once
#include <iostream>
#include <GL/glew.h>
#include "Vertex.h"
using namespace std;

class Sprite
{
private:
	float x, y;
	float width, height;
	GLuint vboID;
	Vertex vertexData[6];

public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();
};

