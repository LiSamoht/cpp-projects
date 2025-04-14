/*
Thomas Li
*/
#include <iostream>
using namespace std;

int numTimes(/*inout*/ int* array,/*in*/ int size,/*in*/ int value); //a sample function prototype
int findLargest(/*in*/ const int array[],/*in*/ int start,/*in*/ int end);  //a sample function prototype

int main()
{
    const int SIZE = 10;  // Array size
    int number = 8;       //value to check frequency
    int array[SIZE] = { 7, 3, 9, 8, 0, 1, 8, 4, 6, 5 };

    cout << "Data structure elements: ";
    // Display the array contents.
    for (int count = 0; count < SIZE; count++)
        cout << array[count] << " ";
    cout << endl;

    cout << "\n----------------------------------------------------\n"; // a spacer

    //  if(numTimes (array,SIZE,number)>0)
    cout << "The number " << number << " occurs " << numTimes(array, SIZE, number) << " times in the data structure " << endl;
    cout << findLargest(array, 0, SIZE - 1) << " is the largest number in the data structure " << endl;

    return 0;
}

/*
The numTimes function is a recursive algorithm that counts the occurrences of a specified value in an array. The base case checks if the size is zero, 
returning 0, as there are no elements left to check. In the recursive case, if the last element of the current subarray equals the specified value, the
function returns 1 plus the result of the recursive call with the array size decreased by one. If the last element does not match the specified value,
the function simply returns the result of the recursive call with the array size decreased by one. This process continues until the base case is reached, 
ensuring that each element is checked, and the total count of the specified value is accumulated.
*/
int numTimes(/*inout*/ int* array,/*in*/ int size,/*in*/ int value) {
    if (size == 0)         //base case
        return 0;
    else if (array[size - 1] == value) {
           return 1 + numTimes(array, size - 1, value);
    }
    else if (array[size - 1] != value) {
        return numTimes(array, size - 1, value);
    }
    // TBD: numTimes recursive algorithm to return the number of times element in parameter value appears in the array
}


/*
The findLargest function is a recursive algorithm that finds the largest value in an array. The base case checks if the start index is equal to the end index, 
returning the single element in the subarray as the largest. In the recursive case, the function divides the array into two halves by calculating the middle index. 
It then recursively finds the largest value in each half. After obtaining the largest values from the left and right halves, it compares them and returns the larger
of the two. This process continues until the base case is reached, ensuring that the largest value in the entire array is found by comparing the largest
values from progressively smaller subarrays.
*/
int findLargest(/*in*/ const int array[],/*in*/ int start,/*in*/ int end) {

    if (start == end)            //base case
        return array[start];

    else {
        int mid = (start + end) / 2;
        int leftMax = findLargest(array, start, mid);
        int rightMax = findLargest(array, mid + 1, end);
        
        //comparisons
        if (leftMax > rightMax) {
            return leftMax;
        }
        if (rightMax > leftMax) {
            return rightMax;
        }
    }
    //TBD: findLargest recursive algorithm to return the largest element value in the array
}

/* A sample Test results program output

  Data structure elements: 7 3 9 8 0 1 8 4 6 5

----------------------------------------------------
The number 8 occurs 2 times in the data structure
9 is the largest number in the data structure

*/
