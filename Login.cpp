#include <iostream>
#include <fstream>
#include "RPS.h"
#include "TTT.h"
#include "Snake.h"
using namespace std;

class User {
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
         //score = 0;
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

bool LoginFunc (string username, string password)
{
   string e_username, e_password;
   // If username exists
   ifstream file(username + ".txt");
   getline(file, e_username);
   getline(file, e_password);
   if (username == e_username && password == e_password)
   {
      return true;
   }
   return false;
}

void RegisterFunc(string username, string password)
{
   // If username does not exist
   ofstream file;
   file.open(username + ".txt");
   file << username << endl << password;
   file.close();
}

int main() {
   string option, username, password;
   int pick;
   User mainUser = User();
   cout << "Welcome to the GameHub" << endl;
   cout << "Would you like to login or register? ";
   // Input validation missing?
   cin >> option;

   cout << "Please Enter a username: ";
   cin >> username;
   // Have password hidden?
   cout << "Please Enter a password: ";
   cin >> password;

   // Register or login
   if (option == "register")
   {
      RegisterFunc(username, password);
   }
   else if (option == "login" && !LoginFunc(username, password))
   {
      cout << "Wrong username or password..." << endl;
      main();
   }
   else if (option != "login")
   {
      cout << "No such option..." << endl;
      main();
   }

   mainUser.SetUsername(username);
   mainUser.SetPassword(password);

   // Only arrive here if registered or correct login info
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

   // Clear user info?
   username = "";
   password = "";
   return 0;
}