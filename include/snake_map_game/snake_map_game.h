#include <iostream>
#include <vector>
#include <ncurses.h>
#ifndef SNAKEMAP_GAME_H
#define SNAKEMAP_GAME_H

class Snake_map_game
{
protected:
    int startx, starty;
    int stage_height, stage_width;
    std::vector<std::string> stage;

public:
    Snake_map_game(int srartx, int starty);
    void Snake_stage_init(std::vector<std::string> stage);
    void Poison_create(int percentage, int r);
    void Growth_create(int percentage, int r);
    void Slow_create(int percentage, int r);
    void Fast_create(int percentage, int r);
};

#endif