#include <iostream>
#include <vector>
using namespace std;

void WinFunction(string enemy_pick)
{
    cout << "Congratulations, you win!" << endl;
    cout << "Enemy picked: " << enemy_pick << endl;
}

void LoseFunction(string enemy_pick)
{
    cout << "Sorry, you lost..." << endl;
    cout << "Enemy picked: " << enemy_pick << endl;
}

void TieFunction(string enemy_pick)
{
    cout << "It's a tie" << endl;
    cout << "Enemy picked: " << enemy_pick << endl;
}

void RPS() {
    string play;
    cout << "Welcome to Rock Paper Scissors" << endl;
    cout << "Rock, Paper Scissors! ";
    cin >> play;

    // Random pick
    vector<string> options = {"Rock", "Paper", "Scissors"};
    srand (time(0));
    string enemy_pick = options[rand() % options.size()];

    // Check conditions
    if(play == "Rock")
    {
        if(enemy_pick == "Scissors")
        {
            // Win function
            WinFunction(enemy_pick);
        }
        else if (enemy_pick == "Paper")
        {
            // Lose function
            LoseFunction(enemy_pick);
        }
        else
        {
            // Tie function
            TieFunction(enemy_pick);
        }
    }
    else if (play == "Paper")
    {
        if(enemy_pick == "Rock")
        {
            // Win function
            WinFunction(enemy_pick);
        }
        else if (enemy_pick == "Scissors")
        {
            // Lose function
            LoseFunction(enemy_pick);
        }
        else
        {
            // Tie function
            TieFunction(enemy_pick);
        }
    }
    else if (play == "Scissors")
    {
        if(enemy_pick == "Paper")
        {
            // Win function
            WinFunction(enemy_pick);
        }
        else if (enemy_pick == "Rock")
        {
            // Lose function
            LoseFunction(enemy_pick);
        }
        else
        {
            // Tie function
            TieFunction(enemy_pick);
        }
    }
    else
    {
        // Fix for input validation
        cout << "Incorrect input" << endl;
    }
    return;
}