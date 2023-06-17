#include <ncurses.h>
#include <string>
#include "../../include/snake_game/snake_game.h"
#include "../snake_map_game/snake_map_game.cpp"
#include "../snake_map_scoreboard/snake_map_scoreboard.cpp"
#include "../snake_entity/snake_entity.cpp"
#include "../../map/stage1.h"
#include "../../map/stage2.h"
#include "../../map/stage3.h"
#include "../../map/stage4.h"

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

Snake_map_score SnakeGame::initScore(std::vector<std::string> scoreboard)
{
    score = scoreboard;
    Snake_map_score snake_score = Snake_map_score(70, 2); // map 1 61, 33
    snake_score.Snake_score_init(score);
    return snake_score;
}

void SnakeGame::gameStart(Snake_map_game map, Snake_map_score score, int tick)
{
    nodelay(stdscr, true);
    Snake_entity snake = Snake_entity(tick);
    snake.loop_snake(map, score);
    Snake_map_game map2 = selectMap(stage3);
    Snake_map_score score2 = initScore(scoreBoard);
    snake.loop_snake(map2, score2);
}
