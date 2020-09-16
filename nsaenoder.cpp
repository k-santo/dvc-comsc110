#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
ifstream fin;
ofstream fout;
string line; // string of text for line
string fileName; //name of the file
string secretFile = "secret.txt";
int i; // loop index

// prompt user to enter name of text file, open file and secret.txt 
cout << "Please enter the name of the text file you wish to encode: "; 
getline (cin, fileName);
cin.ignore(1000, 10);


fin.open(fileName.c_str());
if (!fin.good()) throw "I/O error";
while(!eof.fileName=true)
{
getline(fin, line);
fin.close();

for (i = 0; i < line.length(); i=i+1){
line[i] = line[i] + 1; // bump the ASCII code by 1
}

fout.open(secretFile.c_str());
if (!fout.good()) throw "I/O error";
fout << line;
fout.close();
cout << line;
}
}