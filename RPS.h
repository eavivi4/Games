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

string LowerWord(string input)
{
    string output;
    for (int i = 0; i < input.size(); i++)
    {
        output += tolower(input[i]);
    }
    return output;
}

void RPS() {

    string play;
    cout << "Welcome to Rock Paper Scissors" << endl;

    // Input validation, need to add condition for just ENTER key
    while (play != "rock" && play != "paper" && play != "scissors")
    {
        cout << "Rock, Paper Scissors! ";
        cin >> play;
        // Make sure input is all lowercase for input validation
        play = LowerWord(play);
    }
    
    

    // Random pick
    vector<string> options = {"Rock", "Paper", "Scissors"};
    srand (time(0));
    string enemy_pick = options[rand() % options.size()];

    // Check conditions
    if(play == "rock")
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
    else if (play == "paper")
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
    else if (play == "scissors")
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
        // Would not arrive here
        return;
    }
    return;
}