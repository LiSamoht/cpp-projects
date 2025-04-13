/*
 Thomas Li
 Instructor: Sarkar S
 CS10B Spring 2024

 Assignment 6a [15 points] - Character and String related  processing ...
 (1) Sum of Digits in a String

 This program prompts the user to enter a series of digits with no spaces between them.It validates the input,
 ensuring that only digits are entered, and displays an error message if non - digit characters are detected. After
 receiving valid input, the program calculates and displays the sum of all the digits, as well as the highest and
 lowest digits in the input string. The implementation utilizes separate functions for input validation, sum
 calculation, finding the highest digit, and finding the lowest digit, enhancing modularity, simplicity, and readability.
*/
#include <iostream>
#include <string>
using namespace std;

void GetValidInput(/*in/out*/string& input);

int SumInput(/*in*/string input);
int highestDigit(/*in*/string input);
int lowestDigit(/*in*/string input);

int main() {
	string userStr;
	GetValidInput(userStr);

	int sumDigits = SumInput(userStr);
	int maxDigit = highestDigit(userStr);
	int minDigit = lowestDigit(userStr);

	cout << "The sum of those digits is " << sumDigits << endl;
	cout << "The highest digit is " << maxDigit << endl;
	cout << "The lowest digit is " << minDigit << endl;
	
	return 0;
}


/*
 Prompts the user for input and validates it, ensuring it contains only digits through the usage of isdigit from <string>.
*/
void GetValidInput(/*in*/string& input) {
	// pre: none
    //post: The input string contains only digits
	bool validInput;
	do {
		validInput = true;
		cout << "Enter a series of digits with no spaces between them.\n";
		getline(cin, input);

		for (int i = 0; i < input.size(); i++) {
			if (!isdigit(input.at(i))) {
				validInput = false;
				cout << "Incorrect input....?" << endl << endl;
				break;
			}
		}

	} while (!validInput);
}


/*
 Calculates the sum of all the digits in the input string through iterating through the string and converting each character to an integer, adding
 it to the total.
*/
int SumInput(/*in*/string input) {
	//pre: the input string contains only digits (ensured from data validation).
	//post: return (sum of the digits in input).
	int sum = 0;
	for (int i = 0; i < input.size(); i++) {
		char currentchar = input.at(i); 

		//also can use currentchar - '0' to convert to an integer. Since the theme of the assignment is to use string-related processing, I'll use this.
		int currentint = stoi(string(1, currentchar)); 

		sum += currentint;
	}

	return sum;
}

/*
 Finds and returns the highest digit in the input string through iterating through the string and converting each character to an integer,
 utilizing simple conditional logic to locate the largest digit.
*/
int highestDigit(/*in*/string input) {
	//pre: the input string contains only digits (ensured from data validation)
	//post: return (highest digit).
	int max = stoi(string(1, input.at(0))); //initialized to the integer value of the first character in the string

	for (int i = 1; i < input.size(); i++) {
		char currentchar = input.at(i);
		int currentint = stoi(string(1, currentchar));
		
		if (currentint > max) {
			max = currentint;
		}
	}

	return max;
}


/*
 Finds and returns the lowest digit in the input string through iterating through the string and converting each character to an integer,
 utilizing simple conditional logic to locate the smallest digit.
*/
int lowestDigit(/*in*/string input) {
	//pre: the input string contains only digits (ensured from data validation)
	//post: return (lowest digit).
	int min = stoi(string(1, input.at(0))); //initialized to the integer value of the first character in the string

	for (int i = 1; i < input.size(); i++) {
		char currentchar = input.at(i);
		int currentint = stoi(string(1, currentchar));

		if (currentint < min) {
			min = currentint;
		}
	}

	return min;
}