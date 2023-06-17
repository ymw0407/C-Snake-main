#include "../../include/snake_entity/snake_entity.h"
#include "../../include/snake_map_scoreboard/snake_map_scoreboard.h"
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <string>

map_position::map_position(int x, int y) : x(x), y(y) {}

std::pair<int, int> map_position::get_position()
{
    return std::make_pair(x, y);
}

Snake_entity::Snake_entity(int delay) : delay(delay)
{
    for (int i = 0; i < 3; i++)
    {
        snake.push_back(map_position(15, 30 + i * 2));
    }
    set_snake();
    refresh();
}

void Snake_entity::move_snake()
{
    int KEY = getch();
    switch (KEY)
    {
    case KEY_LEFT:
        if (dir != 'r')
        {
            dir = 'l';
        } else {
            dir = 'q';
        }
        break;
    case KEY_RIGHT:
        if (dir != 'l')
        {
            dir = 'r';
        } else {
            dir = 'q';
        }
        break;
    case KEY_UP:
        if (dir != 'd')
        {
            dir = 'u';
        } else {
            dir = 'q';
        }
        break;
    case KEY_DOWN:
        if (dir != 'u')
        {
            dir = 'd';
        } else {
            dir = 'q';
        }
        break;
    case KEY_F(1):
        dir = 'q';
        break;
    }

    int x = snake[0].get_position().second;
    int y = snake[0].get_position().first;

    if (dir == 'l')
        snake.insert(snake.begin(), map_position(y, x - 2));
    else if (dir == 'r')
        snake.insert(snake.begin(), map_position(y, x + 2));
    else if (dir == 'u')
        snake.insert(snake.begin(), map_position(y - 1, x));
    else if (dir == 'd')
        snake.insert(snake.begin(), map_position(y + 1, x));

    int x2 = snake.back().get_position().second;
    int y2 = snake.back().get_position().first;

    switch (snake_collision())
    {
    case '1':
        dir = 'q';
        break;

    case 'B':
        dir = 'q';
        break;

    case 'G': // growth
        if (l >= 20)
        {
            mvaddch(y2, x2, ' ');
            snake.pop_back();
        }
        else
        {
            p++;
        }
        Growth::cnt--;
        break;

    case '@': // poison
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        x2 = snake.back().get_position().second;
        y2 = snake.back().get_position().first;
        snake.pop_back();
        mvaddch(y2, x2, ' ');
        m++;
        Poison::cnt--;
        break;

    case 'S': // slow
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        delay *= 1.5;
        s++;
        Slow::cnt--;
        break;

    case 'F': // fast
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        delay *= 0.8;
        f++;
        Fast::cnt--;
        break;

    default:
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        break;
    }

    if (snake.size() < 3)
        dir = 'q';

    set_snake();
    refresh();
}

void Snake_entity::set_snake()
{
    int x = snake[0].get_position().second;
    int y = snake[0].get_position().first;
    mvaddch(y, x, 'H');
    l = snake.size();
    for (int i = 1; i < l; i++)
    {
        x = snake[i].get_position().second;
        y = snake[i].get_position().first;
        mvaddch(y, x, 'B');
    }
}

void Snake_entity::loop_snake(Snake_map_game map, Snake_map_score score)
{
    while (dir != 'q')
    {
        delay *= 0.99;
        delay -= 30;
        move_snake();

        map.Poison_create(4, 7);
        map.Growth_create(3, 93);
        map.Fast_create(4, 31);
        map.Slow_create(3, 61);
        Fast::tick_check();
        Growth::tick_check();
        Slow::tick_check();
        Poison::tick_check();
        sp = delay;
        msp = std::min(delay, msp);
        score.Snake_score_reload(l, msp, sp, p, m, f, s);
        usleep(delay);
    }
}

char Snake_entity::snake_collision()
{
    int x = snake[0].get_position().second;
    int y = snake[0].get_position().first;
    char head = mvinch(y, x);

    return head;
}