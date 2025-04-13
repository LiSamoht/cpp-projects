/*
Thomas Li
Instructor: Sarkar S
CS10B, Spring 2024

This C++ program prompts the user to input five real numbers and uses only selection control structure to 
find the median (without using arrays, loops, or sorting algorithms). The algorithm consists of three steps. 
First, it identifies the minimum value among the five, excluding it from the set. Next, it determines the 
second minimum among the remaining four values. Finally, it finds the minimum among the three remaining values, 
representing the "third least" in the original set, which is fundamentally equivalent to the median in a set of 5 values.
The code outputs the saved user-entered values as well as the calculated median, showcasing a clear and step-by-step
approach of using only selection control structures for an array-free and loop-free median calculation. However, it should be
noted that a sorting algorithm is much cleaner.

*/
#include <iostream>
using namespace std;

int main() {
	// Create variables to save user inputs and save them in correspondings "nums" 
	double UserNum1, UserNum2, UserNum3, UserNum4, UserNum5;
	double num1, num2, num3, num4, num5;

	//prompts user to enter in 5 number and assigns each to a corresponding "num" and "val". 
	cout << "Enter five real numbers below" << endl;
	cout << "Enter value for number 1; press return." << endl;
	cin >> UserNum1;
	num1 = UserNum1; //save userinput into "num"

	cout << "Enter value for number 2; press return." << endl;
	cin >> UserNum2;
	num2 = UserNum2; //save userinput into "num"

	cout << "Enter value for number 3; press return." << endl;
	cin >> UserNum3;
	num3 = UserNum3; //save userinput into "num"

	cout << "Enter value for number 4; press return." << endl;
	cin >> UserNum4;
	num4 = UserNum4; //save userinput into "num"

	cout << "Enter value for number 5; press return." << endl;
	cin >> UserNum5;
	num5 = UserNum5; //save userinput into "num"


	/*Step #1: Here, we are going to find the minimum of the list of 5 numbers.Once the minimum is determined, we wish to exclude it
	from the rest of the 5 numbers so that we may find the "next" minimum*/

	//Initialize the minimum as num1
	double min1 = num1;
	//Create 4 "newnums" in order to store the next 4 numbers and exclude the minimum.
	double newnum1 = num2, newnum2 = num3, newnum3 = num4, newnum4 = num5;
	// Compare each subsequent number with the current minimum
	if (num2 < min1) {
		min1 = num2;
			newnum1 = num1; //store the "non-minimum" values into 4 new places to exclude the minimum.
			newnum2 = num3;
			newnum3 = num4;
			newnum4 = num5;
	}
	if (num3 < min1) {
		min1 = num3;
		newnum1 = num1;
		newnum2 = num2;
		newnum3 = num4;
		newnum4 = num5;
	}
	if (num4 < min1) {
		min1 = num4;
		newnum1 = num1;
		newnum2 = num2;
		newnum3 = num3;
		newnum4 = num5;
	}
	if (num5 < min1) {
		min1 = num5;
		newnum1 = num1;
		newnum2 = num2;
		newnum3 = num3;
		newnum4 = num4;
	}

	
	/* Step #2: We have already determined and excluded the minimum. We now have only the 4 numbers (excluding the minimum), and we 
	will apply the same algorithm to find the minimum of these 4. Ultimately, we are trying to find the "second least" value of our
	original 5 numbers. */

	//Initialize the minimum as our starting place
	double min2 = newnum1;
	/*Create 3 "finalnums" to store the other 3 numbers that aren't the minimum. This is the final time we will store numbers (as median
	will be the "third least" value in the set of 5 numbers).*/
	double finalnum1 = newnum2, finalnum2 = newnum3, finalnum3 = newnum4;
	if (newnum2 < min2) {
		min2 = newnum2;
		finalnum1 = newnum1;
		finalnum2 = newnum3;
		finalnum3 = newnum4;
	}

	if (newnum3 < min2) {
		min2 = newnum3;
		finalnum1 = newnum1;
		finalnum2 = newnum2;
		finalnum3 = newnum4;
	}

	if (newnum4 < min2) {
		min2 = newnum4;
		finalnum1 = newnum1;
		finalnum2 = newnum2;
		finalnum3 = newnum3;
	}

	/* Step #3: We have now determined and excluded both the least and second least values in our list of 5 numbers ONLY USING
	SELECTION CONTROL STRUCTURES. The "third least" value in our list of 5 numbers will be the median, and we apply the same algorithm
	to our 3 remaining numbers to find the minimum (thus yielding the "third least" value of our original set, which is the median).*/
	double MEDIAN = finalnum1;
	if (finalnum2 < MEDIAN) {
		MEDIAN = finalnum2;
	}
	if (finalnum3 < MEDIAN) {
		MEDIAN = finalnum3;
	}

	/* Step #4: We now output the median with correct formatting! */
	cout << endl << "For the values entered " << UserNum1 << ", " << UserNum2 << ", "
		<< UserNum3 << ", " << UserNum4 << " and " << UserNum5 << endl;

	cout << "the median is " << MEDIAN << "." << endl;
}