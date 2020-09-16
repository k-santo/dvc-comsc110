//Objective: To find how many weeks it takes to be a billionaire, millionaire, and thousandaire if an allowance is doubled each week
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
int piggyBank(int finalAmount); //returns number of weeks for a certain value to be met if allowance is doubled each week


//main program
int main()
{
  //Data
  string objective = "Objective: To find how many weeks it takes to be a billionaire, millionaire, and thousandaire if an allowance is doubled each week"; 

  //user introduction
  introduction(objective);
  
  //output weeks for millionaire, thousandaire, and billionaire
  cout << "In " << piggyBank(1000) << " weeks, I will be a thousandaire" << endl;
  cout << "In " << piggyBank(1000000) << " weeks, I will be a millionaire" << endl;
  cout << "In " << piggyBank(1000000000) << " weeks, I will be a billionaire" << endl;

 

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

//piggy bank function
int piggyBank(int finalAmount){
  
  //finalAmount is the final amount of money looked for
  double netMoney=0.05; //total money in piggy bank
  double allowance=0.05; //allowance per week
  int weeks=1; //number of weeks
    
  while(netMoney<finalAmount){
      allowance=allowance*2;
      netMoney=netMoney+allowance;
      weeks++;
    }
    return weeks;
}