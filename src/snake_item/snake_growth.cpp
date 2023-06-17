#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <vector>

class Growth : public item
{
protected:
    char item_char;
    int percentage;
    int ttl;
    int x, y;

public:
    Growth(int percentage = 3, char item_char = 'G') : item_char(item_char), percentage(percentage){};
    void create_item(Growth groth, int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    static int cnt;
    static std::vector<Growth> check;
    static void tick_check();
};

int Growth::cnt = 0;
std::vector<Growth> Growth::check;

void Growth::create_item(Growth growth, int starty, int startx, int height, int width, int r, int percentage, char item_char)
{
    srand((unsigned int)time(NULL) * r + r + 2);

    int tmp_x = (int)((rand() % (width - 2)) / 2) * 2 + startx + 2;
    int tmp_y = (rand() % (height - 1)) + starty + 1;

    if (mvinch(tmp_y, tmp_x) == ' ' && (rand() % (int)(percentage * 0.8)) != 0)
    {
        cnt++;
        mvaddch(tmp_y, tmp_x, item_char);
        growth.x = tmp_x;
        growth.y = tmp_y;
        growth.ttl = 40;
        check.push_back(growth);
        refresh();
    }
}

void Growth::tick_check()
{
    for (int i = 0; i < check.size();)
    {
        check[i].ttl--;
        if (check[i].ttl <= 0)
        {
            if (mvinch(check[i].y, check[i].x) == 'G')
            {
                mvaddch(check[i].y, check[i].x, ' ');
                cnt--;
                refresh();
            }
            check.erase(check.begin() + i);
        }
        else
        {
            i++;
        }
    }
}