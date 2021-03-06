//Objective: To allow for the user to input a file for its lines to be encoded and outputted into another file and the console
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
const int SIZE=4;

//Programmer defined functions
string lineEncoder(string line1, int* o, int size1); //encode line by +1 ASCII value

//main program
int main()
{
  //Data
  string objective = "Objective: To allow for the user to input a file for its lines to be encoded and outputted into another file and the console"; 
  ifstream fin; //file input
  ofstream fout; //file output
  string line;// string of text for line
  string fileName;//name of the file input
  string secretFile = "secret.txt"; //name of file output
  int i;//loop index
  int offset[SIZE]= {5, 3, -1, 5};

  //prompt user to enter name of text file
  cout << "Please enter the name of the text file you wish to encode: ";
  getline (cin, fileName);

  //open input file
  fin.open (fileName.c_str ());
  if (!fin.good ()) throw "I/O error";
  
  //open output file
  fout.open (secretFile.c_str ());
  if (!fout.good ()) throw "I/O error";
  
  //convert line and output encoded line.
  while(fin.good())
  {
    getline(fin, line);
    line = lineEncoder(line, offset, SIZE);
    fout << line << endl;
    cout << line << endl;
  }//while
  
  //close both files
  fin.close();
  fout.close();
  
  fout.open("offset.txt");
  if (!fout.good()) throw "I/O error";
  
  fout << SIZE << endl;
  for(i=0; i<SIZE; i++)
  {
    fout << offset[i] << endl;
  }
  
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

//encode line into +1 ASCII value
string lineEncoder(string line1, int* o, int size1){
  //data
  //line1 is the line to be encoded
  int i; //index loop
  int j; // 2nd index loop

  for (i = 0; i < line1.length(); i++)
  {
    for (j = 0; j < size1; j++){
      line1[i] = line1[i] + o[j];
      i++;
    }//for
  }//for
  return line1;
}//lineEncoder
