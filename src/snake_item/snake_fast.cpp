#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <vector>

class Fast : public item
{
protected:
    char item_char;
    int percentage;
    int ttl;
    int x, y;

public:
    Fast(int percentage = 10, char item_char = 'F') : item_char(item_char), percentage(percentage)
    {
        ttl = 6;
    };
    void create_item(int starty, int startx, int height, int width, int r, int percentage = 3, char item_char = '@');
    static int cnt;
    static std::vector<Fast> check;
    static void tick_check();
};

int Fast::cnt = 0;
std::vector<Fast> Fast::check;

void Fast::create_item(int starty, int startx, int height, int width, int r, int percentage, char item_char)
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

void Fast::tick_check()
{
    for (int i = 0; i < check.size(); i++)
    {
        check[i].ttl--;
        if(check[i].ttl == 0){
            
        }
    }
}