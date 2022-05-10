#include <iostream>
#include <fstream>
#include <string>
#include "stuclass.h"
#include "filemanip.h"

using namespace std;

//creates a student object, adds relevant information to .txt files
//rollno format - Rxy (xy ranges from 00 to 20)
void Student::createstudent(string name, string rollno)
{
    fstream file;
    string filename = "list.txt";

    if(checkfile(file, rollno+"-N/A", filename)==0&&name!="N/A")
    {
        cout<<"A student was already registered at this roll number"<<endl;
        return;
    }

    string r = rollno.substr(1);
    int rno = stoi(r);

    string x,y;
    x = accesslineno(file, rno+6, filename); 
    y = accesslineno(file, rno+7, filename);

    insertstr(file, y, "R"+r+"-"+name, filename);
    deletestr(file, x, filename);


    studname = name;
    studrollno = rollno;

}

void Student::cpystudentdata(string rollno)
{
    fstream file;
    string line = accesslineno(file, 7+toint(rollno), "list.txt");
    studrollno = line.substr(0,3);
    studname = line.substr(4);
}

void Student::dispstudentdata()
{
    cout<<"Student name is:"<<studname<<endl;
    cout<<"Student roll number is:"<<studrollno<<endl;
}