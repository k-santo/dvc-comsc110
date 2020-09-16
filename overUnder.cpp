//Objective:  User will guess a number between 1 and 100
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
  srand(time(0)); rand(); //random number generator
  int target = 1 + rand() % 100; // number between 1 and 100 that the user will attempt to guess
  int userGuess; //guess that the user inputs

  // introduction
  cout << "Objective: User will guess a number between 1 and 100\n";
  cout << "Programmer: Kristofer Santo\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  cout << "I'm thinking of a number between 1 and 100, guess what it is: ";

  // game loop where the user guesses with input validation and gets guess feedback
  while (true)
  {
  cin >> userGuess;
  cin.ignore (1000, 10);
  if (userGuess < 1 || userGuess > 100)
  {
    cout << "Invalid input-- guess again: ";
  } // if user guess is invalid
  else if (userGuess < target)
  {
    cout << "That's too low-- guess again: ";
  } // if user guess is too low
  else if (userGuess > target)
  {
    cout << "That's too high-- guess again: ";
  } // if user guess is too high
  else
  {
    cout << "That's right-- it's " << target;
    break;

  } //if user guess is correct

  } // end while true loop

}//main
