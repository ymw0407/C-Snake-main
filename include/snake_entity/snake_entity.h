#include <ncurses.h>
#include <vector>
#ifndef SNAKEENTITY_H
#define SNAKEENTITY_H

struct map_position
{
private:
    int x, y;
public:
    map_position(int x, int y);
    std::pair<int, int> get_position();
};

class Snake_entity
{
private:
    std::vector<map_position> snake;
    char dir = 'l';
    int delay;
    void set_snake();
    char snake_collision();
public:
    Snake_entity(int delay);
    void move_snake();
    void loop_snake(Snake_map_game map);
};

#endif