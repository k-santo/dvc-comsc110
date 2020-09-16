//Objective:
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
void output(string in, string out); // output

//main program
int main()
{
  //Data
  string objective = "Objective: "; 
  string dFileName ="fileContainingEmails.txt"; // default file name
  string iFileName; //input file name
  string oFileName; //output file name

  cout << "Enter input filename [default:" << dFileName << "]: ";
  getline(cin, iFileName);
  if(iFileName.length()==0) 
  {
    iFileName=dFileName;
    dFileName="copyPasteMyEmails.txt";
  }
  while(!(iFileName[iFileName.length()-1]=='t' && iFileName[iFileName.length()-3]=='t' && iFileName[iFileName.length()-2]=='x' && iFileName[iFileName.length()-4]=='.' && iFileName.length()>=5))
  {
    cout << "Must be a 'txt' file more than 4 characters long. Enter input filename [default:" << dFileName << "]: ";
    getline(cin, iFileName);
    if(iFileName.length()==0) 
    {
      iFileName=dFileName;
      dFileName="copyPasteMyEmails.txt";
    }
  }//while
  dFileName="copyPasteMyEmails.txt";
  
  cout << "Enter output filename [default:" << dFileName << "]: ";
  getline(cin, oFileName);
  if(oFileName.length()==0) oFileName=dFileName;
  while(!(oFileName[oFileName.length()-1]=='t' && oFileName[oFileName.length()-3]=='t' && oFileName[oFileName.length()-2]=='x' && oFileName[oFileName.length()-4]=='.' && oFileName.length()>=5))
  {
    cout << "Must be a 'txt' file more than 4 characters long. Enter output filename [default:" << dFileName << "]: ";
    getline(cin, oFileName);
  }//while
  
  output(iFileName, oFileName);

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

void output(string in, string out)
{
  //data
  //in is the name of the input file
  //out is the name of the output file
  
  //output names of files
  cout << "Input file: " << in << endl;
  cout << "Output file: " << out;
}//output
