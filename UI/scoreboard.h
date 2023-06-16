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
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "|                                         |",
        "@=========================================@"};

std::pair<int, int> length = std::make_pair(13, 6);
std::pair<int, int> maxSpeed = std::make_pair(13, 8);
std::pair<int, int> Speed = std::make_pair(12, 10);
std::pair<int, int> plus = std::make_pair(12, 12);
std::pair<int, int> minus = std::make_pair(8, 14);
std::pair<int, int> fast = std::make_pair(8, 16);
std::pair<int, int> slow = std::make_pair(8, 18);

#endif