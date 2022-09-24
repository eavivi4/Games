#include <iostream>
#include <fstream>
#include "RPS.h"
using namespace std;
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

   // Only arrive here if registered or correct login info
   cout << "Welcome " << username << "!" << endl;
   cout << "Which game would you like to play? " << endl;
   cout << "1. Rock Paper Scissors" << endl;
   // Add more options
   cout << "2. Other game" << endl;
   cin >> pick;
   switch (pick)
   {
      case 1:
         RPS();
         break;
      default:
         break;
   }

   // Clear user info?
   username = "";
   password = "";
   return 0;
}