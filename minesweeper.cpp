#include <iostream>
#include "game.h"

int main(){

    cout << "Welcome to the Minesweeper (best one the humanity has ever created.) Enjoy this unforgettable experience\n";
    cout << "Choose you level: \n";

    cout << "1. Beginner \n";
    cout << "2. Intermediate\n";
    cout << "3. Advanced \n";
    cout << "Your choice: ";
    int valik;
    cin >> valik;

    Game game;

    switch(valik){
        case 1:
            game = Game(9, 10);
            break;
        case 2:
            game = Game(16, 40);
            break;
        case 3:
            game = Game(24, 99);
            break;
    }

    game.createBoard();
    game.placeMines();

    int total = 0;
    // game loop
    while (true) {
        game.drawBoard();

        cout << "Hit X coordinate: ";
        int x;
        cin >> x;

        cout << "Hit Y coordinate: ";
        int y;
        cin >> y;

        if (game.hasMine(make_pair(x, y))) {
            cout << "You hit the mine! Game over \n";
            return 0;
        }

        total++;

        if (game.getSize() * game.getSize() - total == game.getMines()){
            cout << "You won!\n";
            return 0;
        }

        int bordering = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x >= 0 && y >= 0 && x < game.getSize() && y < game.getSize()){
                    if (!(i == 0 && j == 0) && game.hasMine(make_pair(x+i, y+j))) {
                        bordering++;
                    }
                }

            }
            cout << '\n';
        }

        vector<vector<char>> board = game.getBoard();
        board.at(x).at(y) = '0' + bordering;
        game.setBoard(board);
    }

    return 0;
}