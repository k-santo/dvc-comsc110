//Objective: calculate a value in the "Fibonacci number" series
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables

//Programmer defined functions
void introduction(string obj); //user introduction
int fibonacci(int index); //finds the fibonacci number given the index of the sequence

//main program
int main()
{
  //data
  string objective = "Objective: calculate a value in the 'Fibonacci number' series"; 
  int fibonacciIndex; //
  int fibonacciNumber; //the Fibonacci number that is calculated from the index
  //introduction
  introduction(objective);

  //input fibonacci index from user
  cout << "Enter an index [0 or greater]: ";
  cin >> fibonacciIndex;
  cin.ignore(1000, 10);
  
  //calculate fibonacci number from 
  fibonacciNumber=fibonacci(fibonacciIndex);
  cout << "The Fibonacci number at index " << fibonacciIndex << " is " << fibonacciNumber;
}//main

//user introduction
void introduction(string obj)
{
  
  //data
  //obj is the program objective
  
  // introduction
  cout << obj << endl;
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
 
}//introduction

void output(string in, string out)
{
  //data
  //in is the name of the input file
  //out is the name of the output file
  
  //output names of files
  cout << "Input file: " << in << endl;
  cout << "Output file: " << out;
}//output

int fibonacci(int index)
{
  //data
  //index is the index of the fibonacci number

  //find fibonacci number
  if (index == 0) return 0;
  if (index <= 2)
  {
    return 1;
  }//if
  else
  {
    return fibonacci(index - 1) + fibonacci(index - 2);
  }//else
}//fibonacci
