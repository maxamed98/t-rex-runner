#include "../declarations/trex.hpp"


Trex::Trex() {

    image = LoadTexture("./resources/trex.png");


}


Trex::~Trex() {

    UnloadTexture(image);


}


void Trex::calculateChanges(double currentTime) {

    if(position.y < 820) {
        
        if(currentTime - lastTime >= interval) {
            lastTime = currentTime;
            
            position.y += gravityYAxisOffset;
        }

    }

    if(position.y > GetScreenHeight() - 72) {
        position.y = GetScreenHeight() - 72;
    }


    if(IsKeyDown(KEY_UP) && position.y == GetScreenHeight() - 72 ) {

        position.y -= yAxisOffset;

        // 588 = position.y (828) - (yAxisOffset) 240
        if(position.y <= 588) {
            position.y = 588;
        }

    }
    


}


Rectangle Trex::getRectangle() {

    Rectangle rec = {position.x, position.y, width, height};

    return rec;


}


void Trex::render() {

    DrawTextureV(image, position, WHITE);


    // Rectangle rec = {position.x, position.y, width, height};

    // DrawRectangleLinesEx(rec, 5, RED);

    // DrawLineV(
    //             {200, 700},
    //             {1500, 700},
    //             RED
    //         );

    // DrawLineV(
    //             {200, 640},
    //             {1500, 640},
    //             RED
    //         );

    // DrawLineV(
    //             {200, 588},
    //             {1500, 588},
    //             RED
    //         );

}