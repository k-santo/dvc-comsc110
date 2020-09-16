//Objective: Prompt the user to input 4 numbers between 0 and 100, and calculate the average of those 4 numbers, and how many of those 4 numbers are above the average.
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
double inputArray(int* n); //input loop for 4 numbers

//main program
int main()
{
  //Data
  string objective = "Objective: Prompt the user to input 4 numbers between 0 and 100, and calculate the average of those 4 numbers, and how many of those 4 numbers are above the average."; 
    int Numbers[3];
    double sum=0.0;
    int input=0;
    int i=0;
    double average=0;
    int count=4;
    int nGreater=0;
  
  //user introduction
  introduction(objective);

  //loop input
  sum = inputArray(Numbers);
  // calculate average
  if (count>0) average = sum/count+1;

  //calculate the number of input values that are greater than average
  for (int i=0; i<count; i++){
    if (average<Numbers[i]) nGreater=nGreater+1;
  }//for

  //output results
  cout.setf(ios::fixed|ios::showpoint);
  cout << "The average of " << count << " numbers is " << setprecision(2) << average << ". ";
  cout << nGreater << " number(s) is/are greater than the average."<< endl;

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

double inputArray(int* n){
  double sum1=0.0;
  int cnt;
  //int Numbers[] is the array

  for(cnt=0; cnt<4; cnt++){
  cout << "Please enter a number [0-100]" << endl;
  cin >> n[cnt];
  cin.ignore(1000,10);
  if (n[cnt]<0 || n[cnt]>100){
    cnt= cnt-1;
  }//if
  else 
    sum1 = sum1 + n[cnt];
  }//for
  return sum1;
}//main