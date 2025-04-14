/*
 Thomas Li
 CS10C
 08/28/2024
 Instructor: Dave Harden
 main.cpp

 This program manages a list of students' grades using a C++ `map`. The program preloads
 the map with several students' names and corresponding grades. It then allows the user
 to input a student's name and a new grade. If the student's name already exists in the map,
 the program updates the student's grade and displays the original and new grades. If the
 student's name is not found, the program adds the student and their grade to the map
 and informs the user of this action.

*/
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string studentName;
	double studentGrade;

	map<string, double> studentGrades; //list to store student names and corresponding student names

	// Students' grades (pre-entered)
	studentGrades.emplace("Harry Rawlins", 84.3);
	studentGrades.emplace("Stephanie Kong", 91.0);
	studentGrades.emplace("Shailen Tennyson", 78.6);
	studentGrades.emplace("Quincy Wraight", 65.4);
	studentGrades.emplace("Janine Antinori", 98.2);

	getline(cin, studentName);
	cin >> studentGrade;

	if (studentGrades.count(studentName)) {
		cout << studentName << "'s original grade: " << studentGrades[studentName] << endl;
		studentGrades[studentName] = studentGrade;
		cout << studentName << "'s new grade: " << studentGrades[studentName] << endl;
	}
	else {
		cout << "Original name/grade not found. Adding to the datatable." << endl;
		studentGrades.emplace(studentName, studentGrade);
	}
}