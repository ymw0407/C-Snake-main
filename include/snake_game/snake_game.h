#include <vector>
#include "../snake_map_game/snake_map_game.h"

class SnakeGame{
private:
    int delay;
    std::vector<std::string> map;
public:
    SnakeGame();
    ~SnakeGame();
    
    Snake_map_game selectMap(std::vector<std::string> stage);
    void gameStart(Snake_map_game map, int delay = 10000);
};