Mini-AIMS project:


Works for (upto) 20 students, 5 courses, and 5 faculty members.
Code was developed on MacOS

Student/Course/Faculty data:
All numbers associated with student/course/faculty are 3 characters long.
The students have a name (string, egs: Rohit Desai) and a roll number. The format of
the roll number is Rxy, where xy ranges from 01 to 20.
The faculty have a name (string, egs: Suresh Kumar) and a faculty number. The format of
the faculty number is Fxy, where xy ranges from 01 to 05. A faculty member can only be assigned 
to a single course.
The courses have a name (format similar to course ID, egs: CS1023) and a course number. The
format of the course number is Cxy, where xy ranges from 01 to 05.
The admin must manually enter the names, numbers, etc. 

Data storage:

The code uses text files to store the data. "list.txt" stores the list of students, faculty, and 
courses (default-"N/A"). Whenever a new course is created, a new text-file, "course_name.txt" is
created.  This file contains info about the course; the name, the number, the faculty assigned,
whether it is floated or not, and the grade-list of students.
The grade-list also stores info about whether the students are registered or not. An 'X'
indicates that the student hasn't registered, while an 'R' indicates that they have.

Logging in:

The code expects two command line arguments, ./a.out and a username.
The student roll number, faculty number and A01 act as the student username, faculty username
and admin username respectively. Entering "./a.out username" logs the person in as the respective
user.

Menu Options:
Admin-
1) Add/Delete course
2) Add/Delete faculty members
3) Float courses
4) Add/Delete students
5) Register/Deregister students from courses
6) Exit

Faculty-
1) Check students enrolled in course and submit grades
2) Exit

Students-
1) Register to a course / Deregister from a course
2) Check Grades 
3) Exit 

The corresponding number has to be entered.
The coursename, course number, faculty number etc. have to be entered in the correct format. 
