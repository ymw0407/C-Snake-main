#include "./snake_game/snake_game.cpp"
// #include "../map/stage1.h"
// #include "../map/stage2.h"
#include "../UI/scoreboard.h"
#include <ncurses.h>

int main()
{
    int result;
    SnakeGame game = SnakeGame();
    Snake_map_game map = game.selectMap(stage1);
    Snake_map_score score = game.initScore(scoreBoard);
    result = game.gameStart(map, score, 500000);

    map.~Snake_map_game();
    score.~Snake_map_score();

    if (result == 1)
    {
        game = SnakeGame();
        map = game.selectMap(stage2);
        score = game.initScore(scoreBoard);
        result += game.gameStart(map, score, 500000);
        map.~Snake_map_game();
        score.~Snake_map_score();
    }

    if (result == 2)
    {
        game = SnakeGame();
        map = game.selectMap(stage3);
        score = game.initScore(scoreBoard);
        result += game.gameStart(map, score, 500000);
        map.~Snake_map_game();
        score.~Snake_map_score();
    }

    if (result == 3)
    {
        game = SnakeGame();
        map = game.selectMap(stage4);
        score = game.initScore(scoreBoard);
        result += game.gameStart(map, score, 500000);
        map.~Snake_map_game();
        score.~Snake_map_score();
    }

    return 0;
}
