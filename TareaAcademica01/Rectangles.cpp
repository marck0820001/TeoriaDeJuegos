#include "Rectangles.h"

Rectangles::Rectangles() {
	rectangles = vector<Sprite*>();
}

Rectangles::~Rectangles() {
}

void Rectangles::draw() {
	for (int i = 0; i < rectangles.size(); i++) {
		rectangles[i]->draw();
	}
}

void Rectangles::addRectangles(Sprite* sprite) {
	rectangles.push_back(sprite);
}