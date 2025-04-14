/*
 Thomas Li
 CS10C
 08/28/2024
 Instructor: Dave Harden
 main.cpp

 This program checks whether a given line of text is a palindrome using a deque.
 A palindrome is a string that reads the same forwards and backwards. The program
 ignores non-alphabetic characters and assumes all alphabetic characters will be
 in lowercase. The input is read from the user, and the program outputs whether
 the input string is a palindrome or not. The input expects only to check alphabetical characters,
 omitting any non alphabetical characters.
*/
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	string line; //input string
	bool result = true; //hypothesis: yes is palindrome
	deque<char> str;

	getline(cin, line);

	for (auto c : line) {
		if (isalpha(tolower(c))) {
			str.push_back(c);
		}
	}

	while (str.size() > 1) {
		if (str.front() != str.back()) {
			result = false;
			break;
		}
		str.pop_front();
		str.pop_back();
	}

	if (result) {
		cout << "Yes, \"" << line << "\" is a palindrome." << endl;
	}
	else {
		cout << "No, \"" << line << "\" is not a palindrome." << endl;
	}
	return 0;
}