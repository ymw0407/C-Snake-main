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
};