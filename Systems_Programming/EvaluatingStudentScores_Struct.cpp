/*
 Thomas Li
 Array of Structures

 This program is designed to manage student data, calculate their average test scores, and assign corresponding grades based on their performance. 
 It begins by prompting the user to input the number of students. Then, it dynamically allocates memory for an array of Student structures based 
 on this input. The getInfo function iterates through each student, prompting for their name, ID number, and four test scores while ensuring
 validation for the ID number and test scores. After gathering this information, it calculates the average test score and assigns a grade to each
 student based on predefined criteria. The showInfo function then displays a formatted course grade report on the console, listing each student's name,
 ID number, average test score, and grade. Additionally, input validation functions getValidID and getValidScores ensure that the entered data adheres
 to specified constraints. Finally, the program deallocates the dynamically allocated memory before termination, ensuring proper memory management.
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_TESTS = 4; //a global constant

struct Student {
	string name;
	string IDnum;
	int Scores[NUM_TESTS];
	double Average;
	char Grade;
};

//USING Struct Student
Student* initArrays(/*in*/ int);
void getInfo(/*out*/ Student[], /*in*/ int);
void showInfo(/*in*/ const Student[], /*in*/ int);

//for Input Validation
void getValidID(string& input);
void getValidScores(int& input, int testNum);

int main() {
	int numStudents;
	cout << "How many students? ";
	while (!(cin >> numStudents) || numStudents < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid number of students. Enter a positive integer number of students." << endl;
		cout << "How many students? ";
	}

	Student* students = initArrays(numStudents);

	getInfo(students, numStudents);
	showInfo(students, numStudents);


	delete[] students;

}


/*
 Dynamically allocates memory for an array of Student structs based on the number of students. Returns a pointer to allocated memory block with numStudents
 Student structs.
*/
Student* initArrays(/*int*/int numStudents) {
	//pre: numStudents is a positive integer
	//post: returns a pointer to allocated memory block with numStudents Student structs.
	return new Student[numStudents];
}


/*
The getInfo function iterates over each student in the array, prompting the user to input their name, ID number, and four test scores. 
It validates the ID number to ensure it contains only digits and the test scores to ensure they are within the range of 0 to 100. 
After gathering all necessary data, it calculates the average test score for each student and assigns a corresponding course grade based 
on the average score. This function ensures accurate and validated input for each student, facilitating the calculation of their average 
test score and course grade.
*/
void getInfo(Student students[], int numStudents) {
	//pre: students[] must point to a valid memory block of Student structs, numStudents must be a positive integer.
	//post: Populates the students[] array with information about each student including name, ID number, test scores, average score, and grade.
	for (int i = 0; i < numStudents; i++) {

		cout << "Student name: ";
		cin.ignore();
		getline(cin, students[i].name);

		getValidID((students[i]).IDnum);

		int input;
		for (int j = 0; j < NUM_TESTS; j++) {
			getValidScores(input, j+1);
			students[i].Scores[j] = input;
		}

		double sum = 0;
		for (int k = 0; k < NUM_TESTS; k++) {
			sum += students[i].Scores[k];
		}
		students[i].Average = sum / NUM_TESTS;

		if (students[i].Average >= 91) {
			students[i].Grade = 'A';
		}
		else if (students[i].Average >= 81) {
			students[i].Grade = 'B';
		}
		else if (students[i].Average >= 71) {
			students[i].Grade = 'C';
		}
		else if (students[i].Average >= 61) {
			students[i].Grade = 'D';
		}
		else {
			students[i].Grade = 'F';
		}
	}
}

/*
 Validates a user's ID number. Ensures that every character in the user's input is a digit.
*/
void getValidID(string& input) {
	//pre: none
	//post: input contains a valid ID number consisting of digits only
	bool valid;
	do {

		cout << "ID Number: ";
		getline(cin, input);
		valid = true;

		for (int i = 0; i < input.size(); i++) {
			if (!isdigit(input.at(i))) {
				cout << "Invalid ID Number. Must only contain digits." << endl;
				valid = false;
				break;
			}
		}

	} while (!valid);
}

/*
 Validates a user's test score(s). Ensures that the input is an integer between 0 and 100.
*/
void getValidScores(int& input, int testNum) {
	// Precondition: None
    // Postcondition: input will contain a valid test score between 0 and 100
	bool valid;
	do {
		valid = true;
		cout << "        Test # " << testNum << ": ";
		if (!(cin >> input) || input < 0 || input > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid test score." << endl;
			valid = false;
		}
	} while (!valid);
}


/*
 
The function showInfo takes an array of Student structures (students[]) and the number of students (numStudents) as input parameters. 
It is responsible for displaying a formatted course grade report on the console. It first prints a header indicating the start of the 
report, followed by a title indicating the nature of the report. Then, it iterates through each student in the array, printing their name,
ID number, average test score, and course grade. Each student's information is displayed in a structured format with appropriate labels. 
*/
void showInfo(const Student students[], int numStudents) {
	//pre: students[] must point to a valid memory block of Student structs, numStudents must be a positive integer
	//post: Displays the course grade report including student names, ID numbers, average test scores, and grades
	cout << "\n===========================\n";
	cout << "Course Grade Report\n";
	cout << "===========================\n";

	for (int i = 0; i < numStudents; i++) {
		cout << "Student name: " << students[i].name << endl;
		cout << "ID number: " << students[i].IDnum << endl;
		cout << "Average test score: " << fixed << setprecision(1) << students[i].Average << endl;
		cout << "Grade: " << students[i].Grade << endl << endl;
	}
}