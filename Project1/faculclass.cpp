#include <iostream>
#include <fstream>
#include <string>
#include "faculclass.h"
#include "filemanip.h"
#

using namespace std;

//Creates a faculty object, assigns attributes name and coursename. Also adds faculty name
//to relevant .txt file along with roll number. 
// Roll number format - Fxy (xy ranges from 01 to 05)
//Can also be used to delete faculty (let name be N/A)
void Faculty::createfacult(string name, string coursename, string rollno)
{
    
    fstream file;
    
    int tab = 0;
    for(int i=1;i<=5;i++)
    {
        string cn = "C0"+to_string(i);
        if(checkfile(file, cn+"-"+coursename, "list.txt")!=0)
        {
            tab = 1;
        }
    }

    if(tab==0)
    {
        cout<<"This course hasn't been created by the admin yet"<<endl;
        return;
    }




    if((checkfile(file, "Faculty-N/A", coursename+".txt")==0)&&name!="N/A")
    {
        cout<<"A faculty member was already assigned this course"<<endl;
        return;
    }

    if(faculcourse!=coursename&&name=="N/A")
    {
        cout<<"This faculty was not assigned this course"<<endl;
        return;
    }

    for(int i=1;i<=5;i++)
    {
        string rn = "F0"+to_string(i);
        if(checkfile(file, rn+"-"+name, "list.txt")!=0&&name!="N/A")
        {
            cout<<"This faculty member was already assigned a roll number"<<endl;
            return;
        }
    }

    if(checkfile(file, rollno+"-"+"N/A", "list.txt")==0&&name!="N/A")
    {
        cout<<"This roll number was already assigned to another faculty"<<endl;
        return;
    }
    
    
    faculrollno=rollno;
    faculname=name;
    faculcourse=coursename;
    
    string x = accesslineno(file, 4, coursename+".txt");
    string y = accesslineno(file, 5, coursename+".txt");

    if(name!="N/A")
    {
        insertstr(file, y, "Faculty-"+name+"("+rollno+")", coursename+".txt");
        deletestr(file, x, coursename+".txt");
    }
    else
    {
       insertstr(file, y, "Faculty-"+name, coursename+".txt");
        deletestr(file, x, coursename+".txt"); 
    }

    string filename = "list.txt";
    string r = rollno.substr(1);
    int rno = stoi(r);

    string a,b;
    a = accesslineno(file, rno+27, filename); 
    b = accesslineno(file, rno+28, filename);
    insertstr(file, b, "F"+r+"-"+name, filename);
    deletestr(file, a, filename);

}

void Faculty::cpyfaculdata(string rollno)
{
    fstream file;
    string line = accesslineno(file, 28+toint(rollno), "list.txt");
    faculrollno = line.substr(0,3);
    faculname = line.substr(4);
    
    for(int i=0;i<5;i++)
    {
        string s = accesslineno(file, i+2, "list.txt");
        string coursenostr =  idnumbr(1,i+1);
        if((coursenostr+"-N/A") != s)
        {
            string coursefile = s.substr(4)+".txt";
            string facstr = accesslineno(file, 5, coursefile);
            string facnam = facstr.substr(8, facstr.length()-13);
            if(faculname==facnam)
            {
                faculcourse = s.substr(4);
                return;
            }
        }
    }

    faculcourse = "N/A";
    return;
}

void Faculty::dispfaculdata()
{
    cout<<"Faculty Name:"<<faculname<<endl;
    cout<<"Faculty Roll No:"<<faculrollno<<endl;
    cout<<"Faculty Course:"<<faculcourse<<endl;
}