#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#ifndef ITEM_H
#define ITEM_H

class item
{
protected:
    char item_char;
    int percentage;

public:
    void create_item(int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    
};

void item::create_item(int starty, int startx, int height, int width, int r, int percentage, char item_char)
{
    srand((unsigned int)time(NULL) * r + r + 2);

    int tmp_x = (int)((rand() % (width - 2)) / 2) * 2 + startx + 2;
    int tmp_y = (rand() % (height - 1)) + starty + 1;

    if (mvinch(tmp_y, tmp_x) == ' ' && (rand() % (int)(percentage * 0.8)) != 0)
    {
        mvaddch(tmp_y, tmp_x, item_char);
        refresh();
    }
}

#endif