#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "Sprite.h"

class Imagen : public Sprite {
public:
    Imagen(float x, float y, float width, float height, const std::string& imagePath = "a.jpg")
        : Sprite() {
        init(x, y, width, height, imagePath);
    }
};

#endif // IMAGE_H
