#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

class Slow : public item
{
protected:
    char item_char;
    int percentage;

public:
    Slow(int percentage = 10, char item_char = 'S') : item_char(item_char), percentage(percentage){};
};