//Objective: To read all song titles from a text file and randomly select and output titles in a loop until the user wishes to stop
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
const int MAX_SONGS=200;

//Programmer defined functions
void introduction(string obj); //user introduction
void playSong(string* s, int totalSongs, deque<string>& dupSong); //loop for playing the song

//main program
int main()
{
  //Data
  string objective="Objective: To read all song titles from a text file and randomly select and output titles in a loop until the user wishes to stop";
  srand(time(0)); rand();  //seed random number generator
  int nSongs=0; //number of songs
  ifstream fin; //input file
  deque<string> dupSong; //collection of duplicate songs
  string songName; //name of song 
  string song[MAX_SONGS]; //list of songs
  
  //user introduction
  introduction(objective);
  
  //open songs file and input songs into song list
  fin.open("songs.txt");
  while(fin.good())
  {
    getline(fin, songName);
    if (nSongs<MAX_SONGS) song[nSongs++] = songName;
    if (nSongs>=MAX_SONGS) break;
  }//while
  
  //play songs
  playSong(song, nSongs, dupSong);
  
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

void playSong(string* s, int totalSongs, deque<string>& dupSong)
{
  //data
  //s is the list of songs
  //totalSongs is the number of total songs
  char choice='y'; //the user's choice whether to conitnue or not 
  int randomSong; //number generated randomly representing songs
  bool isDupSong=false; //checks for a duplicate song
  
    while(choice=='Y' || choice =='y'){
    cout << "Play a song [Y/N]?: ";
    cin >> choice;
    cin.ignore(1000, 10);
    if (choice == 'n' || choice == 'N') break;
    if (choice =='y' || choice =='Y')
    {
      do{
      randomSong= rand() % totalSongs;
      for(int i=0; i<dupSong.size(); i++)
      {
        if (dupSong[i]==s[randomSong]) 
        {
          isDupSong=true;
          break;
        }//if
        else
        {
          isDupSong=false;
        }
      }//for
      }while(isDupSong==true);
       
      if(isDupSong==false)
      {
        cout << s[randomSong] << endl;
        dupSong.push_back(s[randomSong]);
        if(dupSong.size()>5) dupSong.pop_front();
      }
    }//if
  }//while
}//playsong
