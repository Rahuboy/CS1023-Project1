#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// inserts 'insert' after the string 'tobefore' in the file 'filename'
void insertstr(fstream& file, string tobefore, string insert, string filename)
{
    
    file.open(filename);

    int i=1;
    string contents;
    file.seekg(0, ios::beg);
    string s;
    getline(file,s);
    contents.append(s+'\n');
    while(s!=tobefore)
    {
        getline(file,s);
        i++;
        contents.append(s+'\n');
    }
        contents.append(insert+'\n');

    while(file.eof()!=1)
    {
        getline(file,s);
        contents.append(s+'\n');
    }

    //cout<<contents;

    file.close();

    file.open(filename, ios::trunc|ios::in|ios::out);

        file<<contents.substr(0,contents.length()-1);

    file.close();

}

//function  deletes string located after the string 'before' in the file 'filename'
void deletestr(fstream& file, string before, string filename)
{
     file.open(filename);

    int i=1;
    string contents;
    file.seekg(0, ios::beg);
    string s;
    getline(file,s);
    contents.append(s+'\n');
    while(s!=before)
    {
        getline(file,s);
        i++;
        contents.append(s+'\n');
    }
       
       getline(file,s);

    while(file.eof()!=1)
    {
        getline(file,s);
        contents.append(s+'\n');
    }

    //cout<<contents;

    file.close();

    file.open(filename, ios::trunc|ios::in|ios::out);

        file<<contents.substr(0,contents.length()-1);

    file.close();

}

//returns line 'lineno' from file 'filename'
string accesslineno(fstream& file, int lineno, string filename)
{
    file.open(filename);
    string s;
    for(int i=0; i<lineno; i++)
    {
        getline(file,s);
    }
    file.close();
    return s;
}

//checks file 'filename' for string 'tocheck'
//return value: if successful, line number of string; 0 otherwise
int checkfile(fstream& file, string tocheck, string filename)
{
    file.open(filename);
        string s;
        int i=1;
        while(file.eof()!=1)
        {
            getline(file,s);
            if(tocheck==s)
            {
                file.close();
                return i;
            }
            i++;
        }
        file.close();
        return 0;
}

//Returns either roll number or course number
//Modes: 1 for course, 2 for students, 3 for faculty
string idnumbr(int mode, int number)
{
    string s;
    if(mode==1)
    {
        s="C0"+to_string(number);
        return s;
    }
    else if(mode==2)
    {
        if(number<=9) return "R0"+to_string(number);
        else return "R" +to_string(number);
    }
    else
    {
        return "F0"+to_string(number);
    }
}

//converts course or roll number to integer
int toint(string rollno)
{
    return stoi(rollno.substr(1));
}