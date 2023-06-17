#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <vector>

class Poison : public item
{
protected:
    char item_char;
    int percentage;
    int ttl;
    int x, y;

public:
    Poison(int percentage = 10, char item_char = '@') : item_char(item_char), percentage(percentage){};
    void create_item(Poison poison, int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    static int cnt;
    static std::vector<Poison> check;
    static void tick_check();
};

int Poison::cnt = 0;
std::vector<Poison> Poison::check;

void Poison::create_item(Poison poison, int starty, int startx, int height, int width, int r, int percentage, char item_char)
{
    srand((unsigned int)time(NULL) * r + r + 2);

    int tmp_x = (int)((rand() % (width - 2)) / 2) * 2 + startx + 2;
    int tmp_y = (rand() % (height - 1)) + starty + 1;

    if (mvinch(tmp_y, tmp_x) == ' ' && (rand() % (int)(percentage * 0.8)) != 0)
    {
        cnt++;
        mvaddch(tmp_y, tmp_x, item_char);
        poison.x = tmp_x;
        poison.y = tmp_y;
        poison.ttl = 60;
        check.push_back(poison);
        refresh();
    }
}

void Poison::tick_check()
{
    for (int i = 0; i < check.size();)
    {
        check[i].ttl--;
        if (check[i].ttl <= 0)
        {
            if (mvinch(check[i].y, check[i].x) == '@')
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