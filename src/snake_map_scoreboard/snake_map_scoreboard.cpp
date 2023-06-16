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

void Snake_map_score::Snake_score_reload(Snake_entity snake)
{
    mvprintw(length.second, length.first, "%s", std::to_string(snake.l).c_str());
    refresh();
    // mvprintw(length.second, length.first, std::to_stirng(snake.l).c_str());
}