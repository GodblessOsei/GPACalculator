# GPACalculator
Overview
The CGPA Calculator is a C++ program designed to help students calculate their Grade Point Average (GPA) for a semester based on their course grades. The program reads course and student details from files, allows users to input their grades, and calculates their GPA. The results are then saved to a file for future reference.

Features
Course Management: Reads course details (name, code, credits) from a file (courses.txt).

Student Management: Reads existing student details (name, ID, major, CGPA) from a file (student.txt).

GPA Calculation: Computes the semester GPA based on entered grades and course credits.

Data Persistence: Saves new student records to student.txt for future use.

Input Validation: Ensures valid course codes and grades are entered.

Prerequisites
A C++ compiler (e.g., g++).

Input files:

courses.txt: Contains course details in the format:
Course Name, Course Code, Credits
Example:
Data Structures, CS-UH 2002, 4

student.txt: Contains student details in the format:
Name, ID, Major, CGPA
Example:
Godbless Osei Mensah,gmo6996,Computer Science,3.41675

How to Use
Prepare Input Files:

Ensure courses.txt and student.txt are in the same directory as the program.

Populate courses.txt with your course details and student.txt with existing student records (if any).

Compile the Program:

g++ cgpacalc.cpp -o cgpacalc

Run the Program:

./cgpacalc

Follow Prompts:

Enter your name, student ID, major, academic year, and semester.

Specify the number of courses you are taking.

For each course, enter the course code and your grade.

The program will validate inputs and calculate your GPA.

View Results:

Your GPA for the semester will be displayed.

Your details and GPA will be appended to student.txt.

