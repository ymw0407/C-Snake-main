#include <vector>

class SnakeGame{
private:
    int delay;
    std::vector<std::string> map;
public:
    SnakeGame();
    ~SnakeGame();
    
    void selectMap(std::vector<std::string> stage);
    void gameStart(int delay);
};