#include "../../include/snake_map_game/snake_map_game.h"
#include "../snake_item/snake_poison.cpp"
#include "../snake_item/snake_growth.cpp"
#include <ncurses.h>
#include <vector>

Snake_map_game::Snake_map_game(int startx, int starty) : startx(startx), starty(starty)
{
    move(0, 0);
    printw("Snake Game by MinWoo, SinJi, DongHyeon");
}

void Snake_map_game::Snake_stage_init(std::vector<std::string> stage)
{
    stage_height = stage.size();
    stage_width = stage[0].length();

    for (int y = 0; y < stage_height; y++)
    {
        for (int x = 0; x < stage_width; x++)
        {
            mvaddch(y + starty, x + startx, stage[y][x]);
        }
    }
    refresh();
}

void Snake_map_game::Poison_create(int percentage)
{
    Poison poison = Poison(percentage);
    poison.create_item(starty, startx, stage_height, stage_width, percentage, '@');
}

void Snake_map_game::Growth_create(int percentage)
{
    Growth growth = Growth(percentage);
    growth.create_item(starty, startx, stage_height, stage_width, percentage, '$');
}