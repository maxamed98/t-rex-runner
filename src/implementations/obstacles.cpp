#include "../declarations/obstacles.hpp"


Obstacles::Obstacles() {

    addObstacles();   

}


void Obstacles::addObstacles() {

    obstacle.color = colors[GetRandomValue(0, 9)];

    obstaclesDeque.push_back(obstacle);


}


void Obstacles::calculateChanges(double currentTime) {

    if(currentTime - lastTime >= interval) {
        lastTime = currentTime;

        for(int i = 0; i < obstaclesDeque.size(); i++) {

            obstaclesDeque[i].position.x -= xAxisOffset;
            
        }

        if(obstaclesDeque.back().position.x < GetScreenWidth() / 2){
            addObstacles();
        }

        

    }


}


void Obstacles::render() {

    for(auto obstacle : obstaclesDeque) {

        DrawRectangleV(
                        obstacle.position,
                        {obstacle.width, obstacle.height},
                        obstacle.color
                    );

        // int b = obstacle.hasBeenPassed ? 1 : 0;

        // DrawText(TextFormat("%i", obstacle.hasBeenPassed), 
        //             obstacle.position.x + 0.5 * obstacle.width,
        //             obstacle.position.y + 0.5 * obstacle.height,
        //             20,
        //             WHITE
        //         );

    }

}

