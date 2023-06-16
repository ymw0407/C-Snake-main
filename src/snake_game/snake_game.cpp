#include <ncurses.h>
#include <string>
#include "../../include/snake_game/snake_game.h"
#include "../snake_map_game/snake_map_game.cpp"
#include "../snake_entity/snake_entity.cpp"

SnakeGame::SnakeGame()
{
    /* screen setting */
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

SnakeGame::~SnakeGame()
{
    /* screen setting */
    endwin();
}

Snake_map_game SnakeGame::selectMap(std::vector<std::string> stage)
{
    map = stage;
    Snake_map_game snake_map = Snake_map_game(4, 2); // map 1 61, 33
    snake_map.Snake_stage_init(map);
    return snake_map;
}

void SnakeGame::gameStart(Snake_map_game map, int tick)
{
    nodelay(stdscr, true);
    Snake_entity snake = Snake_entity();
    snake.loop_snake(tick, map);
}
