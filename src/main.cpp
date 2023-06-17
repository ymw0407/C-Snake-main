#include "./snake_game/snake_game.cpp"
// #include "../map/stage1.h"
// #include "../map/stage2.h"
#include "../UI/scoreboard.h"
#include <ncurses.h>

int main()
{
    SnakeGame game = SnakeGame();
    Snake_map_game map = game.selectMap(stage2);
    Snake_map_score score = game.initScore(scoreBoard);
    game.gameStart(map, score, 500000);
    return 0;
}
