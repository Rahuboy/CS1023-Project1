/* To log-in as admin, use the username A01 as a command-line argument. ("./a.out A01" without the quotes)
This code was developed on MacOS */
//More details regarding input formats and terms etc. present in README.txt


#include <iostream>
#include <fstream>
#include <string>
#include "filemanip.h"
#include "courseclass.h"
#include "faculclass.h"
#include "stuclass.h"
#include "extras.h"
using namespace std;

#define COPY for(int i = 0; i< 5; i++) c[i].cpycoursedata(idnumbr(1,i+1)); for(int i = 0; i< 20; i++) s[i].cpystudentdata(idnumbr(2,i+1)); for(int i = 0; i< 5; i++) f[i].cpyfaculdata(idnumbr(3,i+1));


int main(int argc, char* argv[])
{
    fstream file;
    Course c[5];
    Student s[20];
    Faculty f[5];
    for(int i = 0; i< 5; i++) c[i].cpycoursedata(idnumbr(1,i+1));
    for(int i = 0; i< 20; i++) s[i].cpystudentdata(idnumbr(2,i+1));
    for(int i = 0; i< 5; i++) f[i].cpyfaculdata(idnumbr(3,i+1));
    int tab = 1;
    int count = 0;

    if(argc!=2)
    {
        cout<<"Invalid Number of command-line arguments!"<<endl;
        return 0;
    }

    string username(argv[1]);

    if(username=="A01")
    {
        cout<<"\nLogged in as admin\n\n";
        cout<<"MENU: (Type the corresponding number)\n"<<endl;
        cout<<"1) Add/Delete course"<<endl;
        cout<<"2) Add/Delete faculty members"<<endl;
        cout<<"3) Float courses"<<endl;
        cout<<"4) Add/Delete students"<<endl;
        cout<<"5) Register/Deregister students from courses"<<endl;
        cout<<"6) Exit\n"<<endl;

        while(tab==1)
        {
            if(count!=0)
            {
                cout<<"MENU: (Type the corresponding number)\n"<<endl;
                cout<<"1) Add/Delete course"<<endl;
                cout<<"2) Add/Delete faculty members"<<endl;
                cout<<"3) Float courses"<<endl;
                cout<<"4) Add/Delete students"<<endl;
                cout<<"5) Register/Deregister students from courses"<<endl;
                cout<<"6) Exit\n"<<endl;

            }
            count++;
            string choice;
            string ch;
            cin>>choice;
            if(choice == "1")
            {
                string coursename, coursenumber;
                cout<<"Add or delete course? (A/D)"<<endl;
                cin>>ch;
                if(ch=="A")
                {
                    
                    cout<<"Enter course name and course number (space separated)"<<endl;
                    cin>>coursename>>coursenumber;

                    if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }

                    else if(checknamnum(0,coursenumber)==0)
                    {
                    cout<<"Invalid course number"<<endl;
                    cout<<"Course number format: Cxy, where xy ranges from 01 to 05"<<endl;
                    cout<<"Choose options (1-6)"<<endl;
                    continue;
                    }
                    else
                    {
                        int courseno = toint(coursenumber);
                        c[courseno-1].createcourse(coursename, coursenumber);
                        c[courseno-1].cpycoursedata(idnumbr(1,courseno));
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else if(ch=="D")
                {
                    cout<<"Enter course number"<<endl;
                    cin>>coursenumber;
                    if(checknamnum(0,coursenumber)==0)
                    {
                        cout<<"Invalid course number"<<endl;
                        cout<<"Course number format: Cxy, where xy ranges from 01 to 05"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int courseno = toint(coursenumber);
                        c[courseno-1].createcourse("N/A", coursenumber);
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else
                {
                    cout<<"Invalid Input\n"<<endl;
                    cout<<"Choose options (1-6)"<<endl;
                }
            }

            else if(choice == "2")
            {
                string coursename,faculname,faculnumber,coursenumber;
                cout<<"Add or delete faculty? (A/D)"<<endl;
                cin>>ch;
                if(ch=="A")
                {
                    cout<<"Enter name of faculty:"<<endl;
                    getline(cin >> ws,faculname);
                    cout<<"Enter course name and faculty roll number (space separated)"<<endl;
                    cin>>coursename>>faculnumber;
                    if(checknamnum(2,faculnumber)==0)
                    {
                        cout<<"Invalid faculty roll number"<<endl;
                        cout<<"Faculty roll number format: Fxy, where xy ranges from 01 to 05"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int facno = toint(faculnumber);
                        f[facno-1].createfacult(faculname, coursename, faculnumber);
                        for(int i = 0; i< 5; i++) c[i].cpycoursedata(idnumbr(1,i+1));
                        f[facno-1].cpyfaculdata(faculnumber);
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else if(ch=="D")
                {
                    cout<<"Enter faculty roll number and coursename: (space separated)"<<endl;
                    cin>>faculnumber>>coursename;
                    if(checknamnum(2,faculnumber)==0)
                    {
                        cout<<"Invalid faculty roll number"<<endl;
                        cout<<"Faculty roll number format: Fxy, where xy ranges from 01 to 05"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }

                    else if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    
                    else
                    {
                        int facno = toint(faculnumber);
                        f[facno-1].createfacult("N/A", coursename, faculnumber);
                        for(int i = 0; i< 5; i++) c[i].cpycoursedata(idnumbr(1,i+1));
                        f[facno-1].cpyfaculdata(faculnumber);
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else
                {
                    cout<<"Invalid Input\n"<<endl;
                    cout<<"Choose options (1-6)"<<endl;
                }
            }

            else if(choice=="3")
            {
                string coursename;
                cout<<"Enter coursename to float:"<<endl;
                cin>>coursename;
                int courseno = toint(nametoroll(coursename,1));
                if(courseno>5)
                {
                    cout<<"Course hasn't been created yet\n"<<endl;
                    cout<<"Choose options (1-6)"<<endl;
                    continue;
                }
                c[courseno-1].floatcourse(coursename, 1);
                cout<<"Request was processed\n"<<endl;
                cout<<"Choose options (1-6)"<<endl;
            }

            else if(choice=="4")
            {
                string studentname,rollno;
                cout<<"Add or delete student? (A/D)"<<endl;
                cin>>ch;
                if(ch=="A")
                {
           
                    cout<<"Enter student name:"<<endl;
                    getline(cin >> ws,studentname);
                    cout<<"Enter roll number:"<<endl;
                    cin>>rollno;
                    if(checknamnum(3,rollno)==0)
                    {
                        cout<<"Invalid student roll number"<<endl;
                        cout<<"Student roll number format: Rxy, where xy ranges from 01 to 20"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int rno = toint(rollno);
                        s[rno-1].createstudent(studentname, rollno);
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else if(ch=="D")
                {
                    cout<<"Enter roll number:"<<endl;
                    cin>>rollno;
                    int rno = toint(rollno);
                    s[rno-1].createstudent("N/A", rollno);
                    for(int i=0; i<5; i++) c[i].assigngrade(rollno,"X");
                    cout<<"Request was processed\n"<<endl;
                    cout<<"Choose options (1-6)"<<endl;

                }
                else
                {
                    cout<<"Invalid Input\n"<<endl;
                    cout<<"Choose options (1-6)"<<endl;
                }
            }

            else if(choice == "5")
            {
                string studrollno, coursename;
                cout<<"Register or de-register? (R/D)"<<endl;
                cin>>ch;
                if(ch=="R")
                {
                    cout<<"Enter student roll number and coursename (space separated)"<<endl;
                    cin>>studrollno>>coursename;
                    if(checknamnum(3,studrollno)==0)
                    {
                        cout<<"Invalid student roll number"<<endl;
                        cout<<"Student roll number format: Rxy, where xy ranges from 01 to 20"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int courseno = toint(nametoroll(coursename,1));
                        if(courseno>5)
                        {
                            cout<<"Course hasn't been created yet\n"<<endl;
                            cout<<"Choose options (1-6)"<<endl;
                            continue;
                        }
                        c[courseno-1].registerstud(coursename, studrollno, "R");
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
                else if(ch=="D")
                {
                    cout<<"Enter student roll number and coursename (space separated)"<<endl;
                    cin>>studrollno>>coursename;
                    if(checknamnum(3,studrollno)==0)
                    {
                        cout<<"Invalid student roll number"<<endl;
                        cout<<"Student roll number format: Rxy, where xy ranges from 01 to 20"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int courseno = toint(nametoroll(coursename,1));
                        if(courseno>5)
                        {
                            cout<<"Course hasn't been created yet\n"<<endl;
                            cout<<"Choose options (1-6)"<<endl;
                            continue;
                        }
                        c[courseno-1].registerstud(coursename, studrollno, "X");
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                    }
                }
            }

            else if(choice=="6")
            {
                tab=0;
            }

            else
            {
                cout<<"Invalid Input\n"<<endl;
                cout<<"Choose options (1-6)"<<endl;
            }
    
        }

    }

    else if(checkfacrollno(username)!=0)
    {
          
        cout<<"\nLogged in as "<<rolltoname(username)<<"\n\n";
        cout<<"MENU: (Type the corresponding number)\n"<<endl;
        cout<<"1) Check students enrolled in course and submit grades"<<endl;
        cout<<"2) Exit\n"<<endl;
        while(tab==1)
        {

            if(count!=0)
            {
                cout<<"MENU: (Type the corresponding number)\n"<<endl;
                cout<<"1) Check students enrolled in course and submit grades"<<endl;
                cout<<"2) Exit\n"<<endl;

            }
            count++;
            string choice;
            cin>>choice;
            string coursename;
            if(choice=="1")
            {
                cout<<"Enter course name"<<endl;
                cin>>coursename;
                if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                else
                {
                    int courseno = toint(nametoroll(coursename,1));
                    if(courseno>5)
                    {
                        cout<<"Course hasn't been created yet\n"<<endl;
                        cout<<"Choose options (1 or 2)"<<endl;
                        continue;
                    }
                    c[courseno-1].checkenrolled(username, coursename);

                    cout<<"Request was processed\n"<<endl;
                    cout<<"Choose options (1 or 2)"<<endl;
                }
                
            }
            else if(choice=="2")
            {
                tab=0;
            }
            else
            {
                cout<<"Invalid Input: " << choice << "\n"<<endl;
                cout<<"Choose options (1 or 2)"<<endl;
            }
        }
    }

    else if(checkstudentrollno(username)!=0)
    {
        cout<<"\nLogged in as "<<rolltoname(username)<<"\n\n";
        cout<<"MENU: (Type the corresponding number)\n"<<endl;
        cout<<"1) Register to a course / Deregister from a course"<<endl;
        cout<<"2) Check Grades "<<endl;
        cout<<"3) Exit \n"<<endl;

        while(tab==1)
        {
            if(count!=0)
            {
                cout<<"MENU: (Type the corresponding number)\n"<<endl;
                cout<<"1) Register to a course / Deregister from a course"<<endl;
                cout<<"2) Check Grades "<<endl;
                cout<<"3) Exit \n"<<endl;

            }
            count++;
            string choice;
            string ch;
            cin>>choice;
            string coursename;
            if(choice=="1")
            {
                cout<<"Register or de-register? (R/D)"<<endl;
                cin>>ch;
                if(ch=="R")
                {
                    cout<<"Enter course name"<<endl;
                    cin>>coursename;
                    if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int courseno = toint(nametoroll(coursename,1));
                        if(courseno>5)
                        {
                            cout<<"Course hasn't been created yet\n"<<endl;
                            cout<<"Choose options (1-3)"<<endl;
                            continue;
                        }
                        if(c[courseno-1].checkgradeassignment(coursename)==1)
                        {
                            cout<<"Student/s have already been assigned grades in this course"<<endl;
                            cout<<"Cannot register\n"<<endl;
                            cout<<"Choose options (1-3)"<<endl;
                            continue;
                        }
                        c[courseno-1].registerstud(coursename, username, "R");
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-3)"<<endl;
                    }
                }
                else if(ch=="D")
                {
                    cout<<"Enter course name"<<endl;
                    cin>>coursename;
                    if(checknamnum(1,coursename)==0)
                    {
                        cout<<"Invalid course name"<<endl;
                        cout<<"Course name format similar to course ID, egs: CS1023"<<endl;
                        cout<<"Choose options (1-6)"<<endl;
                        continue;
                    }
                    else
                    {
                        int courseno = toint(nametoroll(coursename,1));
                        if(courseno>5)
                        {
                            cout<<"Course hasn't been created yet\n"<<endl;
                            cout<<"Choose options (1-3)"<<endl;
                            continue;
                        }
                        if(c[courseno-1].checkgradeassignment(coursename)==1)
                        {
                            cout<<"Student/s have already been assigned grades in this course"<<endl;
                            cout<<"Cannot de-register\n"<<endl;
                            cout<<"Choose options (1-3)"<<endl;
                            continue;
                        }
                        c[courseno-1].registerstud(coursename, username, "X");
                        cout<<"Request was processed\n"<<endl;
                        cout<<"Choose options (1-3)"<<endl;
                    }
                }
                else
                {
                    cout<<"Invalid Input\n"<<endl;
                    cout<<"Choose options (1-3)"<<endl;
                }
            }

            else if(choice=="2")
            {
                for(int i = 0; i<5; i++)
                {
                    c[i].displaygrades(username);
                }
                cout<<"\nRequest was processed\n"<<endl;
                    cout<<"Choose options (1-3)"<<endl;
            }

            else if(choice=="3")
            {
                tab=0;
            }

            else
            {
                cout<<"Invalid Input\n"<<endl;
                cout<<"Choose options (1-3)"<<endl;
            }
        }


    }

    else
    {
        cout<<"Invalid username";
    }
}