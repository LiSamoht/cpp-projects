/*
Thomas Li
CS10B Spring 2024
04/24/2024
Sarkar S
File Name: mystring.h

Description:
	This header file defines the MyString class, which provides functionality for handling strings with dynamic memory allocation.

Public Function Prototypes:

MyString();
pre: None
post: Constructs an empty MyString object.

MyString(const char* inString);
pre: inString points to a valid C-style string.
post: Constructs a MyString object and initializes it with the content of the given C-style string.

~MyString();
pre: None
post: Destructs the MyString object and deallocates the dynamically allocated memory.

MyString(const MyString& copyMe);
pre: None
post: Constructs a new MyString object as a deep copy of the given MyString object.

MyString operator=(const MyString& right);
pre: None
post: Assigns the contents of the given MyString object to this object and returns a reference to this object.

int length() const;
pre: None
post: Returns the number of characters in the string.

char operator[] (int index) const;
pre: index is a valid index within the string.
post: Returns the character at the specified index without allowing modification.

char& operator [] (int index);
pre: index is a valid index within the string.
post: Returns a reference to the character at the specified index, allowing modification.

friend std::ostream& operator << (std::ostream& out, const MyString printMe);
pre: None
post: Outputs the content of the MyString object to the specified output stream.

friend std::istream& operator >> (std::istream& in, MyString& readMe);
pre: None
post: Reads input from the specified input stream and stores it in the MyString object.

void readline(std::istream& in, char delimiter);
pre: None
post: Reads characters from the specified input stream up to the specified delimiter and stores them in the MyString object.

friend MyString operator + (const MyString leftOp, const MyString rightOp);
pre: None
post: Concatenates two MyString objects and returns the result as a new MyString object.

MyString operator += (const MyString rightOp);
pre: None
post: Concatenates the specified MyString object with this object and returns this object.

friend bool operator < (const MyString leftOp, const MyString rightOp);
friend bool operator <= (const MyString leftOp, const MyString rightOp);
friend bool operator > (const MyString leftOp, const MyString rightOp);
friend bool operator >= (const MyString leftOp, const MyString rightOp);
friend bool operator == (const MyString leftOp, const MyString rightOp);
friend bool operator != (const MyString leftOp, const MyString rightOp);
pre: None
post: Performs the specified comparison operation between two MyString objects and returns the result.

static const int MAX_INPUT_SIZE = 127;
Description: Maximum size for input strings.

*/
#pragma warning(disable:4996)
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring {
	class MyString {
	private:
		char* str;
	public:
		static const int MAX_INPUT_SIZE = 127;
		int length() const;

		MyString(); //default constructor
		MyString(const char* inString); //parametrized constructor

		friend std::ostream& operator << (std::ostream& out, const MyString printMe);

		char operator[] (int index) const; //const version allowing only read access
		char& operator [] (int index);

		friend bool operator < (const MyString leftOp, const MyString rightOp);
		friend bool operator <= (const MyString leftOp, const MyString rightOp);
		friend bool operator > (const MyString leftOp, const MyString rightOp);
		friend bool operator >= (const MyString leftOp, const MyString rightOp);
		friend bool operator == (const MyString leftOp, const MyString rightOp);
		friend bool operator != (const MyString leftOp, const MyString rightOp);

		~MyString(); //class destructor
		MyString operator=(const MyString& right); // = operator used in client code
		MyString(const MyString& copyMe); //copy constructor for deep copying.

		friend std::istream& operator >> (std::istream& in, MyString& readMe);
		void readline(std::istream& in, char delimiter);
		friend MyString operator + (const MyString leftOp, const MyString rightOp);
		MyString operator += (const MyString rightOp);
	};
}

#endif
