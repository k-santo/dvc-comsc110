//Objective: To use a linked list to make a student database
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
struct Student
{
  string name;
  int id;
  float gpa;
  Student* next; // the next-link
}; // Student

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
  string objective="Objective: To use a linked list to make a student database\n";
  ifstream fin; //input file
  int nStudents=0; //number of students
  
  //introduction
  introduction(objective);
  
  // open a file for input
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
 
  // create an empty linked list
  Student* start = 0;
 
  // read and save the records
  while (fin.good())
  {
    // Step 1, create a node
    Student* aStudent = new Student;

    // Step 2, read its data fields
    getline (fin, aStudent->name);

    fin >> aStudent->id;
    fin.ignore(1000, 10);
 
    fin >> aStudent->gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the separator line

    // Step 3, add new node to the list
    aStudent->next = start;
    start = aStudent;
    nStudents++;
  }//while
  fin.close();
 
  cout << "Number of Students: " << nStudents << endl;
  // traverse the list and output
  Student* p;
  for (p = start; p; p = p->next)
  {
    cout << "Name = " << left << setw(30) << p->name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << p->id
      << ", gpa = " << p->gpa << endl;
    cout.fill(' '); 
  }//for

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
