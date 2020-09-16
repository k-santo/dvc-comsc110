//Objective: User will guess a number between 1 and 100
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
const int MAX_SIZE=100; //maximum size of dupGuesses list

//Programmer defined functions
void introduction(string obj); //user introduction
bool isDupGuess(deque<int>& dupGuesses, int nDupGuesses1, int userGuess1); //check if user guess is a duplicate
bool isValidInput(int userGuess2); //checks if valid input

//main program
int main()
{
  //Data
  string objective = "Objective: User will guess a number between 1 and 100"; 
  deque<int> dupGuesses; //collection of duplicate guesses 
  srand(time(0)); rand(); //random number generator
  int target= 1 + rand() %100; //target number 
  ofstream fout; //output file
  ifstream fin; //input file
  int userGuess; // what the user guesses
  bool checkDupGuess; //checks if duplicate guess
  bool checkValidInput; //checks if valid input
  string scoreLine; // line inputted showing previous player's score
  int nGuesses=0; //number of guesses
  
  //input last score
  fin.open("scores.txt");
  getline(fin, scoreLine);
  fin.close();
  cout << scoreLine << endl;
  
  //user instructions
  cout << "I'm thinking of a number between 1 and 100. Guess what it is [-999 to quit]: ";
  while(true)
  {
    cin >> userGuess;
    cin.ignore (1000, 10);
    if (userGuess==-999) break; //check for sentinel value
    
    //check for valid input
    checkValidInput= isValidInput(userGuess); 
    if (checkValidInput==false) cout << "Invalid input-- guess again: ";
    
    if (checkValidInput==true)
    {  
      checkDupGuess= isDupGuess(dupGuesses, dupGuesses.size(), userGuess); //check for duplicate guess
      
      if(checkDupGuess==true) cout << "You already guessed " << userGuess << " -- guess again: ";
      
      //score loop, add guess to list
      if (checkDupGuess==false)
      {
        if (dupGuesses.size() < MAX_SIZE) dupGuesses.push_back(userGuess); //add guess to list
        if (userGuess < target)
        {
          cout << "That's too low-- guess again: ";
        } // if user guess is too low
        else if (userGuess > target)
        {
          cout << "That's too high-- guess again: ";
        } // if user guess is too high
        else
        {
          cout << "That's right-- it's " << target << endl;
          break;
        }//right answer
      }//if (dupGuess)
    }//if (valid input)
    nGuesses++;
  }//while
  //output score
  cout << "Player took " << nGuesses << " guesses to guess the correct number.";
  fout.open("scores.txt");
  fout << "Last player took " << nGuesses << " guesses to guess the correct number.";
  fout.close();
}//main

//user introduction
void introduction(string obj)
{
  
  //data
  //obj is the program objective
  
  // introduction
  cout << obj;
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
 
}//introduction

bool isDupGuess(deque<int>& dupGuesses, int nDupGuesses1, int userGuess1)
{
  //data
  //dupGuesses is the list of duplicate guesses
  //userGuess1 is the user's guesses
  //nDupGuesses1 is the number of duplicate guesses
  bool checker=false; //checks if it is a duplicate guess
  int i=0;
  
  for(i=0; i<dupGuesses.size(); i++)
  {
    if(dupGuesses[i]==userGuess1) checker=true;
  }//for
  return checker;
}//isDupGuess

bool isValidInput(int userGuess2)
{
  //data
  //userGuess2 is the user's guess
  bool validInputChecker=true; //is valid input?
  if (userGuess2 < 1 || userGuess2 > 100)
  {
    validInputChecker=false;
  } // if user guess is invalid
  return validInputChecker;
}//isValidInput