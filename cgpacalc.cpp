#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <map>

using namespace std;

class student
{
private:
    string name;
    string id;
    string major;
    float cgpa;
    //float gpa;
public:
    // Default constructor
    student(/* args */): name(), id(), major("undeclared"), cgpa(4.0){}
    // Parameterized constructor
    student(string n, string i, string m, float cgpa)
        : name(n), id(i), major(m), cgpa(cgpa) {}

   //Destructor
    ~student() {}
};

class course
{
    
public:
    string courseName;
    string courseCode;
    int credits;
    course(/* args */): courseName(), courseCode(), credits(0) {}
    course(string name, string code, int cr)
        : courseName(name), courseCode(code), credits(cr) {}
    // Destructor
    ~course() {}
};



int main(){ 
    //Variables for student details
    string studentName;
    string studentId;
    string studentMajor;
    string academicYear;
    string semester;
    int numCourses;

    float totalCredits = 0.0;
    float totalGradePoints = 0.0;


    string dum_grade; // Temporary variable to hold grade input
    
    //map<string,string> stu_courseGrades; // Map to hold student course grades
    // Key: course code, Value: grade

    //map to course taken and grades
    //Key: course code, Value: grade
    map<string, float> gradesMap; // Map to hold course codes and corresponding grades
    gradesMap["A"] = 4.000;
    gradesMap["A-"] = 3.667;
    gradesMap["B+"] = 3.333;
    gradesMap["B"] = 3.000;
    gradesMap["B-"] = 2.667;
    gradesMap["C+"] = 2.333;
    gradesMap["C"] = 2.000;
    gradesMap["C-"] = 1.667;
    gradesMap["D+"] = 1.333;
    gradesMap["D"] = 1.000;
    gradesMap["F"] = 0.000;

    
    float GPA(0.0); // Variable to hold the calculated GPA
    
    //Variables for course details
    string courseName, courseCode;
    int courseCredits;
    
    //Map of courses
    //Key: course code, Value: course object
    map<string, course> coursesMap;
    
    
    // Read course details from a file
    //File contains course name, code, and credits  
    // Example file format:
    // Data Structures, CS-UH 2002, 4
    string dum_coursename(" "), dum_coursecode(" ");
    int dum_coursecredits(0); // Temporary variables to hold course details
    string courseDetails;
    
    cout << "Reading course details from file..." << endl;
    ifstream inputFile("courses.txt");// Open the file containing course details
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return -1;
    }
    while (inputFile){ 
        getline(inputFile, courseDetails);
        if (courseDetails.empty()) continue; // Skip empty lines
        
        int pos1 = courseDetails.find(',');
        if (pos1 == string::npos){
            cerr << "Invalid course details format." << endl;
            continue; // Skip this line if format is invalid
        }
        
        dum_coursename = courseDetails.substr(0, pos1);
        int pos2 = courseDetails.find(',', pos1 + 1);
        if (pos2 == string::npos){
            cerr << "Invalid course details format." << endl;
            continue; // Skip this line if format is invalid
        }
        dum_coursecode = courseDetails.substr(pos1 + 1, pos2 - pos1 - 1);
        dum_coursecredits = stoi(courseDetails.substr(pos2 + 1));

        // Create a course object and add it to the vector
        coursesMap[dum_coursecode] = course(dum_coursename, dum_coursecode, dum_coursecredits);
    }
    cout << "Course details read successfully." << endl;

    // Close the file after reading
    inputFile.close();

    //Map of students
    //Key: student ID, Value: student object
    map<string, student> studentsMap;


    
    //Read student details from file
    //File contains student name, ID, major, CGPA
    // Example file format:
    //Godless Osei,gmo1234,Computer Science,3.7
    string studentDetails;
    string dum_studentName(" "), dum_studentId(" "), dum_studentMajor(" ");
    float dum_studentCGPA(0.0); // Temporary variables to hold student details

    cout << "Reading student details from file..." << endl;
    ifstream studentFile("student.txt"); // Open the file containing student details
    if (!studentFile) {
        cerr << "Error opening student file." << endl;
        return -1;
    }
    while (studentFile)
    {
        getline(studentFile, studentDetails);
        if (studentDetails.empty()) continue; // Skip empty lines

        int pos1 = studentDetails.find(',');
        if (pos1 == string::npos) {
            cerr << "Invalid student details format." << endl;
            continue; // Skip this line if format is invalid
        }
        dum_studentName = studentDetails.substr(0, pos1);
        int pos2 = studentDetails.find(',', pos1 + 1);
        if (pos2 == string::npos) {
            cerr << "Invalid student details format." << endl;
            continue; // Skip this line if format is invalid
        }
        dum_studentId = studentDetails.substr(pos1 + 1, pos2 - pos1 - 1);
        int pos3 = studentDetails.find(',', pos2 + 1);
        if (pos3 == string::npos) {
            cerr << "Invalid student details format." << endl;
            continue; // Skip this line if format is invalid
        }
        dum_studentMajor = studentDetails.substr(pos2 + 1, pos3 - pos2 - 1);
        dum_studentCGPA = stof(studentDetails.substr(pos3 + 1));

        // Create a student object and add it to the map
        studentsMap[dum_studentId] = student(dum_studentName, dum_studentId, dum_studentMajor, dum_studentCGPA);
    }
    cout << "Student details read successfully." << endl;
    // Close the file after reading
    studentFile.close();
    

    cout<<"Welcome to CGPA Calculator!" << endl;
    cout<<"This program will help you calculate your CGPA based on your courses and grades." << endl;
    cout<<"Please enter your name: ";
    getline(cin, studentName); // Use getline to allow spaces in name
    cout<<"Please enter your student ID: ";
    cin>>studentId;
    cout<<"Please enter your major: ";
    getline(cin >> ws, studentMajor); // Use getline to allow spaces in major
    // Use cin >> ws to ignore leading whitespace before getline
    cout<<"Please enter your academic year: ";
    getline(cin >> ws, academicYear); // Use getline to allow spaces in academic year
    cout<<"Please enter your semester: ";
    cin>>semester;
    cout<<"How many courses are you taking this semester? ";
    cin>>numCourses;


    
    for (int i = 0; i < numCourses; i++)
    {
        cout<<"Please enter the course code for course " << (i + 1) << ": ";
        getline(cin >> ws, courseCode); // Use getline to allow spaces in course code
        // Check if the course code exists in the courses map
        if (coursesMap.find(courseCode) == coursesMap.end()) {
            cout << "Course code " << courseCode << " not found. Please enter a valid course code." << endl;
            i--; // Decrement i to repeat this iteration
            // Continue to the next iteration to re-prompt for the course code
            continue;
        }
        else {
            cout<<"Please enter your grade for " << coursesMap[courseCode].courseName << ": ";
            cin >> dum_grade;
            // Check if the grade is valid
            if (gradesMap.find(dum_grade) == gradesMap.end()) {
                cout << "Invalid grade entered. Please enter a valid grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F)." << endl;
                i--; // Decrement i to repeat this iteration  
            }
            else{
                // Store the course code and grade in the map
                //stu_courseGrades[courseCode] = dum_grade;

                // Add the credits of the course to totalCredits
                totalCredits += coursesMap[courseCode].credits;

                //total points
                totalGradePoints += coursesMap[courseCode].credits * gradesMap[dum_grade];
            }
        }
    }

    GPA = totalGradePoints / totalCredits; // Calculate GPA
    cout << "Your GPA for this semester is: " << GPA << endl;

    ofstream outputFile("student.txt", ios::app); // Open the file in append mode
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return -1;
    }
    // Write the student details to the file
    outputFile << studentName << "," << studentId << "," << studentMajor << "," << GPA << endl;
    outputFile.close(); // Close the file after writing

    
    
   
    return 0;
}





