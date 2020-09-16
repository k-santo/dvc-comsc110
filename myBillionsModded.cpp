//Objective: To find how many weeks it takes to be a billionaire, millionaire, and thousandaire if an allowance is doubled each week (with user input)
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
int piggyBank(int finalAmount, double netMoney, double allowance); //returns number of weeks for a certain value to be met if allowance is doubled each week

//main program
int main()
{
  //Data
  string objective = "Objective: To find how many weeks it takes to be a billionaire, millionaire, and thousandaire if an allowance is doubled each week(with user input)"; 
  double weeklyAllowance; //weekly allowance doubled each week
  double initialAmount; //initial amount of money
  //user introduction
  introduction(objective);
  
  //input allowance and initial money in piggy bank
  cout << "How much money (in dollars; if cents, enter as decimal) do you have right now? ";
  cin >> initialAmount;
  cin.ignore(1000,10);
  cout << endl << "How much money (in dollars; if cents, enter as decimal) will you earn on your first week? Allowance will double each week! ";
  cin >> weeklyAllowance;
  cin.ignore(1000,10);
  
  //output weeks for millionaire, thousandaire, and billionaire
  cout << "In " << piggyBank(1000, initialAmount, weeklyAllowance) << " weeks, you will be a thousandaire" << endl;
  cout << "In " << piggyBank(1000000, initialAmount, weeklyAllowance) << " weeks, you will be a millionaire" << endl;
  cout << "In " << piggyBank(1000000000, initialAmount, weeklyAllowance) << " weeks, you will be a billionaire" << endl;

 

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
int piggyBank(int finalAmount, double netMoney, double allowance){
  
  //finalAmount is the final amount of money looked for
  int weeks=1; //number of weeks
    
  while(netMoney<finalAmount){
      allowance=allowance*2;
      netMoney=netMoney+allowance;
      weeks++;
    }
    return weeks;
}