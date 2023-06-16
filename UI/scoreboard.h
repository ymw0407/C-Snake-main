#include <vector>
#include <string>

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

std::vector<std::string> scoreBoard =
    {
        "@=========================================@",
        "|                                         |",
        "| Score Board                             |",
        "|                                         |",
        "|                                         |",
        "|  Length :     / 20                      |",
        "|                                         |",
        "|  MaxSpeed :                             |",
        "|                                         |",
        "|  Speed :                                |",
        "|                                         |",
        "|  + :                                    |",
        "|                                         |",
        "|  - :                                    |",
        "|                                         |",
        "|  F :                                    |",
        "|                                         |",
        "|  S :                                    |",
        "|                                         |",
        "@=========================================@",
        "|                                         |",
        "| Mission                                 |",
        "|                                         |",
        "|                                         |",
        "|  Length : 10 (   )                      |",
        "|                                         |",
        "|  MaxSpeed : 100000 (   )                |",
        "|                                         |",
        "|  + : 5 (   )                            |",
        "|                                         |",
        "|  - : 2 (   )                            |",
        "|                                         |",
        "@=========================================@"};

std::pair<int, int> length = std::make_pair(13, 5);
std::pair<int, int> maxSpeed = std::make_pair(14, 7);
std::pair<int, int> speed = std::make_pair(11, 9);
std::pair<int, int> plus = std::make_pair(7, 11);
std::pair<int, int> minus = std::make_pair(7, 13);
std::pair<int, int> fast = std::make_pair(7, 15);
std::pair<int, int> slow = std::make_pair(7, 17);
std::pair<int, int> m_length = std::make_pair(17, 24);
std::pair<int, int> m_maxSpeed = std::make_pair(23, 26);
std::pair<int, int> m_plus = std::make_pair(11, 28);
std::pair<int, int> m_minus = std::make_pair(11, 30);

#endif