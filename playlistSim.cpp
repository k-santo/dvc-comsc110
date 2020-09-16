//playlist simulator
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
  #endif

//linked list 
struct Song{
    string songName;
    int songLength;
    Song* next;
};


string chooseInputType(int tIndicator); //chooses the type of input 
string fileInput();//stuff
string inputFileName(); //
void countdown(int songlength);


int main(){
    cout << "Welcome to the Playlist Simulator! The instructions are simple. First, you will be prompted to " << endl;
    cout << "specify a method of how you would like to input the songs. Then, after the songs are inputted, " << endl;
    cout << "the first song on the playlist will 'play' and you will be given the following ways of navigating" << endl;
    cout << "the playlist." << endl << "Press: " << endl;
    cout << "'w' to skip to the next song" << endl;
    cout << "'s' to skip to the previous song" << endl;
    cout << "'a' to restart the currently playing song" << endl;
    cout << "'d' to exit out of the playlist" << endl;
    Song* start= 0;
    string aSongName;
    int i=0;
    bool playSong=true;
    char choice;
    Song* current;
    countdown(150);
    
    cout << "Please type the song names and press enter after each name: " << endl;
    for(i=0; i<5; i++){
        Song* s = new Song;
        getline(cin, aSongName);
        s->songName=aSongName;
        s->next=start;
        start=s;
    }
    while(playSong=true){
        cout << "Now Playing: ";
        cout << start->songName;
        cin >> choice;
        if (choice='w');
    }
    
}
void countdown(int songlength){
   int secLength = songlength%60;
   int minLength = songlength/60;
   cout << minLength;
   int sec;
   int min;
   
   for (min = 0; min<=minLength; min++)
   {
        for (sec = 0; sec < 61; sec++)
        {
            cout << min << ":" << setw(2) << sec;
            cout.flush();

             sleep(1);
             cout << '\r';
             if (sec == 10)
            {
            cout << "boom" << endl;
            }
        }
    }
}