// Program 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Student.h"

void outputRoster(vector<Student> students) {
    int column = 20;
    for (unsigned int i = 0; i < students.size(); i++) {
        Student tempStudent = students.at(i);
        cout << left << setw(column);
        cout << tempStudent.GetFirstName();
        cout << left << setw(column);
        cout << tempStudent.GetLastName();
        cout << left << setw(column);
        tempStudent.DisplayCourseAverage(cout);
        cout << left << setw(column);
        cout << tempStudent.LetterGrade();
        cout << endl;
    }
    
}
int main()
{
    vector<Student> students;
    ifstream input;
    input.open("Program4Data.txt");
    
    while(true){
        Student tempStudent = Student();
        if (!tempStudent.ReadData(input)) {
            break;
        }
        students.push_back(tempStudent);
    }

    input.close();
    
    outputRoster(students);

}
