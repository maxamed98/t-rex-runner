#include "../declarations/obstacle.hpp"


Rectangle Obstacle::getRectangle() {

    Rectangle rec = {
                        position.x,
                        position.y,
                        width,
                        height
                    };

    return rec;

}