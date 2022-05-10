#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _FILEMANIP_
#define _FILEMANIP_

void insertstr(fstream& file, string tobefore, string insert, string filename); //inserts string at specified location

void deletestr(fstream& file, string before, string filename); //deletes string at specified location

string accesslineno(fstream& file, int lineno, string filename); //accesses a line number from any .txt file

int checkfile(fstream& file, string tocheck, string filename); //checks file for string

string idnumbr(int mode, int number); //creates roll numbers / course numbers

int toint(string rollno); //converts roll / course numbers to integers

#endif