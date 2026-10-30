#pragma once

#include "./obstacle.hpp"
#include <vector>
#include <deque>

class Obstacles {

    public:
        Obstacle obstacle;
        std::deque<Obstacle> obstaclesDeque;
        void calculateChanges(double currentTime);
        void render();
        void addObstacles();
        Obstacles();
        int xAxisOffset = 75;
        double lastTime = 0;
        double interval = 0.2;
        Color colors[10] = {
                                {152, 34, 164, 255},
                                {57, 184, 167, 255},
                                {227, 34, 193, 255},
                                {212, 0, 0, 255},
                                {200, 198, 25, 255},
                                {209, 122, 50, 255},
                                {120, 15, 15, 255},
                                {16, 25, 194, 255},
                                {33, 211, 91, 255},
                                {0, 0, 0, 255},
                            };

};