#include <vector>

class Game{
    int size; // size of game board
    int mines; // number of mines
    std::vector<std::vector<char>> board;
    std::vector<int[2]> mineLocations;
public:
    Game();
    Game(int size, int mines);
    int getSize();
    void setSize(int m_size);
    int getMines();
    void setMines(int m_mines_count);
    void createBoard();
    void placeMines();
};