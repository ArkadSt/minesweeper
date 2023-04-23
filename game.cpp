#include "game.h"
#include <cstdlib>
#include <time.h>

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

void Game::createBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board.at(i).at(j) = '-';
        }
    }
}

void Game::placeMines()
{
    srand(time(NULL));
    for (int i = 0; i < mines; i++)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        mineLocations.at(i)[0] = row;
        mineLocations.at(i)[1] = col;
    }
}
