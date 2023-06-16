#include <ncurses.h>
#include <vector>
#include <climits>
#include "../snake_map_game/snake_map_game.h"
#include "../snake_map_scoreboard/snake_map_scoreboard.h"
#ifndef SNAKEENTITY_H
#define SNAKEENTITY_H

struct map_position
{
private:
    int x, y;

public:
    map_position(int x, int y);
    std::pair<int, int> get_position();
};

class Snake_entity
{
private:
    std::vector<map_position> snake;
    char dir = 'l';
    int delay;
    void set_snake();
    char snake_collision();

public:
    Snake_entity(int delay);
    void move_snake();
    void loop_snake(Snake_map_game map, Snake_map_score score);
    int l = 3, msp = INT_MAX, sp, p = 0, m = 0, f = 0, s = 0;
};

#endif