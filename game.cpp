#include "game.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>

// constructors
Game::Game(){}
Game::Game(int m_size, int m_mines) : size{m_size}, mines{m_mines}{}

// getters/setters
int Game::getSize()
{
    return size;
}
void Game::setSize(int m_size)
{
    size = m_size;
}
int Game::getMines()
{
    return mines;
}
void Game::setMines(int m_mines_count)
{
    mines = m_mines_count;
}

// creates board according to the size member
void Game::createBoard()
{
    for (int i = 0; i < size; i++)
    {
        board.emplace_back();
        for (int j = 0; j < size; j++)
        {
            board.at(i).push_back('-');
        }
    }
}

// places the number of mines specified in the mines member
void Game::placeMines()
{
    srand(time(NULL));
    for (int i = 0; i < mines; i++)
    {
        int row, col;

        while (true) {
            row = rand() % size;
            col = rand() % size;
            for (auto & mineLocation : mineLocations) {
                if (mineLocation.first == row && mineLocation.second == col) {
                    goto cnt;
                }
            }
            break;
            cnt:;
        }
        mineLocations.emplace_back();
        mineLocations.at(i).first = row;
        mineLocations.at(i).second = col;
    }
}

vector<vector<char>> Game::getBoard() {
    return board;
}

vector<pair<int, int>> Game::getMineLocations() {
    return mineLocations;
}

// compares each mine location to the given coordinates and returns true if the given coordinates are the location of a mine
bool Game::hasMine(pair<int, int> coords) {
    for (auto mine : mineLocations){
        if (mine.first == coords.first && mine.second == coords.second){
            return true;
        }
    }
    return false;
}

bool Game::hasOnlyMines(){
    int total = 0;
    for (int i = 0; i < getBoard().size(); i++)
    {
        for (int j = 0; j < getBoard().at(i).size(); j++)
        {
            if (getBoard().at(i).at(j) == '-') total++;
        }
    }
    cout << "total lines found: " << total << '\n';
    cout << "total mines: " << mineLocations.size() << '\n';
    return total == mineLocations.size();
}

void Game::setBoard(vector<vector<char>> board) {
    this ->board = board;
}

void Game::drawBoard(){
        int spacing = numDigits() + 1;

        // top row of indices
        cout << left << setw(spacing) << " ";
        for (int i = 0; i < getSize(); i++){
            cout << setw(spacing) << i + 1;
        }
        cout << "X/Y\n";
        
        // game board itself
        for (int i = 0; i < getSize(); i++) {
            if (i < 9 && spacing > 2)
                cout << right << setw(spacing - 1) << i + 1 << " " << left;
            else
                cout << setw(spacing) << i + 1;

            for (int j = 0; j < getSize(); j++) {
                cout << setw(spacing) << getBoard().at(i).at(j);
            }
            cout << i + 1 << '\n';
        }

        // bottom row of indices
        cout << setw(spacing) << " ";
        for (int i = 0; i < getSize(); i++){
            cout << setw(spacing) << i + 1;
        }
        cout << '\n';
}

void Game::drawBoardWithMines(){
    int spacing = numDigits() + 1;

    // top row of indices
    cout << left << setw(spacing) << " ";
    for (int i = 0; i < getSize(); i++){
        cout << setw(spacing) << i + 1;
    }
    cout << "X/Y\n";
    
    // game board itself
    for (int i = 0; i < getSize(); i++) {
        if (i < 9 && spacing > 2)
            cout << right << setw(spacing - 1) << i + 1 << " " << left;
        else
            cout << setw(spacing) << i + 1;

        for (int j = 0; j < getSize(); j++) {
            char tile = getBoard().at(i).at(j);
            // if (tile == '-')
            //     cout << setw(spacing) << 'X';
            // else
            bool isBomb = false;
            vector<pair<int, int>>::iterator it = mineLocations.begin();
            for (it; it < mineLocations.end(); it++){
                if (it->first == i && it->second == j){
                    cout << setw(spacing) << 'X';
                    isBomb = true;
                    mineLocations.erase(it);
                    break;
                }
            }
            if (!isBomb) cout << setw(spacing) << tile;
        }
        cout << i + 1 << '\n';
    }

    // bottom row of indices
    cout << setw(spacing) << " ";
    for (int i = 0; i < getSize(); i++){
        cout << setw(spacing) << i + 1;
    }
    cout << '\n';
}

// finds number of digits in the size of the largest row/column in the game board
int Game::numDigits()
{
    int size = getSize();
    int digits = 0;
    while (size) {
        size /= 10;
        digits++;
    }
    return digits;
}

// reveals all tiles next to the tile selected by the user if the tile has zero bombs next to it,
// does the same recursively for every 0 bomb tile that the last tile revealed
void Game::updateMapOnHit(int x, int y){
    int bordering = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x+i >= 0 && y+j >= 0 && x+i < getSize() && y+j < getSize()){
                if (!(i == 0 && j == 0) && hasMine(make_pair(x+i, y+j))) {
                    bordering++;
                }
            }
        }
    }

    vector<vector<char>> board = getBoard();
    if (bordering == 0) board.at(x).at(y) = ' ';
    else board.at(x).at(y) = '0' + bordering;
    setBoard(board);

    if (bordering == 0){
        // cout << "bordering = 0\n";
        // siin võib selle kohta ohutuks märkida

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x+i >= 0 && y+j >= 0 && x+i < getSize() && y+j < getSize()){
                    if (!(i == 0 && j == 0) && !hasMine(make_pair(x+i, y+j)) && (getBoard().at(x+i).at(y+j) == '-')) {
                        // cout << "x: " << x+i << " y: " << y+j << '\n';
                        updateMapOnHit(x + i, y + j);
                    }
                }
            }
        }
    }
}
