#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>
#include "../snake_entity/snake_entity.h"
#ifndef SNAKEMAP_SCORE_H
#define SNAKEMAP_SCORE_H

class Snake_map_score
{
protected:
    int startx, starty;
    int board_height, board_width;

public:
    Snake_map_score(int srartx, int starty);
    void Snake_score_init(std::vector<std::string> scoreboard);
    void Snake_score_reload(Snake_entity snake);
};

#endif