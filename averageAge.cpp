//Objective:  Calculate the average age of all students in the classroom
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
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  int age;
  int sum;
  int numberOfPeople;
  int averageAge;
    
    
  // introduction
  cout << "Objective: Calculate the average age of all students in the classroom \n"; 
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

cout << "How many people are in the classroom? ";
cin >> numberOfPeople;
cin.ignore(1000, 10);
    
    for (int i=0; i<numberOfPeople; i++) {
        cout << "\n What is the age of one of the people in the classroom? ";
        cin >> age;
        cin.ignore(1000,10);
        sum = sum + age;
    }
    
    averageAge = sum / numberOfPeople;
    cout << "\n The average age of all people in the classroom is" << averageAge
}//main