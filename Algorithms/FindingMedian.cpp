#include <iostream>

using namespace std;

int main() {
	double val1, val2, val3, val4, val5;
	double num1, num2, num3, num4, num5;
	//prompt user to enter in 5 numbers using c++ cout and cin.
	cout << "Enter five real numbers below" << endl;
	cout << "Enter value for number 1; press return." << endl;
	cin >> num1;
	val1 = num1;

	cout << "Enter value for number 2; press return." << endl;
	cin >> num2;
	val2 = num2;

	cout << "Enter value for number 3; press return." << endl;
	cin >> num3;
	val3 = num3;

	cout << "Enter value for number 4; press return." << endl;
	cin >> num4;
	val4 = num4;

	cout << "Enter value for number 5; press return." << endl;
	cin >> num5;
	val5 = num5;

	/*the following checks each consecutive couple through the list of val1 to val5. It ensures that each couple of values is sorted by least
	* to greatest by checking whether */
	bool donesorting = true;
	int count = 0;
	do {
		if (val1 > val2) {
			double store = val1;
			val1 = val2;
			val2 = store;

			count++;
			//an algorithm to swap val1 and val2, assuming that val1 is larger than val2.
		}
		if (val2 > val3) {
			double store = val2;
			val2 = val3;
			val3 = store;
			count++;
		}
		if (val3 > val4) {
			double store = val3;
			val3 = val4;
			val4 = store;
			count++;
		}
		if (val4 > val5) {
			double store = val4;
			val4 = val5;
			val5 = store;
			count++;
		}

		if (count != 0) {
			donesorting = false;
			count = 0;
		}
		else {
			donesorting = true;
		}
	} while (!donesorting);
	/* now we must sort the list of five numbers (this is super easy using functions built in STL libraries or arrays
	but as a challenge, we won't use them)*/

	cout << "For the values entered " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << " and " << num5 << endl;
	cout << "the median is " << val3 << "." << endl;
	//cout << "Process returned 0 (0x0) execution time: " <<




}