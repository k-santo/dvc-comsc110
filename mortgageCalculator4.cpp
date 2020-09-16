//Objective: To calculate and output the monthly cost over 30 years of a fixed loan
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

//Programmer defined data types
struct Mortgage{
  int amountBorrowed; //the specified amount borrowed (user specified)
  double anInterestRate; //the percent annual interest rate (user specified)
  double nMonthlyPayments; // the number of monthly payments
  double monthlyPayment; //the calculated monthly payment
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
bool getPassword(); //get password to continue
void getMortgageValues(Mortgage& mort); //input mortgage values
void calculateMortgageData(Mortgage& mort); //calculate the monthly payment
void outputMortageData(Mortgage& mort); //output mortgage data into console and mortgage.txt

//main program
int main()
{
  //Data
  string objective = "Objective: To calculate and output the monthly cost over 30 years of a fixed loan "; 
  struct Mortgage mort;
  
  //Perform Mortgage input, calculations, and output if password is correct
  if(getPassword()==true)
  {
    getMortgageValues(mort);
    calculateMortgageData(mort);
    outputMortageData(mort);
  }//if
  
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

void getMortgageValues(Mortgage& mort)
{
  //data
  //mort is the Mortgage object
  
  //enter amount borrowed
  cout << "Please enter the amount borrowed: ";
  cin >> mort.amountBorrowed;
  cin.ignore(1000, 10);
  
  //enter annual interest rate
  cout << "Please enter the annual interest rate: ";
  cin >> mort.anInterestRate;
  cin.ignore(1000, 10);
  
  //calculate number of monthly payments over 30 years
  mort.nMonthlyPayments = 12 * 30;
}//getMortgageValues

void calculateMortgageData(Mortgage& mort)
{
  //data
  //mort is the mortgage object
  double monInterestRate = mort.anInterestRate / 1200; //decimal monthly interest rate
  
  //calculate monthly payment
  mort.monthlyPayment = (mort.amountBorrowed*(pow(1+monInterestRate, mort.nMonthlyPayments)*monInterestRate)/((pow(1+monInterestRate, mort.nMonthlyPayments))-1));
}//calculateMortgageData

void outputMortageData(Mortgage& mort)
{
  //data
  //mort is the mortgage object
  ofstream fout; //output File
  string fileName = "mortgage.txt"; //name of output file
  cout.setf(ios::fixed|ios::showpoint); //formatting for console output
  fout.setf(ios::fixed|ios::showpoint); //formatting for file output
  
  //output into console
  cout << "Amount Borrowed: $" << mort.amountBorrowed << endl;
  cout << "Annual Interest Rate: " << setprecision(3) << mort.anInterestRate << "%" << endl;
  cout << "Payback period: 30 years" << endl;
  cout << "Monthly Payment: $" << setprecision(2) << mort.monthlyPayment << endl;
  
  //output into file
  fout.open(fileName);
  if (!fout.good()) throw "I/O error"; 
  fout << "Amount Borrowed: $" << mort.amountBorrowed << endl;
  fout << "Annual Interest Rate: " << mort.anInterestRate << "%" << endl;
  fout << "Payback period: 30 years" << endl;
  fout << "Monthly Payment: $" << setprecision(2) << mort.monthlyPayment << endl;
  fout.close();
  
}//outputMortageData

bool getPassword()
{
  //data
  int triesLeft=3;
  bool isCorrectPassword= false;
  string correctPassword = "1768976";
  string userResponse;
  
  //give user 3 tries to unlock mortgage
  for(triesLeft = 3; triesLeft>0, triesLeft--;)
  {
    cout << "Please enter the password (Author's ID Number): ";
    getline(cin, userResponse);
    if (userResponse == correctPassword)
    {
      isCorrectPassword= true;
      break;
    }//if
    else
    {
      if (triesLeft == 1)
      {
        cout << "Incorrect password. You have " << triesLeft  << " try left." << endl;
      }//if
      else
      {
        cout << "Incorrect password. You have " << triesLeft  << " tries left." << endl;
      }//else
    }//else
  }//for
  return isCorrectPassword;
}//getPassword
