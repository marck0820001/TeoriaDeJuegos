#pragma once
#include <GL/glew.h>

class Position
{
public:
	float x;
	float y;
};

class Color
{
public:
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

class Vertex
{
public:
	Position position;
	Color color;

	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}
};

