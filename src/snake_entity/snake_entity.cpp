#include "../../include/snake_entity/snake_entity.h"
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <string>

map_position::map_position(int x, int y) : x(x), y(y) {}

std::pair<int, int> map_position::get_position()
{
    return std::make_pair(x, y);
}

Snake_entity::Snake_entity()
{
    for (int i = 0; i < 4; i++)
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
        }
        break;
    case KEY_RIGHT:
        if (dir != 'l')
        {
            dir = 'r';
        }
        break;
    case KEY_UP:
        if (dir != 'd')
        {
            dir = 'u';
        }
        break;
    case KEY_DOWN:
        if (dir != 'u')
        {
            dir = 'd';
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
    
    case '$':
        break;
    
    case '@':
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        x2 = snake.back().get_position().second;
        y2 = snake.back().get_position().first;
        snake.pop_back();
        mvaddch(y2, x2, ' ');
        break;
    
    default:
        mvaddch(y2, x2, ' ');
        snake.pop_back();
        break;
    }

    set_snake();
    refresh();
}

void Snake_entity::set_snake()
{
    int x = snake[0].get_position().second;
    int y = snake[0].get_position().first;
    mvaddch(y, x, 'H');
    for (int i = 1; i < snake.size(); i++)
    {
        x = snake[i].get_position().second;
        y = snake[i].get_position().first;
        mvaddch(y, x, 'B');
    }
}

void Snake_entity::loop_snake(int delay, Snake_map_game map)
{
    while (dir != 'q')
    {
        map.Poison_create(5);
        map.Growth_create(7);
        move_snake();
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