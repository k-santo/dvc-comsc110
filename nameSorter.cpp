//Objective:To read names in a text file, sort them alphabetically, and output them to the screen
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
const int MAX_NAMES=5; //max number of names

//Programmer defined functions
void introduction(string obj); //user introduction
string inputFileName(); //inputs the name of file containing names
void outputSortNames(string* name, int numNames); //output sorted names

//main program
int main()
{
  //Data
  ifstream fin; //input file
  string objective= "Objective: to read names in a text file, sort them alphabetically, and output them to the screen";
  int nNames=0; //number of names
  string name[MAX_NAMES]; //list of names
  string aName; //temporary name
  string fileName; //name of file
  
  //introduction
  introduction(objective);
  
  //input file name
  fileName=inputFileName();
  
  //open file and input names
  fin.open(fileName);
  if (!fin.good()) throw "I/O error";
  while(fin.good())
  {
    getline(fin, aName);
    if(aName.length()>0)
    {
      if (nNames < MAX_NAMES) name[nNames++] = aName;
    }//if
  }//while
  
  //sort and output sorted names
  outputSortNames(name, nNames);

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

string inputFileName()
{
  //data
  string fName; //name of file
  
  cout << "Enter the name of the file containing names: ";
  getline(cin, fName);
  return fName;
}//inputFileName

void outputSortNames(string* name, int nNames)
{
  //data
  //name is the list of names
  //numNames is the number of names
  int i; //index loop
  int j; //index loop
  string tempName; //temporary name
  
  for (i = 0; i < nNames; i++)
  {    
    for (j = i + 1; j < nNames; j++)   
    { 
      if (name[i] > name[j])      
      {         
        tempName = name[i]; 
        name[i] = name[j];
        name[j] = tempName;     
      } // if     
    } // for j  
  } // for i
  
  for(i=0; i<nNames; i++)
  {
    cout << name[i] << endl;
  }//for
}//outputSortedNames
