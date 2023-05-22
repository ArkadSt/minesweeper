#include <vector>
using namespace std;


class Game{
    int size; // size of game board
    int mines; // number of mines
    vector<vector<char>> board;
    vector<pair<int, int>> mineLocations;
public:
    Game();
    Game(int size, int mines);
    int getSize();
    void setSize(int m_size);
    int getMines();
    void setMines(int m_mines_count);
    void createBoard();
    vector<vector<char>> getBoard();
    void setBoard(vector<vector<char>>);
    void placeMines();
    vector<pair<int, int>> getMineLocations();
    bool hasMine(pair<int, int>);

    void drawBoard();
    int numDigits();
    void exposeEmpty(int x, int y);

};