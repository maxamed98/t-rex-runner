#pragma once

#include <raylib.h>

class Trex {

    public:
        Trex();
        ~Trex();
        Texture2D image;
        Vector2 position = {200 + 100, GetScreenHeight() - 72};
        int yAxisOffset = 240;
        int gravityYAxisOffset = 60;
        int width = 75;
        int height = 72;
        void calculateChanges(double currentTime);
        void render();
        Rectangle getRectangle();
        int score = 0;
        int lives = 5;
        double lastTime = 0;
        double interval = 0.3;

};