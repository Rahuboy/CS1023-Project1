#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _STUDENT_
#define _STUDENT_

class Student
{
    private:
        string studname;
        string studrollno;

    public:
        void createstudent(string name, string rollno); //creates a student object
        void cpystudentdata(string rollno);
        void dispstudentdata();

        Student()
        {
            studname="N/A";
            studrollno="N/A";
        }
};



#endif