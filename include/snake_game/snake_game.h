#include <vector>
#include "../snake_map_game/snake_map_game.h"
#include "../snake_map_scoreboard/snake_map_scoreboard.h"

class SnakeGame{
private:
    int delay;
    std::vector<std::string> map;
    std::vector<std::string> score;
public:
    SnakeGame();
    ~SnakeGame();
    
    Snake_map_game selectMap(std::vector<std::string> stage);
    Snake_map_score initScore(std::vector<std::string> scoreboard);
    int gameStart(Snake_map_game map, Snake_map_score score, int delay = 10000);
};