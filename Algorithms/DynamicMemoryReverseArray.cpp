/*
	Thomas Li
	Instructor: Sarkar S
	CS10B Spring 2024
	Assignment 5a [18 points] (i) Reverse Array
	
	The program initializes a predefined array of integers, displaying its contents to the console. It then calls a function to create a 
	reversed copy of the array using dynamic memory allocation. The original and reversed arrays are both displayed to the user. 
	The core function, reverseArray, accepts an array and its size, dynamically allocates memory for a reversed array, and fills it 
	with elements from the original array in reverse order. The program concludes by deallocating the memory allocated for the reversed 
	array to prevent memory leaks. Each function is thoroughly documented with header comments specifying its purpose and pre/post conditions
	for correct usage.
*/

#include <iostream>
using namespace std;

int* reverseArray(/*in*/ const int[],/*in*/ int); //a value returning function that returns a pointer to an array
void showArray(/*in*/const int[],/*in*/ int);     // a void function to display array elements 

int main() {
	const int ARR_SIZE = 10; //PROGRAMER DEFINED ARRAY SIZE
	const int programArr[ARR_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //PROGRAMER DEFINED ARRAY LIST

	//display original array
	cout << "The contents of the original array are:" << endl;
	showArray(programArr, ARR_SIZE);
	cout << endl;

	//display reversed array
	cout << "The contents of the copy:" << endl;
	int* ReversedCopy = reverseArray(programArr, ARR_SIZE); //create reversed copy
	showArray(ReversedCopy, ARR_SIZE);
	cout << endl;
	
	delete[] ReversedCopy; //free dynamically allocated memory.
	return 0;
}


/*
	Displays the elements in an integer array, separated by a space from index 0 and ascending.
*/
void showArray(/*in*/const int arr[],/*in*/ int size) {
	//pre: arr[] is not null and size >= 0.
	//post: elemnts of arr[] displayed to the console.
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}


/*
	Creates a reversed copy of an integer array. It accepts an array of integers and its size as arguments,
	then creates a pointer (serving as a new array) that contains the elements of the original array but in reversed order.
	Dynamic memory allocation is used.
*/
int* reverseArray(/*in*/const int arr[],/*in*/ int size) {
	//pre: array arr[] is not null and size >= 0.
	//post: function returns a pointer to a newly allocated array that contains arr[] but in reverse order. Caller is responsible to deallocate to avoid memory leaks.
	
	int* reversedArrptr = new int[size]; //allocate memory for reversed array

	for (int i = 0; i < size; i++) {
		*(reversedArrptr + i) = arr[size - 1 - i];
	}

	return reversedArrptr;
}