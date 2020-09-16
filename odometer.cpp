//Objective: Program will simulate an odometer
//Name: Kristofer Santo 1768976
//Course: COMSC-110-8076
//Compiler: TDM MinGW
//Editor: MS NotePad

#include <iomanip> //formatting
#include <iostream>  //console input and output
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif 

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  int hundredThousands = 0; //hundred thousands
  int tenThousands = 0; //ten thousands
  int thousands = 0; //thousands
  int hundreds = 0; //hundreds
  int tens = 0; //tens (1 digits width) in odometer
  int ones = 0; //ones (1 digits width) in odometer
  int tenths = 0;// tenths (1 digits width) in odometer

  // output my name and objective and program information
  cout << "Objective: This program will simulate an odometer\n"; 
  cout << "Programmer: Kristofer Santo\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  cout << endl << endl << "CTRL-C to exit...\n"; 

  //output odometer
  cout.fill('0');
  for (hundredThousands=0; hundredThousands<10; hundredThousands++)
  {
    for (tenThousands=0; tenThousands<10; tenThousands++)
    {
        for (thousands=0; thousands<10; thousands++)
        {
            for (hundreds=0; tens<10; hundreds++)
            {
                for (tens=0; tens < 10; tens++) 
                { 
                    for (ones=0; ones < 10; ones++) 
                    { 
                        for (tenths=0; tenths < 10; tenths++) 
                        { 
                        //output digits of odometer
                        cout << setw(1) << hundredThousands; 
                        cout << setw(1) << tenThousands; 
                        cout << setw(1) << thousands; 
                        cout << setw(1) << hundreds; 
                        cout << setw(1) << tens; 
                        cout << setw(1) << ones << '.';
                        cout << setw(1) << tenths; 
                        cout.flush();  //clears the output buffer

        //pause for one second  
        #ifdef _WIN32 
        Sleep(1000); // one hundred milliseconds
        #else 
        sleep(1); // one second
        #endif 

        //return to begining of current line  
        cout << '\r'; // CR 
         }
        }
            }
        }
      } //for 
    } // for 
  } //for 
}//main