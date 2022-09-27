#include <iostream>
using namespace std;

char element[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void GameBoard() {
    // 1  | 2 | 3
    // ___|___|___
    // 4  | 5 | 6
    // ___|___|___
    // 7  | 8 | 9
    //    |   |
    cout << element[0] << "  | " << element[1] << " | " << element[2] << endl;
    cout << "___|___|___" << endl;
    cout << element[3] << "  | " << element[4] << " | " << element[5] << endl;
    cout << "___|___|___" << endl;
    cout << element[6] << "  | " << element[7] << " | " << element[8] << endl;
    cout << "   |   |" << endl;
    return;
}
void TicTacToe() {

    int play1, play2;
    int games = 9;
    GameBoard();
    //For 9 squares, play 9 times
    // Needs to stop when one wins
    while (games > 0)
    {
        
        cout << "Player 1, choose a square: ";
        cin >> play1;
        // Need input validation
        element[play1-1] = 'X';
        games--;
        GameBoard();

        if(games)
        {
            cout << "Player 2, choose a square: ";
            cin >> play2;
            // Need input validation
            element[play2-1] = 'O';
            games--;
            GameBoard();
        }
        
    }
    
    
    return;
}