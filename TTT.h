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
    // Present game board
    cout << element[0] << "  | " << element[1] << " | " << element[2] << endl;
    cout << "___|___|___" << endl;
    cout << element[3] << "  | " << element[4] << " | " << element[5] << endl;
    cout << "___|___|___" << endl;
    cout << element[6] << "  | " << element[7] << " | " << element[8] << endl;
    cout << "   |   |" << endl;
    return;
}

char Win() {

    // Can make shorter?
    // Horizontal
    if (element[0] == element[1] && element[0] == element[2])
    {
        return element[0];
    }
    if (element[3] == element[4] && element[3] == element[5])
    {
        return element[3];
    }
    if (element[6] == element[7] && element[6] == element[7])
    {
        return element[6];
    }

    // Across
    if (element[0] == element[4] && element[0] == element[8])
    {
        return element[0];
    }
    if (element[2] == element[4] && element[2] == element[6])
    {
        return element[2];
    }

    // Vertical
    if (element[0] == element[3] && element[0] == element[6])
    {
        return element[0];
    }
    if (element[1] == element[4] && element[1] == element[7])
    {
        return element[1];
    }
    if (element[2] == element[5] && element[2] == element[8])
    {
        return element[2];
    }

    // N for null
    return 'N';
}

void WinOrTie() {
    if (Win() != 'N')
    {

        // Present which player won
        switch (Win())
        {
            case 'X':
                cout << "Player 1 wins!" << endl;
                break;
            case 'O':
                cout << "Player 2 wins!" << endl;
                break;

        }
    }
    else
    {
        // No winner, so only tie possible
        cout << "It's a tie! " << endl;
    }
    return;
}

void TicTacToe() {

    int play1, play2;
    int games = 9;
    GameBoard();

    // For 9 squares, play 9 times
    // Needs to stop when one wins
    while (games && Win() == 'N')
    {
        
        cout << "Player 1, choose a square: ";
        cin >> play1;

        // If current square is marked by other player, do not replace
        if(element[play1-1] != 'O')
        {
            cout << play1 << endl;
            element[play1-1] = 'X';
            games--;
        }
        GameBoard();

        if(games && Win() == 'N')
        {
            cout << "Player 2, choose a square: ";
            cin >> play2;

            // If current square is marked by other player, do not replace
            if(element[play2-1] != 'X')
            {
                element[play2-1] = 'O';
                games--;
            }
            GameBoard();
        }
        
    }

    WinOrTie();
    
    return;
}