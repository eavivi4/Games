#include <iostream>
#include "RPS.h"
using namespace std;

int main() {
   string username, password; 
   int pick;
   cout << "Welcome to the GameHub" << endl;
   cout << "Please Enter a username: ";
   cin >> username;

   // Have password hidden?
   cout << "Please Enter a password: ";
   cin >> password;

   cout << "Welcome " << username << "!" << endl;
   cout << "Which game would you like to play? " << endl;
   cout << "1. Rock Paper Scissors" << endl;
   // Add more options
   cout << "2. Other game" << endl;
   cin >> pick;
   if (pick == 1)
   {
    RPS();
   }
   return 0;
}