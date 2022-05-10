#include <iostream>
#include <fstream>
#include <string>
#include "filemanip.h"

using namespace std;


//converts coursename to roll number
//modes: 1-Course, 2-Students, 3-Faculty
string nametoroll(string name, int mode)
{
    fstream file;
    if(mode==1)
    {

        for(int i=1;i<=5;i++)
        {
            string cn = "C0"+to_string(i);
            if(checkfile(file, cn+"-"+name, "list.txt")!=0)
            {
    
                return cn;
            }
        }
        return "C06";
    }
    else if(mode==2)
    {
        for(int i=1;i<=20;i++)
        {
            string rn;
            if(i<=9)  rn = "R0"+to_string(i);
            else  rn = "R" + to_string(i);
            if(checkfile(file, rn+"-"+name, "list.txt")!=0)
            {
                return rn;
            }
        }
        return "R21";
    }
    else
    {
        for(int i=1;i<=5;i++)
        {
            string fn = "F0"+to_string(i);
            if(checkfile(file, fn+"-"+name, "list.txt")!=0)
            {
                return fn;
            }
        }
        return "F06";
    }
}

//converts roll number to name
string rolltoname(string roll)
{
    fstream file;

    if(roll.length()!=3) return "N/A";

    for(int i=1; i<=33; i++)
    {
        string str = accesslineno(file, i, "list.txt");
        if(str.substr(0,3)==roll)
        {
            return str.substr(4);
        }
    }
    return "N/A";
}

//checks if faculty with rollno 'roll' was created
int checkfacrollno(string roll)
{
    if(roll[0]=='F')
    {
        if(rolltoname(roll)!="N/A")
        {
            return toint(roll);
        }

        else return 0;
    }
    return 0;
}

//checks if student with rollno 'roll' was created
int checkstudentrollno(string roll)
{
    if(roll[0]=='R')
    {
        if(rolltoname(roll)!="N/A")
        {
            return toint(roll);
        }
        else return 0;
    }
    return 0;
}


//checks if course name/number is valid
//mode = 0 => course number
//mode = 1 => coursename
//mode = 2 => faculty roll number
//mode = 3 => student roll number
int checknamnum(int mode, string name)
{
    int i,tab;
    if(mode==0)
    {
        tab=0;
        for(i=1;i<=5;i++)
        {
            if(name==idnumbr(1,i)) tab=1;
        }
        if(tab==0) return 0;
        return 1;
    }
    else if(mode==1)
    {
        if(name.length()!=6) return 0;
        if(!(name[0]>='A'&&name[0]<='Z')) return 0;
        if(!(name[1]>='A'&&name[1]<='Z')) return 0;
        for(i=2;i<=5;i++)
        {
            if(!(name[i]>='0'&&name[i]<='9')) return 0;
        }

        return 1;
    }
    else if(mode==2)
    {
        if(name.length()!=3) return 0;
        if(name[0]!='F') return 0;
        if(name[1]!='0') return 0;
        if(!(name[2]>='1' && name[2]<='5')) return 0;

        return 1;
    }
    else if(mode==3)
    {
        if(name.length()!=3) return 0;
        if(name[0]!='R') return 0;
        if(name[1]=='0' && name[2]=='0') return 0;
        if(name[1]=='0' || name[1]=='1')
        {
            if(name[2]>='0' && name[2] <='9') return 1;
        }

        if(name[1]=='2' && name[2]=='0') return 1;

        return 0;
    }

    else return -1;
}