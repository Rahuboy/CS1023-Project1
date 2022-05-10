#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include "courseclass.h"
#include "filemanip.h"
#include "extras.h"

using namespace std;

//creates a text file for the course ("'coursename'.txt"), and initialises values
//Course number format - "Cxy" where xy ranges from 01 to 05
void Course::createcourse(string coursename, string coursenumber)
{
   
        fstream file;

        for(int i = 1; i<=5; i++)
        {
            string cno = "C0"+to_string(i);
            if(checkfile(file, cno+"-"+coursename,"list.txt")!=0&&coursename!="N/A")
            {
                cout<<"This course has already been created"<<endl;
                return;
            }
        }

        if(checkfile(file,coursenumber+"-"+"N/A","list.txt")==0&&coursename!="N/A")
        {
            cout<<"This course number has already been assigned to another course"<<endl;
            return;
        }

        if(coursename!="N/A")
        {
        file.open(coursename+".txt",ios::out);
        file<<"Course:"<<endl;
        file<<"Number-"<<coursenumber<<endl;
        file<<"Name-"<<coursename<<endl;
        file<<"Floated-"<<0<<endl;
        file<<"Faculty-N/A"<<endl;
        for(int i = 0; i <20; i++)
        {
            if(i<9)    file<<"Grade0"<<i+1<<"-X"<<endl;
            else file<<"Grade"<<i+1<<"-X"<<endl;
        }
        file.close();

        name=coursename;
        fill_n(studentgrades, 20, "X");
        floated=0;
        faculty="N/A";

        string x,y;
        string c = coursenumber.substr(1);
        int cno = stoi(c);

        x = accesslineno(file, cno, "list.txt");
        y = accesslineno(file, cno+1, "list.txt");

        insertstr(file, y, "C"+c+"-"+coursename, "list.txt");
        deletestr(file, x, "list.txt");
        return;
        }
        else
        {
            if(checkfile(file,coursenumber+"-"+"N/A","list.txt")!=0)
            {
                cout<<"The course has already been deleted "<<endl;
                return;
            }
            else
            {
                if(faculty!="N/A") 
                {
                    cout<<"A faculty was assigned to this course, cannot be deleted "<<endl;
                    return;
                }
                for(int i=0;i<20;i++)
                {
                    if(studentgrades[i]!="X")
                    {
                        cout<<"Students are registered/have been assigned grades in this course, cannot be deleted "<<endl;
                        return;
                    }
                }
            string x,y;
            string c = coursenumber.substr(1);
            int cno = stoi(c);

            x = accesslineno(file, cno, "list.txt");
            y = accesslineno(file, cno+1, "list.txt");

            insertstr(file, y, "C"+c+"-"+coursename, "list.txt");
            deletestr(file, x, "list.txt");

            string coursefile = name + ".txt";
            remove(&coursefile[0]);

            name="N/A";
            floated=0;

            return;
                
            }
        }
}

// Registers (or deregisters) a student in 'coursename'.
//Rollno format - Rxy where xy ranges from 01 to 20
//reg - Can be "R" or "X"
void Course::registerstud(string coursename, string rollno, string reg)
{
    fstream file;
    string x,y,flt;
    string r = rollno.substr(1,rollno.length());
    string filename = coursename + ".txt";

    if(nametoroll(coursename,1)=="C06")
    {
        cout<<"Course hasn't been created by the admin yet"<<endl;
        return;
    }

    

    int rno = stoi(r);
    if(studentgrades[rno-1]!="X"&&reg!="X")
    {
        cout<<"Student has already been registered"<<endl;
        return;
    }

    if(studentgrades[rno-1]=="X"&&reg=="X")
    {
        cout<<"Student hasn't registered to this course"<<endl;
        return;
    }

    x = accesslineno(file, 4+rno, filename);
    y = accesslineno(file, 5+rno, filename);
    flt = accesslineno(file, 4, filename);

    if(flt.substr(flt.length()-1,flt.length())=="0")
    {
        cout<<"Course has to first be floated"<<endl;
        return;
    }

    string studstr = accesslineno(file, 7+rno, "list.txt");
    if(studstr == rollno+"-N/A")
    {
        cout<<"Student hasn't been created by the admin yet"<<endl;
        return;
    }

    insertstr(file, y, "Grade"+r+"-"+reg, filename);
    deletestr(file, x, filename);

    studentgrades[rno-1]=reg;

}


//assigns val 1 to floated
void Course::floatcourse(string coursename, int val)
{
    fstream file;
    string x,y;
    int tab=0;

    string test = nametoroll(coursename,1);
    if(test=="C06")
    {
        cout<<"Course hasn't been created yet"<<endl;
        return;
    }

   
    x = accesslineno(file, 3, coursename+".txt");
    y = accesslineno(file, 4, coursename+".txt");
    insertstr(file, y, "Floated-"+to_string(val), coursename+".txt");
    deletestr(file, x, coursename+".txt");

    floated=val;

    return;

}

//Reads faculty name from text file 'coursename'.txt and adds data to class
void Course::checkfaculty(string coursename)
{
    fstream file;
    string filename = coursename + ".txt";
    string x = accesslineno(file, 5, filename);
    string facnam = x.substr(8, x.length()-13);
    faculty = facnam;
    cout<<"Faculty for "<<coursename<<" is: "<<faculty<<endl;

}

//Gives a list of all enrolled students in the course. Allows faculty to assign grades as well
void Course::checkenrolled(string facrollno, string coursename)
{
    fstream file1,file2;
    string file1name = coursename + ".txt";
    string file2name = "list.txt";
    string coursefac = accesslineno(file1, 5, file1name);
    string coursefacroll = coursefac.substr(coursefac.length()-4, 3);

    if(coursefacroll!=facrollno)
    {
        cout<<"A different faculty member was assigned to this course"<<endl;
        return;
    }

    int count=0;

    int studarray[20];

    for(int i=0;i<20;i++)
    {
        string line = accesslineno(file1, 6+i, file1name);
        studarray[i]=0;
        if(line.substr(8)!="X")
        {
            count++;
            string student = accesslineno(file2, 8+i, file2name);
            cout<<student<<endl;
            studarray[i]=1;
        }
    }

    if(count==0)
    {
        cout<<"No students"<<endl;
        return;
    }

    cout<<"Assign grades? (Y/N) "<<endl;
    char ch;
    cin>>ch;
    if(ch=='N') return;

    else
    {
        for(int i=0;i<20;i++)
        {
            if(studarray[i]==0) continue;
            else
            {
                if(i<9) cout<<"Enter grade for Roll Number R0"<<i+1<<endl;
                else cout<<"Enter grade for Roll Number R"<<i+1<<endl;
                string grade;
                cin>>grade;
                string x = accesslineno(file1, i+5, file1name);
                string y = accesslineno(file1, i+6, file1name);

                if (i<9) insertstr(file1, y, "Grade0"+to_string(i+1)+"-"+grade, file1name);
                else insertstr(file1, y, "Grade"+to_string(i+1)+"-"+grade, file1name);

                deletestr(file1, x, file1name);

                studentgrades[i]=grade;
            }
        }
        return;
    }

}

//copies data to class from txt file
void Course::cpycoursedata(string coursenumber)
{
    fstream file;
    int n = toint(coursenumber);
    string line = accesslineno(file, 1+n, "list.txt");

    if(line.substr(4)=="N/A") 
    {
        name="N/A";
        faculty="N/A";
        for(int i=0;i<20;i++) studentgrades[i]="X";
        floated=0;
        return;
    }

    else
    {
        string coursename = line.substr(4);
        name = coursename;
        string coursefile = coursename + ".txt";
        string floatedstr = accesslineno(file, 4, coursefile);
        floated = stoi(floatedstr.substr(8));
        string facstr = accesslineno(file, 5, coursefile);
        string facnam = facstr.substr(8, facstr.length()-13);
        faculty = facnam;
        for(int i = 0; i<20; i++)
        {
            string gradestr = accesslineno(file, i+6, coursefile);
            studentgrades[i]=gradestr.substr(8);
        }
    }

    return;

}

//assigns grade 'G' to student with rollno 'rollno'
void Course::assigngrade(string rollno, string grade)
{
    fstream file1;
    if(name=="N/A") return;
    string file1name = name+".txt";
    int i = toint(rollno);
    
    string x = accesslineno(file1, i+4, file1name);
    string y = accesslineno(file1, i+5, file1name);

    if (i<=9) insertstr(file1, y, "Grade0"+to_string(i)+"-"+grade, file1name);
    else insertstr(file1, y, "Grade"+to_string(i)+"-"+grade, file1name);

    deletestr(file1, x, file1name);

    studentgrades[i-1]=grade;
}

//returns 1 if students have been assigned a grade in the course, 0 otherwise
int Course::checkgradeassignment(string coursename)
{
    for(int i=0;i<20;i++)
    {
        if(studentgrades[i]!="X"&&studentgrades[i]!="R") return 1;
    }
    return 0;
}

void Course::displaygrades(string rollno)
{
    if(name=="N/A")
    {
        cout<<"N/A"<<endl;
        return;
    }
    fstream file;
    string filename = name+".txt";
    string gradeline = accesslineno(file, 5+toint(rollno), filename);
    string grade = gradeline.substr(8);
    if(grade=="X") cout<<"Student hasn't registered for "<<name<<endl;
    if(grade == "R") cout<<"Grades haven't been assigned for "<<name<<endl;
    if(grade!="X"&&grade!="R") cout<<"grade in "<<name<<" is "<<grade<<endl;
    return;
}




//displays data of object
void Course::dispcoursedata()
{
    cout<<"Name of the course is "<<name<<endl;
    for(int i=0; i<20;i++)
    {
        cout<<"Grade "<<i+1<<" is "<<studentgrades[i]<<endl;
    }
    cout<<"Floated value is "<<floated<<endl;
    cout<<"Faculty name is "<<faculty<<endl;
}

