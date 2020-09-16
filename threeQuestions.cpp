//Objective: Ask 3 questions and keep score
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
bool askQuestion(string question, int correctAnswer); //ask user a question, returns correct or incorrect

//main program
int main()
{
  //Data
  string objective = "Objective: Ask 3 questions and keep score"; 
  int correct = 0; //number of answers correct
  string question1 = "Q1) What computer scientist cracked the Enigma Code during WW2? 1)Larry Page 2)Alan Turing 3)Steve Wozniak 4)Vint Cerf ";
  string question2 = "Q2) What is the language C++ based on? 1)Java 2)Python 3)C 4)Fortran ";
  string question3 = "Q3) What defines all of the physical components of a computer? 1)Hardware 2)Software 3)Malware 4)Compiler ";

  //user introduction
  introduction(objective);
  //ask 3 questions
  if (askQuestion(question1, 2) == true) correct++;
  if (askQuestion(question2, 3) == true) correct++;
  if (askQuestion(question3, 1) == true) correct++;
  //output score
  cout << endl << "That's " << correct << " out of 3 correct!";
 

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

//ask user question
bool askQuestion (string question, int correctAnswer)
{

  //data
  //question is the question being asked
  //answer is the answer to the question being asked
  bool result = false;
  int userAnswer;
  //
  cout << question;
  cin >> userAnswer;
  cin.ignore(1000, 10);
  if (userAnswer == correctAnswer) 
  {
     cout << "      Correct!" << endl;
     result = true;
  }
  else
  {
    cout <<      "Incorrect, but a better answer is " << correctAnswer <<endl;
  return result;
  }//if
  
  }//askQuestion