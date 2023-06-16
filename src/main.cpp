#include "./snake_map_game/snake_map_game.cpp"
#include "./snake_entity/snake_entity.cpp"
#include "../map/stage1.h"
#include "../map/stage2.h"
#include <ncurses.h>

int main()
{
    initscr();   // Curses 초기화
    noecho();    // 키 입력을 화면에 표시 x
    curs_set(0); // 커서를 보이지 않게함
    refresh();
    nodelay(stdscr, true);
    keypad(stdscr, TRUE);

    Snake_map_game snake_map = Snake_map_game(4, 2); // stage1 61, 33
    snake_map.Snake_stage_init(stage1);
    getch();

    Snake_entity snake = Snake_entity();
    snake.loop_snake();
    return 0;
}
