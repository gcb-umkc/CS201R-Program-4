#include "Student.h"
#include <istream>
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student() {
	string first = "";
	string second = "";

	for (int i = 0; i < 5; i++) {
		quiz.at(i) = 0;
	}
	for (int i = 0; i < 3; i++) {
		exam.at(i) = 0;
	}
}

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

bool Student::WriteData(ostream& out) const {
	out << left << setw(20) << first << endl;
	out << left << setw(20) << second << endl;
	for (int i = 0; i < 5; i++) {
		out << right << setw(4) << quiz.at(i) << endl;
	}
	for (int i = 0; i < 3; i++) {
		out << right << setw(5) << exam.at(i) << endl;
	}
	
	//Returns if all data is output right
	if (out.fail()) {
		return false;
	}
	else {
		return true;
	}
}


string Student::GetFirstName() const {
	return first;
}

string Student::GetLastName() const {
	return second;
}

float Student::CourseAverage() const {
	float quizSum = 0;
	float examSum = 0;

	for (int i = 0; i < 5; i++) {
		quizSum += quiz.at(i);
	}
	for (int i = 0; i < 3; i++) {
		examSum += exam.at(i);
	}
	float quiz = quizSum / (20 * 5);
	float exam = examSum / (20 * 3);

	float total = quiz * (65) + quiz * (35);
	return total;
}

bool Student::DisplayCourseAverage(ostream& out) const {
	out << setprecision(3) << fixed << CourseAverage();
	return !out.fail();
}

string Student::LetterGrade() const {
	float numGrade = CourseAverage();
	if (numGrade < 0) {
		return "Error";
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
}
