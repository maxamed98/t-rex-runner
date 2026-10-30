#pragma once

#include <raylib.h>

class Obstacle {

    public:
        int width = 50;
        int height = 60;
        Vector2 position = {GetScreenWidth() - 100, GetScreenHeight() - height};
        Color color;
        bool hasBeenPassed = false;
        bool hasCollidedWithTrex = false;
        Rectangle getRectangle();
        
};