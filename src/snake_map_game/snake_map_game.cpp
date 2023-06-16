#include "../../include/snake_map_game/snake_map_game.h"
#include <ncurses.h>
#include <vector>

Snake_map_game::Snake_map_game(int startx, int starty) : startx(startx), starty(starty)
{
    move(0, 0);
    printw("Snake Game by MinWoo, SinJi, DongHyeon");
}

Snake_map_game::~Snake_map_game()
{
    endwin();
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