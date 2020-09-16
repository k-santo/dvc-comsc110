//Objective:  User will guess a number between 1 and 10
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  srand(time(0)); rand(); // seed for random number
  int target =  1 + rand() % 10; // target number between 1 and 10 
  int userGuess; //number between 1 and 10 that the user guesses

  // introduction
  cout << "Objective: User will guess a number between 1 and 10\n written in this course.\n"; 
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << "I'm thinking of a number between 1 and 10" << endl << endl;

  // game loop where the user guesses with input validation and gets guess feedback or exits the game

  while (true)
  {
  cout << "What is your guess [1-10 or 0 to Exit]? ";
  cin >> userGuess;
  cin.ignore(1000, 10);
  if (userGuess == 0)
  {
    break;
  } //if user exits
  else if (userGuess < 1 || userGuess > 10)
  {
    cout << "I really want a number between 1 and 10" << endl;
            
  } // end user guesses invalid input
  else if (userGuess == target)  
  {
    cout << "You guessed it!" << endl;
    break;
  } // right guess
  else
  {
    cout << "Try again..." << endl;
  } //wrong guess
        
  } // end while true loop

} //main