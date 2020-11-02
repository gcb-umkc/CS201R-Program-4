#pragma once
#include <istream>
#include <vector>
using namespace std;
class Student
{
public:
	Student();
	//Input Output 
	bool ReadData(istream& in);
	bool WriteData(ostream& out) const;

	//Accessor Methods
	string GetFirstName() const;
	string GetLastName() const;

	//Calculation Methods
	float CourseAverage() const;
	bool DisplayCourseAverage(ostream& out) const;
	string LetterGrade() const;

private:
	string first;
	string second;
	vector<int> quiz;
	vector<int> exam;
};

