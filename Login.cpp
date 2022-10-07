#include <iostream>
#include <fstream>
#include <string>
#include "RPS.h"
#include "TTT.h"
#include "Snake.h"
using namespace std;

class User {

   // Class User that keeps track of user's information 
   private:
      string username, password;
      int score;
   public: 
      User() {
         username = "";
         password = "";
         score = 0;
      }
      ~User() {
         username = "";
         password = "";
      }
      string GetUsername() {
         return username;
      }
      void SetUsername(string u) {
         username = u;
         return;
      }
      string GetPassword() {
         return password;
      }
      void SetPassword(string p) {
         password = p;
         return;
      }
      void AddScore(int s) {
         score += s;
         return;
      }
      int GetScore() {
         return score;
      }
};

bool LoginFunc (string username, string password, int &s)
{
   string f_username, f_password, f_score;

   // If username exists, check username and password and store score in variable
   ifstream file(username + ".txt");
   getline(file, f_username);
   getline(file, f_password);
   getline(file, f_score);
   if (username == f_username && password == f_password)
   {
      s = stoi(f_score);
      return true;
   }
   return false;
}

void RegisterFunc(string username, string password, int s)
{
   // Register the user or just insert the score
   ofstream file;
   file.open(username + ".txt");
   file << username << endl << password << endl << s;
   file.close();
   return;
}

void Hub(User mainUser) {
   string answer;
   int pick;

   // Either user is logged in or needs to register later to arrive in the hub
   cout << "-----------------------------------------" << endl;
   cout << "Welcome " << mainUser.GetUsername() << "!" << endl;
   cout << "Your current score is: " << mainUser.GetScore() << endl;
   cout << "-----------------------------------------" << endl;
   cout << "Which game would you like to play? " << endl;
   cout << "1. Rock Paper Scissors" << endl;
   cout << "2. Tic Tac Toe" << endl;
   cout << "3. Snake" << endl;
   cout << "4. Exit" << endl;
   cin >> pick;

   // Choose the game based on user input
   switch (pick)
   {
      case 1:
         mainUser.AddScore(RPS());
         break;
      case 2:
         // No score, two players
         TicTacToe();
         break;
      case 3:
         mainUser.AddScore(SnakeGame());
         break;
      default:
         break;
   }

   // Have score inserted into file for user so it is remembered for next time
   RegisterFunc(mainUser.GetUsername(), mainUser.GetPassword(), mainUser.GetScore());

   // Ask user if to return to hub for another game if they didn't exit
   if (pick != 4)
   {
      cout << "Would you like to play another game from the hub? yes/no" << endl;
      cin >> answer;  
      if (answer == "yes")
      {
         // If the user did not choose to exit, continue with prompt
         Hub(mainUser);
      }
      
      // Any other answer, except for y, would result in exiting the hub
      else if (answer == "no")
      {
         return;
      }
      else
      {
         cout << "Invalid answer, exiting the hub" << endl;
         return;
      }
   }
   return;
   
}

int main() {
   string option, username, password;
   int score = 0;
   User mainUser = User();

   cout << "Welcome to the GameHub" << endl;
   cout << "Would you like to login or register? ";
   cin >> option;
   if (option != "login" && option != "register")
   {
      // Input validation
      cout << "No such option..." << endl;
      main();
   }

   cout << "Please Enter a username: ";
   cin >> username;
   
   char ch;
   cout << "Please Enter a password: ";

   // Have password hidden, while it is not enter
   ch = getch();
   while (ch != 13)
   {
      password.push_back(ch);
      cout << "*";
      ch = getch();
   }
   cout << endl;

   // Check if login is correct, if selected login
   if (option == "login" && !LoginFunc(username, password, score))
   {
      cout << "Wrong username or password..." << endl;
      main();
   }

   // Setup the object
   mainUser.SetUsername(username);
   mainUser.SetPassword(password);
   mainUser.AddScore(score);

   Hub(mainUser);

   return 0;
}