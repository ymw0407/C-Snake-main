#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <vector>

class Slow : public item
{
protected:
    char item_char;
    int percentage;
    int ttl;
    int x, y;

public:
    Slow(int percentage = 10, char item_char = 'S') : item_char(item_char), percentage(percentage){};
    void create_item(Slow slow, int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    static int cnt;
    static std::vector<Slow> check;
    static void tick_check();
};

int Slow::cnt = 0;
std::vector<Slow> Slow::check;

void Slow::create_item(Slow slow, int starty, int startx, int height, int width, int r, int percentage, char item_char)
{
    srand((unsigned int)time(NULL) * r + r + 2);

    int tmp_x = (int)((rand() % (width - 2)) / 2) * 2 + startx + 2;
    int tmp_y = (rand() % (height - 1)) + starty + 1;

    if (mvinch(tmp_y, tmp_x) == ' ' && (rand() % (int)(percentage * 0.8)) != 0)
    {
        cnt++;
        mvaddch(tmp_y, tmp_x, item_char);
        slow.x = tmp_x;
        slow.y = tmp_y;
        slow.ttl = 60;
        check.push_back(slow);
        refresh();
    }
}

void Slow::tick_check()
{
    for (int i = 0; i < check.size();)
    {
        check[i].ttl--;
        if (check[i].ttl <= 0)
        {
            if (mvinch(check[i].y, check[i].x) == 'S')
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