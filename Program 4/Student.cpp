#include "Student.h"
#include <istream>
#include <iostream>
#include <iomanip>
using namespace std;

//Default Constructor, sets name to blank and grades to 0
Student::Student() {
	string first = "";
	string second = "";

	for (int i = 0; i < 5; i++) {
		quiz.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		exam.push_back(0);
	}
}

//Reads data into the class data, returns true if successful
bool Student::ReadData(istream& in) {
	in >> first;
	in >> second;

	for (int i = 0; i < 5; i++) {
		in >> quiz.at(i);
	}
	for (int i = 0; i < 3; i++) {
		in >> exam.at(i);
	}
	
	//Returns if all data is read right
	if (in.fail()) {
		return false;
	}
	else {
		return true;
	}
}

//Outputs data to output stream and returns if it is successful
bool Student::WriteData(ostream& out) const {
	out << left << setw(20) << first;
	out << left << setw(20) << second;
	for (int i = 0; i < 5; i++) {
		out << right << setw(4) << quiz.at(i);
	}
	for (int i = 0; i < 3; i++) {
		out << right << setw(5) << exam.at(i);
	}
	cout << endl;
	
	//Returns if all data is output right
	if (out.fail()) {
		return false;
	}
	else {
		return true;
	}
}

//Returns first name of student
string Student::GetFirstName() const {
	return first;
}

//Returns last name of student
string Student::GetLastName() const {
	return second;
}

//Returns the course grade for a student
float Student::CourseAverage() const {
	float quizSum = 0;
	float examSum = 0;

	for (int i = 0; i < 5; i++) {
		quizSum += quiz.at(i);
	}
	for (int i = 0; i < 3; i++) {
		examSum += exam.at(i);
	}
	float quizAverage = quizSum / (20 * 5);
	float examAverage = examSum / (100 * 3);

	float total = examAverage * (65) + quizAverage * (35);
	return total;
}

//Outputs the course average to 3 decimal points
bool Student::DisplayCourseAverage(ostream& out) const {
	out << setprecision(3) << fixed << CourseAverage();
	return !out.fail();
}

//Converts numerical grade to letter grade using UMKC grading scale
string Student::LetterGrade() const {
	float numGrade = CourseAverage();

	//Rounds up grade to nearest integer
	numGrade = round(numGrade);

	//Returns invalid grade if lower than 0 or greater than 100
	if (numGrade < 0) {
		return "Invalid Grade";
	}
	else if (numGrade < 60) {
		return "F";
	}
	else if (numGrade <= 63) {
		return "D-";
	}
	else if (numGrade <= 67) {
		return "D";
	}
	else if (numGrade <= 69) {
		return "D+";
	}
	else if (numGrade <= 73) {
		return "C-";
	}
	else if (numGrade <= 77) {
		return "C";
	}
	else if (numGrade <= 79) {
		return "C+";
	}
	else if (numGrade <= 83) {
		return "B-";
	}
	else if (numGrade <= 87) {
		return "B";
	}
	else if (numGrade <= 89) {
		return "B+";
	}
	else if (numGrade <= 93) {
		return "A-";
	}
	else if (numGrade <= 100) {
		return "A";
	}
	else {
		return "Invalid Grade";
	}
}
