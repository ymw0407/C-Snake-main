#include "../../include/snake_map_scoreboard/snake_map_scoreboard.h"
#include "../../UI/scoreboard.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>

Snake_map_score::Snake_map_score(int startx, int starty) : startx(startx), starty(starty) {}

void Snake_map_score::Snake_score_init(std::vector<std::string> scoreboard)
{
    board_height = scoreboard.size();
    board_width = scoreboard[0].length();

    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            mvaddch(y + starty, x + startx, scoreboard[y][x]);
        }
    }
    refresh();
}

void Snake_map_score::Snake_score_reload(int l, int msp, int sp, int p, int m, int f, int s)
{
    mvprintw(starty + length.second, startx + length.first, "%s", std::to_string(l).c_str());
    mvprintw(starty + maxSpeed.second, startx + maxSpeed.first, "%s", std::to_string(msp).c_str());
    mvprintw(starty + speed.second, startx + speed.first, "%s", std::to_string(sp).c_str());
    mvprintw(starty + plus.second, startx + plus.first, "%s", std::to_string(p).c_str());
    mvprintw(starty + minus.second, startx + minus.first, "%s", std::to_string(m).c_str());
    mvprintw(starty + fast.second, startx + fast.first, "%s", std::to_string(f).c_str());
    mvprintw(starty + slow.second, startx + slow.first, "%s", std::to_string(s).c_str());
    refresh();
    // mvprintw(length.second, length.first, std::to_stirng(snake.l).c_str());
}