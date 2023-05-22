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
        default:
            cout << "Incorrect value\n";
            return -1;
    }

    game.createBoard();
    game.placeMines();

    // int total = 0;
    // game loop
    while (true) {
        game.drawBoard();

        cout << "Type coordinates X Y: ";
        int x, y;
        cin >> y >> x;
        x -= 1;
        y -= 1;

        if (!(x >= 0 && y >= 0 && x < game.getSize() && y < game.getSize())){
            cout << "Incorrect coordinates\n";
            continue;
        }

        if (game.hasMine(make_pair(x, y))) {
            game.drawBoardWithMines();
            cout << "You hit the mine! Game over \n";
            return 0;
        }

        // total++;

        // if (game.getSize() * game.getSize() - total == game.getMines()){
        //     cout << "You won!\n";
        //     return 0;
        // }


        game.exposeEmpty(x, y);
        
        if (game.hasOnlyMines()){
            cout << "You won!\n";
            return 0;
        }
    }
    return 0;
}
