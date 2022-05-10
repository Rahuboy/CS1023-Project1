#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _FACULTY_
#define _FACULTY_

class Faculty
{
    private:
        string faculname;
        string faculrollno;
        string faculcourse;

    public:
        void createfacult(string name, string coursename, string rollno); //creates a faculty member for a course
        void cpyfaculdata(string rollno);
        void dispfaculdata();

        Faculty()
        {
            faculname="N/A";
            faculrollno="N/A";
            faculcourse="N/A";
        }
};

#endif