//Objective:input number of scores to be input, then input that many scores, calculate the maximum score, average score, minimum score, and how many A grade scores
//Name: Kristofer Santo 
//Course: COMSC-110-8074
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
void introduction(string obj); //program introduction
void outputResults(int* s, int minimum, int maximum, double averageGrade, int gradeA, int size1); //output the results from calculations
void sortArray(int* s1, int size2); //sort scores array in numerical order
void inputScores(int* s2, int size3); //input scores for the scores array
int inputSize(); //input the size of the scores array

//main program
int main()
{
  //Data
  string objective = "input number of scores to be input, then input that many scores, calculate the maximum score, average score, minimum score, and how many A grade scores."; //program objective
  int inputtedSIZE; //size of array
  int SIZE;
  int* Scores = new int[SIZE]; //days of the week
  int max; //maximum of inputted values
  int min; //minimum of inputted values
  double sum = 0.0;
  double average = 0.0; //average of inputted values
  int nGradeA=0; //number of grades that are an 'A'
  int i; // loop index
  
  //user introduction
  introduction(objective);  

  // ask user how many values
  inputtedSIZE = inputSize();
  SIZE = inputtedSIZE - 1;
  
  //input Scores
  inputScores(Scores, inputtedSIZE);
  
  // sort the array
  sortArray(Scores, inputtedSIZE);
  
  //calculate min, max, nGradeA, sum, and average
  min = Scores[0];
  max = Scores[SIZE];
  for (i=0; i<inputtedSIZE; i++)
  {
    if (Scores[i] >= 90) nGradeA++;
    sum = sum + Scores[i];
  }//for
  average = sum /inputtedSIZE;

   //output results
   outputResults(Scores, min, max, average, nGradeA, inputtedSIZE);
}//main

// introduction
void introduction(string obj)
{
  //data
  //obj is the program objective

  //user introduction
  cout << "Objective: This program will "; 
  cout << obj << endl;
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction

//outputResults
void outputResults(int* s, int minimum, int maximum, double averageGrade, int gradeA, int size1){
  //data
  //s is the array to be outputted
  //minimum is the minimum score in the array
  //maximum is the maximum score in the array
  //averageGrade is the average of all scores
  //gradeA is the number of grades above A
  //size1 is the size of the array
  int i;

  // output array from least to greatest
  cout << "Sorted: "; 
  for (i = 0; i < size1; i++) 
    cout << s[i] << ' '; 
  cout << endl; 
  
  // output min, max, nGradeA, and average
  cout << "Minimum: " << minimum << endl;
  cout << "Maximum: " << maximum << endl;
  cout << "Average: " << averageGrade << endl;
  cout << gradeA << " 'A' Grade(s) Entered "; 
}//outputResults

//sortArray
void sortArray(int* s1, int size2){
  //data
  //s1 is the array to be sorted
  int i; //loop index
  int j; //loop index
  int temp; //temporary value

  // sort the array
  for (i = 0; i < size2; i++) 
  {
    for (j = i + 1; j < size2; j++) 
    { 
      if (s1[i] > s1[j]) 
      { 
        // swap code 
        temp = s1[i]; 
        s1[i] = s1[j];   
        s1[j] = temp; 
      } // if 
    } // for j
  } // for i
}//sortArray

//inputScores
void inputScores(int* s2, int size3){
    int i;

  for (i=0; i<size3; i++)
  {
    cout << "Enter a score: ";
    cin >> s2[i];
    cin.ignore(1000, 10);
    if (s2[i]>100 || s2[i]<0){
        i--;
        cout << "Invalid score, please enter a score from (0-100)\n";
    }//if
  }//for
}//inputScores

//inputSize
int inputSize(){
  //data
  int inputtedSIZE1; //inputted size of array
  
  //input the size
  cout << "How many scores? ";
  cin >> inputtedSIZE1;
  cin.ignore(1000, 10);
  
  return inputtedSIZE1;
}//inputSize