#include "./snake_item.cpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

class Growth : public item
{
protected:
    char item_char;
    int percentage;

public:
    Growth(int percentage = 3, char item_char = '$') : item_char(item_char), percentage(percentage){};
};