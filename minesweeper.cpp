#include <iostream>
#include "game.h"

void exposeEmpty(Game& game, int x, int y){
    int bordering = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x+i >= 0 && y+j >= 0 && x+i < game.getSize() && y+j < game.getSize()){
                if (!(i == 0 && j == 0) && game.hasMine(make_pair(x+i, y+j))) {
                    bordering++;
                }
            }
        }
    }

    vector<vector<char>> board = game.getBoard();
    board.at(x).at(y) = '0' + bordering;
    game.setBoard(board);

    if (bordering == 0){
        cout << "bordering = 0\n";
        // siin võib selle kohta ohutuks märkida

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x+i >= 0 && y+j >= 0 && x+i < game.getSize() && y+j < game.getSize()){
                    if (!(i == 0 && j == 0) && !game.hasMine(make_pair(x+i, y+j)) && (game.getBoard().at(x+i).at(y+j) == '-')) {
                        cout << "x: " << x+i << " y: " << y+j << '\n';
                        exposeEmpty(game, x+i, y+j);
                    }
                }
            }
        }
    }


}

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

    int total = 0;
    // game loop
    while (true) {
        game.drawBoard();

        cout << "Type coordinates X Y: ";
        int x, y;
        cin >> x >> y;

        if (!(x >= 0 && y >= 0 && x < game.getSize() && y < game.getSize())){
            cout << "Incorrect coordinates\n";
            continue;
        }

        if (game.hasMine(make_pair(x, y))) {
            cout << "You hit the mine! Game over \n";
            return 0;
        }

        total++;

        if (game.getSize() * game.getSize() - total == game.getMines()){
            cout << "You won!\n";
            return 0;
        }

        exposeEmpty(game, x, y);

    }

    return 0;
}
