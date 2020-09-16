//Objective: To convert a file of celcius values into farenheit
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
void introduction(string obj); //user introduction

//main program
int main()
{
  //Data
  string objective = "Objective: To convert a file of celcius values into farenheit";
  string tempFile = "temps.txt";
  double celcius; //celcius value to be converted into farenheit
  double fahrenheit; // farenheit value to be converted from celcius
  ifstream fin; //file input
  ofstream fout; //file output

  //user introduction
  introduction(objective);

  //convert the value of each celcius value into farenheit
    fin.open(tempFile.c_str());
    if (!fin.good()) throw "I/O error";
  while (celcius!=-999){
    fin >> celcius;
    fin.ignore(1000, 10);
    if (celcius!=-999){
      fahrenheit = (9.0/5.0)*celcius+32.0;
      cout << cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(0) << celcius << " Celcius equals " << setprecision(1) << fahrenheit << " fahrenheit" << endl;
    }//if
  }//while
  fin.close();
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