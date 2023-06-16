#include <iostream>
#include <vector>
#include <ncurses.h>
#include "../snake_map/snake_map.h"
#ifndef SNAKEMAP_GAME_H
#define SNAKEMAP_GAME_H

class Snake_map_game : protected Snake_map
{
protected:
    int startx, starty;
    int stage_height, stage_width;
    std::vector<std::string> stage;

public:
    Snake_map_game(int srartx, int starty);
    void Snake_stage_init(std::vector<std::string> stage);
    void Poison_create(int percentage);
    void Growth_create(int percentage);
};

#endif