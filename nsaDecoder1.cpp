//Objective: To allow for the user to input a file for its lines to be decoded and outputted by the console
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
string lineDecoder(string line1); //decode line by -1 ASCII value

//main program
int main()
{
  //Data
  string objective = "Objective: To allow for the user to input a file for its lines to be decoded and outputted by the console"; 
  ifstream fin; //file input
  ofstream fout; //file output
  string line;// string of text for line
  string secretFile = "secret.txt"; //name of file input
  int i;//loop index


  //open input file
  fin.open (secretFile.c_str ());
  if (!fin.good ()) throw "I/O error";
  
  //convert line and output encoded line.
  while(fin.good())
  {
    getline(fin, line);
    line = lineDecoder(line);
    cout << line << endl;
  }//while
  
  //close both files
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

//encode line into -1 ASCII value
string lineDecoder(string line1){
  //data
  //line1 is the line to be decoded
  int i; //index loop

  //decode line to -1 ASCII value
  for (i = 0; i < line1.length(); i = i + 1)
  {
    line1[i] = line1[i] - 1; 
  }//for
  return line1;
}//lineEncoder
