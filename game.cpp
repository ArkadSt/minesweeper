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
        mineLocations.emplace_back();
        int row = rand() % size;
        int col = rand() % size;
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

void Game::setBoard(vector<vector<char>> board) {
    this ->board = board;
}

void Game::drawBoard(){
        int spacing = numDigits() + 1;

        cout << left;
        // top row of indices
        cout << setw(spacing) << " ";
        for (int i = 0; i < getSize(); i++){
            cout << setw(spacing) << i + 1;
        }
        cout << '\n';
        
        // game board itself
        for (int i = 0; i < getSize(); i++) {
            if (i < 9 && spacing > 2){
                cout << right;
                cout << setw(spacing - 1) << i + 1 << " ";
                cout << left;
            }
            else{
                cout << setw(spacing) << i + 1;
            }
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
