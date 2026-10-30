#include <raylib.h>

#include "./declarations/trex.hpp";
#include "./declarations/obstacles.hpp";

int main() 
{

    char* current_window = "start";

    Color playButtonColor = DARKGRAY;
    Color aboutButtonColor = DARKGRAY;
    Color backButtonColor = DARKPURPLE;
    Color playAgainButtonColor = DARKGRAY;

    Rectangle playButton = {575, 200, 300, 120};
    Rectangle aboutButton = {575, 400, 300, 120};
    Rectangle backButton = {20, 20, 300, 80};
    Rectangle playAgainButton = {515, 400, 450, 120};
    
    int screenWidth = 1500;
    int screenHeight = 900;

    Color darkGrey = {70, 67, 70, 255};
    
    
    
    InitWindow(screenWidth, screenHeight, "T-Rex Runner");
    SetTargetFPS(60);

    Trex trex;
    Obstacles obstacles;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();


        if(current_window == "start") {
            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                    current_window = "game";

                }

                if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                    current_window = "about";
                }
            }
            
            if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                playButtonColor = GRAY;
            }
            else {
                playButtonColor = DARKGRAY;
            }

            

            if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                aboutButtonColor = GRAY;
            }
            else {
                aboutButtonColor = DARKGRAY;
            }

            DrawRectangleRounded(playButton, 1, 0, playButtonColor);
            DrawText("PLAY", 670, 245, 40, BLACK);

            DrawRectangleRounded(aboutButton, 1, 0, aboutButtonColor);
            DrawText("ABOUT", 660, 445, 40, BLACK);

            DrawText("T-Rex Runner", 520, 50, 60, BLACK);


        }


        if(current_window == "about") {

            ClearBackground(LIGHTGRAY);
            
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                    current_window = "start";

                }

            }

            if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                backButtonColor = PURPLE;
            }
            else {
                backButtonColor = DARKPURPLE;
            }

            DrawText("Created By Mohamed Dahir.", 550, 400, 30, BLACK);
            DrawText("© MMXXVI", 675, 450, 30, BLACK);

            DrawRectangleRounded(backButton, 1, 0, backButtonColor);
            DrawText("BACK", 115, 45, 40, BLACK);

        }


        if(current_window == "game") {


            ClearBackground(LIGHTGRAY);

            DrawRectangleV({0,0}, {200, GetScreenHeight()}, darkGrey);

            DrawText("SCORE", 23, 200, 45, WHITE);
            DrawText(TextFormat("%i", trex.score), 80, 270, 50, WHITE);

            DrawText("LIVES", 30, (GetScreenHeight() - 375), 45, WHITE);
            DrawText(TextFormat("%i", trex.lives), 80, (GetScreenHeight() - 300), 50, WHITE);

            trex.calculateChanges(GetTime());
            obstacles.calculateChanges(GetTime());

            for(int i = 0; i < obstacles.obstaclesDeque.size(); i++) {

                if(CheckCollisionRecs(trex.getRectangle(), obstacles.obstaclesDeque[i].getRectangle()) &&
                    obstacles.obstaclesDeque[i].hasCollidedWithTrex == false 
                 ) {
                    trex.lives--;
                    obstacles.obstaclesDeque[i].hasCollidedWithTrex = true;
                 }

                     
                if((trex.position.x + trex.width > 
                    obstacles.obstaclesDeque[i].position.x + obstacles.obstaclesDeque[i].width) && 
                    obstacles.obstaclesDeque[i].hasBeenPassed == false &&
                    obstacles.obstaclesDeque[i].hasCollidedWithTrex == false
                ) {
                    trex.score++;
                    obstacles.obstaclesDeque[i].hasBeenPassed = true;
                }


                if(obstacles.obstaclesDeque[i].position.x < 200 ){
                    obstacles.obstaclesDeque.pop_front();
                }

            }

            if(trex.lives == 0 ){
                trex.lives = 5;
                trex.score = 0;

                obstacles.obstaclesDeque.clear();
                obstacles.addObstacles();

                current_window = "game_over";

            }

           
            trex.render();
            obstacles.render();

        }    


        if(current_window == "game_over") {

            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){


                if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                    current_window = "game";
                }

            }
            
                        
            if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                playAgainButtonColor = GRAY;
            }
            else {
                playAgainButtonColor = DARKGRAY;
            }


            DrawText("Game Over", 550, 245, 75, BLACK);

            DrawRectangleRounded(playAgainButton, 1, 0, playAgainButtonColor);
            DrawText("PLAY AGAIN", 620, 445, 40, BLACK);

        }


        

        EndDrawing();

    }
    
    CloseWindow();
}