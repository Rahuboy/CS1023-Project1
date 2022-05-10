#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _EXTRAS_
#define _EXTRAS_

string nametoroll(string name, int mode); //converts name to roll number

string rolltoname(string roll); //converts roll number to name

int checkfacrollno(string roll); //checks if faculty member was created

int checkstudentrollno(string roll); //checks if student was created

int checknamnum(int mode, string name); //checks if course name/id is valid

#endif