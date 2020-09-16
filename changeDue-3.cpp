//Objective: Calculate change due in a transaction, inputting from a file the change paid and the total amount owed, using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: Calculate change due in a transaction, inputting from a file the change paid and the total amount owed, using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills "; 
  string instructions = "Instructions: Please make sure that the file 'change.txt' has the amountOwed on line 1 and cashPaid on line 2. Please enter '1' to continue. ";
  string changeFile = "change.txt";
  ifstream fin;
  ofstream fout;
  int checker;
  int amountOwed; //amount owed
  int cashPaid;  //amount paid
  int totalChangeDue; //counter total change due
  int originalChangeDue; //original change due
  int thousand100; //number of $100000 bills
  int thousand10; //number of $10000 bills
  int thousand5; //number of $5000 bills
  int thousand;  //number of $1000 bills
  int hundred5; //number of $500 bills
  int hundred;  //number of $100 bills
  int fifty;  //number of $50 bills
  int twenty; //number of $20 bills
  int ten;  //number of $10 bills
  int five;  //number of $5 bills
  int two; //number of $2 bills
  int one;  //number of $1 bills

  //user introduction
  introduction(objective, instructions);
  cin >> checker;
  cin.ignore(1000, 10);
  
  //input amountOwed and cashPaid from change.txt file
  fin.open(changeFile.c_str());
  if (!fin.good()) throw "I/O error"; 
  fin >> amountOwed;
  fin.ignore(1000, 10);
  fin >> cashPaid;
  fin.ignore(1000, 10);
  fin.close();
  
  //calculate change due
  totalChangeDue = cashPaid-amountOwed;
  originalChangeDue = totalChangeDue;
  thousand100 = totalChangeDue / 100000;  //number of $100,000 bills
  totalChangeDue = totalChangeDue % 100000;  //remainder from $100,000
  thousand10 = totalChangeDue / 10000;  //number of $10,000 bills
  totalChangeDue = totalChangeDue % 10000; //remainder from $10,000
  thousand5 = totalChangeDue / 5000;  //number of $5,000 bills
  totalChangeDue = totalChangeDue % 5000; //remainder from $5,000
  thousand = totalChangeDue / 1000;  //number of $1,000 bills
  totalChangeDue = totalChangeDue % 1000; //remainder from $1,000
  hundred5 = totalChangeDue / 500;  //number of $500 bills
  totalChangeDue = totalChangeDue % 500; //remainder from $500
  hundred = totalChangeDue / 100;  //number of $100 bills
  totalChangeDue = totalChangeDue % 100; //remainder from $100
  fifty = totalChangeDue / 50;  //number of $50 bills
  totalChangeDue = totalChangeDue % 50; //remainder from $50
  twenty = totalChangeDue / 20;  //number of $20 bills
  totalChangeDue = totalChangeDue % 20; //remainder from $20
  ten = totalChangeDue / 10;  //number of $10 bills
  totalChangeDue = totalChangeDue % 10; //remainder from $10
  five = totalChangeDue / 5;  //number of $5 bills
  totalChangeDue = totalChangeDue % 5; //remainder from $5
  two = totalChangeDue / 2;  //number of $2 bills
  totalChangeDue = totalChangeDue % 2; //remainder from $2
  one = totalChangeDue / 1;  //number of $1 bills
  totalChangeDue = totalChangeDue % 1; //remainder from $1


 

  //output calculated change due for each kind of monetary demonination
  cout << "Amount owed: " << amountOwed << endl;
  cout << "Cash paid: " << cashPaid << endl;
  cout << "Total change due: " << originalChangeDue << endl;
  cout << "this many $100,000 bills: " << thousand100 << endl;
  cout << "this many $10,000 bills: " << thousand10 << endl;
  cout << " this many $5,000 bills: " << thousand5 << endl; 
  cout << " this many $1,000 bills: " << thousand << endl; 
  cout << " this many $500 bills: " << hundred5 << endl; 
  cout << " this many $100 bills: " << hundred << endl; 
  cout << " this many $50 bills: " << fifty << endl; 
  cout << " this many $20 bills: " << twenty << endl; 
  cout << " this many $10 bills: " << ten << endl; 
  cout << " this many $5 bills: " << five << endl; 
  cout << " this many $2 bills: " << two << endl; 
  cout << " this many $1 bills: " << one << endl; 
 

}//main

//user introduction
void introduction(string obj, string ins)
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
  cout << ins << endl;
 
}//introduction