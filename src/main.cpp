#include "./snake_game/snake_game.cpp"
#include "../map/stage1.h"
#include "../map/stage2.h"
#include <ncurses.h>

int main()
{
    SnakeGame game = SnakeGame();
    Snake_map_game map = game.selectMap(stage1);
    game.gameStart(map, 100000);
    return 0;
}
