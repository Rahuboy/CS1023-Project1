#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _COURSE_
#define _COURSE_

class Course
{
    private:
        string name; //name of course, format - ABwxyz
        string studentgrades[20]; //Grade values + "X" for not in course, "R" for registered
        int floated; //either 0 or 1
        string faculty; //faculty taking course

    public:
        void createcourse(string coursename, string coursenumber); //creates .txt file for course
        void registerstud(string coursename, string rollnum, string reg); //registers (or de-reg) students to course 
        void floatcourse(string coursename, int val); //assigns 1 to floated (or val)
        void checkfaculty(string coursename); //initialises the string faculty after reading from .txt file
        void checkenrolled(string facrollno, string coursename); //checks enrolled students, and allows grades to be changed.
        void cpycoursedata(string coursenumber); //copies data to class from txt file
        void assigngrade(string rollno, string grade); //assigns grade to rollno
        int checkgradeassignment(string coursename); //returns 1 if a grade has been assigned, 0 otherwise
        void displaygrades(string rollno);
        void dispcoursedata(); 

        Course()
        {
            name="N/A";
            for(int i=0;i<20;i++) studentgrades[i]="X";
            floated=0;
            faculty="N/A";
        }
        
};


#endif 
