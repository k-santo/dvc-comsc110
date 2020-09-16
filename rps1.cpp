//Objective: To allow the user to play a game of rock paper scissors with the computer, using random number generation
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
void introduction(string obj); //user introduction
int computerPlay(); //computer's play, returns 0-2 based on what computer will play for RPS
int userPlay(); //user's play, returns 0-2 based on what user chooses to play for RPS
int scoring(int compPlay, int userPlay1); //determines who won, returns 0-2 based on who won (0-tie, 1-user, 2-computer)


//main program
int main()
{
  //Data
  string objective = "Objective: To allow the user to play a game of rock paper scissors with the computer, using random number generation"; 
  int scoreChecker; //checker for who scored, used as a conditional of whether the computer or user won
  int userScore = 0; //user's overall score
  int computerScore = 0; //computer's overall score
  int usersPlay; //what user's play is rock, paper, or scissors (or quit)
  int computersPlay; //what computer's play is (randomly generated) 
  bool continueGame = true; //whether to continue the game or not

  //user introduction
  introduction(objective);
  
  // check to see who winner is, keep score, loop
  while (continueGame == true){
    usersPlay = userPlay();
    if (usersPlay == 3) continueGame = false;
    if (continueGame == true){
    computersPlay = computerPlay();
    scoreChecker = scoring(usersPlay, computersPlay);
    if (scoreChecker == 1) userScore++;
        else if (scoreChecker == 2) computerScore++;
    cout << endl << "Player Score: " << userScore << " Computer Score: " << computerScore << endl;
    } //if
  } //while
  cout << endl << "Thanks for playing!";

 

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
  cout << "Welcome to the game of Rock, Paper, Scissors. You will be asked to choose either R=rock or P=paper or S=scissors, and the computer will do the same. The winner is determined by Rock wins against Scissors, or Scissors wins against Paper, or Paper wins against Rock. The game winner is the player with the most scores. The best player is the player with the highest overall score." << endl;
 
}//introduction

int computerPlay(){
  
  //data
  srand(time(0)), rand(); //seed random number generator
  int computerChoice = rand()%3; //computer choice (3 choices, 0-2) for rock, paper, or scissors
  return computerChoice;
} //computerPlay

int userPlay(){
  //data
  char userInput; //what user will input
  int userChoice; //whether user choice rock, paper, scissors, or quit

  //user inputs r, p, s, or q for rock, paper, scissors, or quit
  cout << "Choose: [R=rock, P=paper, S=scissors, or Q=quit] ";
  cin >> userInput;
  cin.ignore(1000, 10);
  
  //transfer userInput to userChoice (char to int)
  if (userInput == 'R' || userInput == 'r') userChoice = 0;
      else if (userInput == 'P' || userInput == 'p') userChoice = 1;
          else if (userInput == 'S' || userInput == 's') userChoice = 2;
              else if (userInput = 'Q' || userInput == 'q') userChoice = 3;
  return userChoice;
} //userPlay

int scoring(int compPlay, int userPlay1) {

  //data
  // userPlay1 is the user's play
  //compPlay is the computer's play
  int score=0; // score indicator

  // determine who won
  if (compPlay == userPlay1) {
      cout << endl << "tie";
  } //if
  else if (userPlay1 == 0 && compPlay == 2){
      score = 1;
      cout << endl << "Player wins!";
  } //if else
  else if (userPlay1 == 1 && compPlay == 0){
      score = 1;
      cout << endl << "Player wins!";
  } //if else
  else if (userPlay1 == 2 && compPlay == 1){
      score = 1;
      cout << endl << "Player wins!";
  } //if else
  else 
  {
      cout << "Player loses!";
      score = 2;
  } //else
  return score;
} //scoring

