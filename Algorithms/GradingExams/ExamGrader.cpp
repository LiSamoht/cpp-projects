/*
 Thomas Li
 Instructor: Sarkar S
 CS10B, Spring 2024
 Assignment 3a [12 points]—Using functions for file data processing ...(b) Drivers License Program (actually: an exam grader)

This program takes input and output file names from the user, reads a file containing exam answers, validates the answers, grades them,
and writes the results to an output file.It includes functions for handling file input / output, grading answers, validating answers, 
and reading files for display.
*/
#include <fstream>
#include <iostream>
#include <string>
//#include <filesystem> // TO FIND PATH, INCLUDE THIS
using namespace std;

void getuserinFile(/*in/out*/string& userFileName);
void getuseroutFile(/*out*/string& userFileName);
void GradeAndCopyInToOut(/*in*/const string inFileName, /*in*/ const string outFileName);
int numCorrectAnswers(/*in*/const string userAns,/*in*/ const string ansKey);
string isvalidAnswer(/*in*/ const string answers, /*in*/const string answerKey);
void readandCoutFile(/*in*/const string fileName);

int main() {
	string userInName;
	string userOutName;

	//cout << "Current path is " << filesystem :: current_path(); // Current path; attach txt file to the outputted location.
	getuserinFile(userInName);
	readandCoutFile(userInName);

	getuseroutFile(userOutName);
	GradeAndCopyInToOut(userInName,userOutName);
	readandCoutFile(userOutName);

}





/*
 This function prompts the user for a filename, inspects it/validates by seeing if it can open a file with that name, and then continuously asks for
 a valid filename if it could not open the user's file. The userFileName is then passed back to the caller.
*/
void getuserinFile(/*in/out*/string& userFileName) {
	//Post: the user's file is found and opened and the userFileName is passed back to the caller (getuserinFile(userInName), line 29)
	ifstream inputFile;
	cout << "Enter data input file name: ";
	cin >> userFileName;

	inputFile.open(userFileName.c_str());
	while (!inputFile) {
		cout << "File not found, please retype correct filename: ";
		cin >> userFileName;
		inputFile.open(userFileName.c_str());
	}
}





/*
 This function prompts the user for the output file name, telling the user that the exam grading data is sent to the specified output file. 
*/
void getuseroutFile(/*out*/string& userFileName) {
	//Pre: the program has already found the user's input file and the user provides a new filename when prompted thus no validation is needed)
	//Post: the user's output file name is passed to the caller. userFileName sent to userOutName in main.
		cout << endl << "Enter data output file name: ";
	cin >> userFileName;
	cout << "Exam grading data sent to output file" << endl;
}





/*This function reads exam data from an input file, grades the answers, and writes the results to an output file.
It first opens the input and output files. Then, it reads the exam key from the input file and writes it to the
output file. After that, it reads each user's answers from the input file, validates them against the exam key,
calculates the number of correct answers, and writes the user ID along with the number of correct answers or an
error message to the output file. Finally, it closes the input file, leaving the output file open to be outputted
or read later.*/
void GradeAndCopyInToOut(/*in*/const string inFileName, /*in*/const string outFileName) {
	//Pre: inFileName and outFileName are valid file names that are able to be accessed, opened, and bound to ifstream or ofstream.
	//Post: The exam data from the input file specified by inFileName is graded and copied to the output file specified by outFileName.
	ifstream inputFile;
	ofstream outputFile;
	outputFile.open(outFileName.c_str());
	inputFile.open(inFileName.c_str());


	string examKey;
	if (inputFile >> examKey) {
		outputFile << examKey << endl;
	}


	string userAnswers;
	int userId;
	int numCorrect;
	string errorAnswer;
	while (inputFile >> userId >> userAnswers) {
		errorAnswer = isvalidAnswer(userAnswers, examKey);
		if (errorAnswer == "No Error") {
			numCorrect = numCorrectAnswers(userAnswers, examKey);
			outputFile << userId << " " << numCorrect << endl;
		}
		else {
			outputFile << userId << " " << errorAnswer << endl;
		}
	}
	inputFile.close();
}




/*
This function checks if a set of user answers is valid compared to an answer key. It examines the length of 
the user's answers and the answer key to determine if there are too many, too few, or an invalid number of
answers. Additionally, it verifies that each answer is within the range of 'a' to 'f'. The function returns 
a message indicating any errors found, or "No Error" if the user's answers are valid.
*/
string isvalidAnswer(/*in*/const string answers, /*in*/const string answerKey) {
	//Precondition: userAns and ansKey are valid strings representing user answers and the answer key respectively.
    //Postcondition : The return value represents the number of correct answers in userAns when compared to ansKey.
	string outputMessage = "No Error";
	if (answers.size() > answerKey.size()) {
		return outputMessage = "Too many answers";
	}
	else if (answers.size() < answerKey.size()) {
		return outputMessage = "Too few answers";
	}

	for (char i : answers) {
		if (i < 'a' || i > 'f') {
			return outputMessage = "Invalid Answers";
		}
	}
	return outputMessage;
}





/*
his function calculates the number of correct answers provided by the user, given their answers and the correct answer key. 
It compares each corresponding answer in the user's response (userAns) to the corresponding answer in the answer key (ansKey). 
If they match, it increments a counter. The function returns the total number of correct answers found.
*/
int numCorrectAnswers(/*in*/const string userAns, /*in*/const string ansKey) {
	//Precondition: answers and answerKey are valid strings representing user answers and the answer key respectively.
    //Postcondition: Returns a message indicating if the user's answers are valid or not.
	int numCorrect = 0;
	for (int i = 0; i < ansKey.size(); i++) {
		if (userAns.at(i) == ansKey.at(i)) {
			numCorrect++;
		}
	}
	return numCorrect;
}





/*
This function reads the contents of a file specified by fileName and prints each line to the console. The precondition ensures
that fileName contains the name of a valid file. After opening the file, the function reads each line using getline() and outputs
it to the console. Finally, the file is closed.
*/
void readandCoutFile(/*in*/const string fileName) {
	//Precondition: fileName contains the name of a valid file.
    //Postcondition: The contents of the file specified by fileName are printed to the console.
	ifstream IOfile(fileName);

	string line;
	while (getline(IOfile, line)) {
		cout << line << endl;
	}
	IOfile.close();
}


/*
SAMPLE OUTPUT:
Enter data input file name: exams.dat
File not found, please retype correct filename: asdkl
File not found, please retype correct filename: dflkadflgag
File not found, please retype correct filename: exams.txt
abcdefabcdefabcdefab
1234567 abcdefabcdefabcdefab
9876543 abddefbbbdefcbcdefac
5554446 abcdefabcdefabcdef
4445556 abcdefabcdefabcdefabcd
3332221 abcdefghijklmnopqrst

Enter data output file name: scores.txt
Exam grading data sent to output file
abcdefabcdefabcdefab
1234567 20
9876543 15
5554446 Too few answers
4445556 Too many answers
3332221 Invalid Answers
*/