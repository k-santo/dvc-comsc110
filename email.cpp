//Objective: To input file names and check if the input file name has an email
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque>
#include <fstream>
#include <iostream>
using namespace std;

//Programmer defined data types
//data

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
string getFileName (string fileType, string dFileName); //outputs variable prompt with default filename and gets a filename (either input or output) using input validation and returns the fileName depending on user
void readFile(deque<string>& nonDup, string iFileName); //reads input file until EOF that calls function processLine for each line read from the input file
int processLine(deque<string>& nonDup, string lineFromFile); //output the line each time an @ is found in the line and return number of @'s
bool isValidEmailChar (char c); //Returns true if c is a valid email address character, else false
string changeCase(string s); //converts string to all one case for case dependent comparisons
bool isDuplicate (deque<string>& nonDup, string aEmail); //checks anEmail whether it is a duplicate email address using case sensitive comparison to create list of non-duplicate email addresses
void outputList(deque<string>& nonDup, string oFileName); //outputs the list of non-duplicate email addresses to the screen and output file meeting all output requirements
void sortList(deque<string>& nonDup); //sorts the nonduplicate emails list

//main program
int main()
{
  //Data
  string objective = "Objective: To input file names and check if the input file name has an email "; 
  string dFileName ="fileContainingEmails.txt"; // default file name
  string iFileName; //input file name
  string oFileName; //output file name
  deque<string> nonDup; //collection of non-duplicate emails
  
  //input and output names of files 
  iFileName= getFileName("input", dFileName);
  dFileName= "copyPasteMyEmails.txt";
  oFileName= getFileName("output", dFileName);
  
  //output if line has email in it
  readFile(nonDup, iFileName);
  
  //output the emails to the output files
  outputList(nonDup, oFileName);
  
}//main

//user introduction
void introduction(string obj)
{
  
  //data
  //obj is the program objective
  
  // introduction
  cout << obj;
  cout << "Instructions: Enter the desired text file of the emails for input and output. Press enter to use the given default file name. " << endl;
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
 
}//introduction

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

void output(string in, string out)
{
  //data
  //in is the name of the input file
  //out is the name of the output file
  
  //output names of files
  cout << "Input file: " << in << endl;
  cout << "Output file: " << out << endl;
}//output

void readFile(deque<string>& nonDup, string iFileName)
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
    inEmails=processLine(nonDup, inLine);
    nEmails= nEmails + inEmails;
  }//while
  if(nEmails>0)
  {
    cout << "The total number of emails is " << nEmails;
  }
  else
  {
    cout << "Sorry, no emails were found in the input file. ";
  }
}//readFile

int processLine(deque<string>& nonDup, string lineFromFile)
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
        if(!isDuplicate(nonDup, anEmail))
        {
          cout << anEmail << endl;
          numEmails++;
        }//if
      }//if
    }//if
  }//for
  
  return numEmails;
}//processLine

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

string changeCase(string s)
{
  //aata
  //s is the input string
  string upperString; //uppercase string
  int i; //index loop 

  //convert lower case to upper case char by char and returns it
  for(i=0; i<s.length(); i++)
  {
    upperString += tolower(s[i]);
  }//for
  return upperString;
}//changeCase

bool isDuplicate (deque<string>& nonDup, string aEmail)
{
  //data
  //nonDup is the list of nonDuplicate emails
  //aEmail is a given email to check if duplicate
  int i; //index loop of course 
  bool dup=false; //checker for if dupicate
  
  for(int i=0; i<nonDup.size(); i++)
  {
    if(changeCase(aEmail)==changeCase(nonDup[i])) dup=true;
  }//if
  if (dup==false)
  {
    nonDup.push_front(aEmail);
  }//if
  return dup;
}//isDuplicate

void outputList(deque<string>& nonDup, string oFileName)
{
  //data
  //nonDup is the list of non duplicate emails
  //oFileName is the name of the output file
  ofstream fout; //output file ofstream
  int i; //index loop for traversing deque nonDup
  
  if(nonDup.size()>0)
  {
    //sort the list of emails into alphabetical order
    sortList(nonDup);
  
    //output the sorted emails into the output file
    fout.open(oFileName);
    for(int i=0; i<nonDup.size(); i++)
    {
      fout << nonDup[i] << endl;
    }//for
  
    //include helpful tips/instructions
    cout << "Find the output file that you inputted (or 'copyPasteMyEmails' if default)." << endl;
    cout << "Then, copy and paste your emails into the 'to', 'bcc', or 'cc' field of any email message" << endl;
    cout << "It's best to use 'bcc' though as it does not display all email adresses to the receiver, helping to maintain privacy. " << endl;
  }//if
}//outputList

void sortList(deque<string>& nonDup)
{
  //nonDup is the list of non duplicate emails
  int a; //first sorting index loop
  int b; //second sorting index loop
  string tempEmail; //temporary email address
  
  
  for(int a=0; a<nonDup.size(); a++)
  {
    for(int b=a+1; b<nonDup.size(); b++)
    {
      if(changeCase(nonDup[a])>changeCase(nonDup[b]))
      {
        tempEmail=nonDup[a];
        nonDup[a]=nonDup[b];
        nonDup[b]=tempEmail;
      }//if
    }//for
  }//for
}//sortList
