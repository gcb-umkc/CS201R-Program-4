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

//Uses insertion sort and string integer comparisons
void sortNames(vector<Student>& students) {
    for (unsigned int i = 0; i < students.size(); i++) {
        unsigned int j = i;
        while (j > 0 && 
            (students.at(j).GetLastName() < students.at(j - 1).GetLastName() || 
            (students.at(j).GetLastName() == students.at(j - 1).GetLastName() && students.at(j).GetFirstName() < students.at(j - 1).GetFirstName()))
            ) {
            Student temp = students.at(j);
            students.at(j) = students.at(j - 1);
            students.at(j - 1) = temp;
            --j;
        }
    }
    return;
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
    sortNames(students);

    outputRoster(students);

}
