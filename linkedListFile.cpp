//Objective: find average score and number of scores greater than average
//Name: Kristofer Santo
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream> 
using namespace std;

//Programmer defined data types
struct Score
{
  int number;
  Score* next; //link
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introductions

//main program
int main()
{
  //Data
  string objective = "Objective: find average score and number of scores greater than average";
  Score* start = 0; //starting node for linkedlist
  Score* p; //index for traversing
  Score* aScore; //temporary score
  Score* newNode; //to replace
  ifstream fin; //represents input file
  int i; // loop counter 
  int scoreTotal = 0; // sums of both scores
  int nGreater = 0; //number of scores greater than average
  int low; //lowest value
  double count=0.0; //number of scores counted
  int high; //highest value
  double average;//average of both scores

  //program introduction
  introduction(objective);

  fin.open("scores.txt"); 
  if (!fin.good()) throw "I/O error"; 
  
  // read and save the scores 
  while (fin.good()) 
  { 
    aScore= new Score;
    
    // read a score from the file 
    fin >> aScore->number;
    fin.ignore(1000, 10); 
  
    // add new score to list, if list is not full 
    aScore->next= start;
    start=aScore;
  } // while 

  // find the average 
  for (p = start; p; p = p->next)
  {
    scoreTotal = scoreTotal + p->number;
    count++;
  } //for 
  average = scoreTotal/count;
  
  // count number of scores > average, highest, and lowest
  low = aScore->number;
  high = aScore->number;
  for (p= start; p; p=p->next)
  {
    if (p->number> average)
    {
      nGreater++;
    }//if
    
    //check if low or high
    if(p->number< low)
    {
      low= p->number;
    }//if
    else if(p->number> high)
    {
      high= p->number;
    }//if
  }//for 
  
  //output results
  cout << "Number of scores: " << count  << endl;
  cout << "Average: " << average << endl;
  cout << "Highest score: " << high << endl; 
  cout << "Lowest score: " << low << endl;
  cout << "Number of scores above average: " << nGreater << endl;
  
  //take old memory
  while(start)
  {
     newNode = start->next; 
     delete start;
     start = newNode;
  } // while
}//main

//program introduction
void introduction(string obj)
{
  //data
  //obj is the objective

  //output introduction
  cout << obj << endl;
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
} //introduction