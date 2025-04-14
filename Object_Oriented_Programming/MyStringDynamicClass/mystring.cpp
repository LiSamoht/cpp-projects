/*
 Description: 
The MyString class provides a dynamic string manipulation mechanism in C++, offering functionalities like the standard C-style string operations but with the
added advantage of dynamic memory management. This class models a character array and provides various member functions for string operations such as length
determination, character access, concatenation, input/output stream handling, and more. With careful consideration of memory management, the MyString class
ensures proper allocation and deallocation of memory to prevent memory leaks. Additionally, it offers overloaded operators for intuitive string manipulation, 
allowing concatenation, comparison, and assignment operations to be performed seamlessly.

Class Invariant:
	- The str pointer points to a dynamically allocated character array.
	- The character array pointed to by str is null-terminated.
	- The length of the character array pointed to by str is always one greater than the length of the string it represents, to accommodate the null terminator.
*/
#include "mystring.h"
#include <cstring>
#include <cassert>

namespace cs_mystring {
	//finds the length of str
	int MyString::length() const {
		return strlen(str);
	}

	//default constructor: constructs an empty string
	MyString::MyString() {
		str = new char[1];
		str[0] = '\0';
	}

	//parametrized constructor: constructs inString as a c-string. Uses dynamically allocated memory
	MyString::MyString(const char* inString) {
		int len = strlen(inString);

		str = new char[len + 1];

		strcpy(str, inString);
	}

	//overloaded << operator to print out string
	std::ostream& operator << (std::ostream& out, const MyString printMe) {
		out << printMe.str;
		return out;
	}

	//[] operator for array indexing...allows direct access to individual characters of the string. This one only allows reading.
	char MyString::operator[] (int index) const {
		assert(index >= 0 && index <= MyString::length() - 1);
		return str[index];
	}

	//[] operator for array indexing...allows direct access to individual characters of the string.
	char& MyString::operator[] (int index) {
		assert(index >= 0 && index <= MyString::length() - 1);
		return str[index];
	}

	//overloaded comparison operators, uses strcmp from <cstring>
	bool operator<(const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) < 0;
	}
	bool operator<=(const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) <= 0;
	}
	bool operator>(const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) > 0;
	}
	bool operator>=(const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) >= 0;
	}
	bool operator==(const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) == 0;
	}
	bool operator != (const MyString leftOp, const MyString rightOp) {
		return strcmp(leftOp.str, rightOp.str) != 0;
	}

	//MyString destructor
	MyString::~MyString() {
		delete[] str;
	}

	//overloaded assignment operator
	MyString MyString::operator=(const MyString& right) {
		if (this != &right) { // Check for self-assignment
			delete[] str; // Deallocate existing memory

			// Perform deep copy
			str = new char[strlen(right.str) + 1]; // Allocate memory
			strcpy(str, right.str); // Copy data

		}
		return *this;
	}
	MyString::MyString(const MyString& copyMe) {
		str = new char[strlen(copyMe.str) + 1]; // Allocate memory
		strcpy(str, copyMe.str); // Copy data
	}

	//overloaded >> operator for reading.
	std::istream& operator >> (std::istream& in, MyString& readMe) {
		char temp[MyString::MAX_INPUT_SIZE + 1];

		in >> temp;
		delete[] readMe.str;
		readMe.str = new char[strlen(temp) + 1];
		strcpy(readMe.str, temp);
		
		return in;
	}

	//reads a line and discards the delimiter
	void MyString::readline(std::istream& in, char delimiter) {
		char temp[MAX_INPUT_SIZE + 1];
		in.getline(temp, MAX_INPUT_SIZE, delimiter);
		delete[] str;
		str = new char[strlen(temp) + 1];
		strcpy(str, temp);
	}

	//overloaded + operator. First calculates the correct size of the final string, then allocates memory for the result (deleted later), strcpy and strcat used.
	MyString operator + (const MyString leftOp, const MyString rightOp) {
		int size = strlen(leftOp.str) + strlen(rightOp.str) + 1;
		char* result = new char[size];
		strcpy(result, leftOp.str);
		strcat(result, rightOp.str);

		MyString concatenateStr(result);
		delete[] result;
		return concatenateStr;
	}

	//overloaded += operator.
	MyString MyString::operator += (const MyString rightOp) {
		*this = *this + rightOp;
		return *this;
	}
}
