#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

class Poison : public item
{
protected:
    char item_char;
    int percentage;

public:
    Poison(int percentage = 10, char item_char = '@') : item_char(item_char), percentage(percentage){};
    void create_item(int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    static int cnt;
};

int Poison::cnt = 0;

void Poison::create_item(int starty, int startx, int height, int width, int r, int percentage, char item_char)
{
    srand((unsigned int)time(NULL) * r + r + 2);

    int tmp_x = (int)((rand() % (width - 2)) / 2) * 2 + startx + 2;
    int tmp_y = (rand() % (height - 1)) + starty + 1;

    if (mvinch(tmp_y, tmp_x) == ' ' && (rand() % (int)(percentage * 0.8)) != 0)
    {
        cnt++;
        mvaddch(tmp_y, tmp_x, item_char);
        refresh();
    }
}