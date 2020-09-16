//Objective: To input file names and check if the input file name has an email
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
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
void output(string in, string out); // output
bool isValidEmailChar (char c); //Returns true if c is a valid email address character, else false
int processLine(string lineFromFile); //output the line each time an @ is found in the line and return number of @'s
string getFileName (string fileType, string dFileName); //outputs variable prompt with default filename and gets a filename (either input or output) using input validation and returns the fileName depending on user
void readFile(string iFileName); //reads input file until EOF that calls function processLine for each line read from the input file

//main program
int main()
{
  //Data
  string objective = "Objective: To input file names and check if the input file name has an email "; 
  string dFileName ="fileContainingEmails.txt"; // default file name
  string iFileName; //input file name
  string oFileName; //output file name
  
  //input and output names of files 
  iFileName= getFileName("input", dFileName);
  dFileName= "copyPasteMyEmails.txt";
  oFileName= getFileName("output", dFileName);
  output(iFileName, oFileName);
  
  //output if line has email in it
  readFile(iFileName);
  
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
  cout << "Output file: " << out << endl;
}//output

int processLine(string lineFromFile)
{
  //data
  //lineFromFile is the line that is inputted from the input file
  //s represents the start of the email
  //e represents the end of the email
  //hasDot represents whether or not the email has a dot
  //dotPos represents the position of the dot
  int i; //index loop, represents where @ is
  int numEmails=0; //total number of emails
  string anEmail; //the email substring to be outputted

    for (i=0; i<lineFromFile.length(); i++)
    {
      if (isValidEmailChar(lineFromFile[i]))
      {
        if (lineFromFile[i]=='@')
        {
          int s; //2nd index loop, represents start
          for(s=i-1; s>= 0; s--)
          {
            if(!isValidEmailChar(lineFromFile[s]))
            {
              break;
            }//if
          }//for 
          s++;
          int e; //3rd index loop, represents end
          bool hasDot=false;
          int dotPos=0;
          for(e=i+1; e<lineFromFile.length(); e++)
          {
            if(lineFromFile[e] =='.')
            {
              hasDot = true;
              dotPos = e;
            }//if
            else if(!isValidEmailChar(lineFromFile[e]))
            {
              break;
            }//if 
          }//for
          if (e > i && s < i && hasDot && dotPos >= (i+1))
          {
            anEmail=lineFromFile.substr(s, e-s);
	    cout << anEmail << endl;
            numEmails++;
          }//if
        }//if
      }//if
    }//for
    
    return numEmails;
}//processLine

string getFileName (string fileType, string dFileName)
{
  //data
  //fileType is the type of the file name to be inputted
  //dfileName is the default filename
  string fileName; //name of file
  
  cout << "Enter " << fileType << " filename [default:" << dFileName << "]: ";
  getline(cin, fileName);
  if(fileName.length()==0) fileName=dFileName;
  while(!(fileName[fileName.length()-1]=='t' && fileName[fileName.length()-3]=='t' && fileName[fileName.length()-2]=='x' && fileName[fileName.length()-4]=='.' && fileName.length()>=5))
  {
    cout << "Must be a 'txt' file more than 4 characters long. Enter " << fileType << " filename [default:" << dFileName << "]: ";
    getline(cin, fileName);
    if(fileName.length()==0) fileName=dFileName;
  }//while
  return fileName;
}//getFileName

void readFile(string iFileName)
{
  //data
  //iFileName is the input file's name
  string inLine; //input line
  ifstream fin; //input files
  int inEmails=0; //number of emails
  int nEmails=0; //sum of all emails
  fin.open(iFileName);
  while (fin.good())
  {
     
    getline(fin, inLine);
    inEmails=processLine(inLine);
    nEmails= nEmails + inEmails;
  }//while
  cout << "The total number of emails is " << nEmails;
}//readFile

bool isValidEmailChar(char c)
{
  //data
  //c is the character being tested
  bool result=false; //the result if valid character or not
  
  if ((c>= 'A' && c <= 'Z') || (c>= 'a' && c<= 'z') || (c=='_') || (c=='+') || (c=='-') || (c=='.') || (c=='@') || (c>= '0' && c<='9'))
  {
    result=true;
  }//if
  return result;
}//isValidEmailChar