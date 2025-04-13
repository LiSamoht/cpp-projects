/*
Thomas Li

This program calculates the mode of an array of integers entered by the user. It begins by prompting the user to input a list of integers, checking to make
sure the user inputs a integer, which are stored in an array named userArr. Then, it calls the CalculateMode function passing the array and its size as 
arguments, and stores the result in the variable mode. The CalculateMode function first checks if the array is empty or contains negative values. If
either condition is true, it returns -1. Otherwise, it sorts the array in ascending order using the selectionSort function, which implements the
selection sort algorithm.  After sorting, it iterates through the array to find the mode, i.e., the value that occurs most frequently. If multiple
values occur with the same highest frequency, it returns the smallest one. Finally, the program prints the calculated mode.

*/

#include <iostream>
using namespace std;

int CalculateMode(/*in/out*/int userArr[], /*in*/int ARRAY_SIZE);
void selectionSort(/*in/out*/int userArr[], /*in*/ int ARRAY_SIZE);
void swap(/*in/out*/int& num1, /*in/out*/int& num2);

int main() {
		const int ARRAY_SIZE = 20; //ENTER/CHANGE THE NUMBER OF VALUES IN ARRAY
		int userArr[ARRAY_SIZE];

		cout << "Enter " << ARRAY_SIZE << " integers: \n";
		for (int i = 0; i < ARRAY_SIZE; i++) {
			//check if the user entered an integer, if not, clear cin stream, decrement i so that we stay on same element.
			if (!(cin >> userArr[i])) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize> ::max(), '\n');
				cout << "Invalid input. Please enter an integer" << endl;
				i--;
			}

		}

		int mode = CalculateMode(userArr, ARRAY_SIZE);
		cout << endl << "Your mode is: " << mode;
}




/*
This function calculates the mode of an array of integers. It returns -1 if the array is empty, contains negative values, or if the array
has no value occuring more than once. It begins by checking two of these conditions, and then it calls the selectionSort function to sort the 
array ascending. This will ensure that, if any values are repeated, they will be adjacent to one another. The function then iterates through
the sorted array, tracking the longest chain of equivalent values and saving that specific value. If there is no longest chain of equivalent values, then
every value occurs only once and the mode is never changed, so the function will return the initialized mode value of -1. IF THE ARRAY HAS MULTIPLE MODES, 
it will simply return one of them (specifically the mode with the smallest value) as it only will save the first mode it finds in the sorted list (which
will always be smallest mode as the list is sorted ascending).
*/
int CalculateMode(/*in/out*/int userArr[], /*in*/int ARRAY_SIZE) {
	// Pre-condition: userArr is an array of nonnegative integers with ARRAY_SIZE elements
    /* Post - condition: Returns the mode of the array.If the array has no mode(none of the values occur more than once), or if the array has
	negative values, or if the array is empty, it will return - 1*/
	
	//check if array is empty, check if array has negative values.
	if (ARRAY_SIZE == 0) {
		return -1;
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (userArr[i] < 0) {
			return -1;
		}
	}

	selectionSort(userArr, ARRAY_SIZE);

	int maxFreq = 1;
	int mode = -1; //initialize the mode to -1. If the mode is left unchanged, then none of the values occur more than once so we return -1.
	int currentFreq = 1;
	for (int i = 0; i < (ARRAY_SIZE - 1); i++) {
		while (userArr[i] == userArr[i + 1]) {
			currentFreq++;
			i++; /*continue with the next element in the array.This won't mess up our original for loop with the i++, because we will only increment when
			have same values.*/
		}
		if (currentFreq > maxFreq) {
			maxFreq = currentFreq;
			mode = userArr[i];
			currentFreq = 1;
		}
	}


	return mode;

}




/*
This function performs the selection sort method on an array of integers. It continuously searches for 
the smallest values in the array, by putting them at the beginning and cutting them from the search range
*/
void selectionSort(/*in/out*/int userArr[], /*in*/ int ARRAY_SIZE) {
	// Pre-condition: userArr is an array of integers with ARRAY_SIZE elements
    // Post-condition: userArr will be sorted in ascending order
	int minIndex;

	for (int start = 0; start < (ARRAY_SIZE - 1); start++) {
		minIndex = start;

		for (int j = start + 1; j < ARRAY_SIZE; j++) {
			if (userArr[j] < userArr[minIndex]) {
				minIndex = j;
			}
		}
		swap(userArr[minIndex], userArr[start]);
	}
}




/* 
This Function simply swaps the values of two integers
*/
void swap(/*in/out*/int& num1, /*in/out*/int& num2) {
	// Pre - condition: num1 and num2 are integer variables
	// Post-condition: num1 will hold the value of num2 and num2 will hold the value of num1 after the swap
	int tempnum = num1;
	num1 = num2;
	num2 = tempnum;
}

/*SAMPLE OUTPUT FOR ARRAY_SIZE = 20: 
"Enter 20 integers:
123
j
Invalid input. Please enter an integer
a
Invalid input. Please enter an integer
s
Invalid input. Please enter an integer
1
2
3
4
5
6
7
8
9
10
10
10
10
11
11
12
13
14
10

Your mode is: 10
*/