/*
    This program demonstrates the QuickSort Algorithm updated with sample function template sample8d.cpp
     Reference Gaddis Chapter - Section 20.8 Focus on Problem Solving and Program Design: The QuickSort Algorithm
     as well as GaddisChapter16.2 Function Templates
     Note: The function templates may also be stored in a header file (quicksort,h) and accessed with an include directive

     Thomas Li
*/
#include <iostream>
using namespace std;

// Function prototypes
template <class T>
void quickSort(T[], int, int);

template <class T>
int partition(T[], int, int);

template <class T>
void swapping(T&, T&);

//Function prototype for a function template (reference Gaddis Chapter 16.2  - Function Templates)
template <class T>
void printArray(T[], int);

int main()
{
    const int SIZE = 10;  // Array size

    int intarray[SIZE] = { 7, 3, 9, 2, 0, 1, 8, 4, 6, 5 };
    double dbarray[SIZE] = { 7.5, 3.3, 9.1, 2.3, 0, 1.5, 8.3, 4.5, 6.45, 5.56 };
    char charray[SIZE] = { 'P', 'a', 'l', 'i', 'n', 'd', 'r', 'o', 'm', 'e' };
    string strarray[SIZE]{ "summer", "winter", "autumn", "fall", "spring", "hot", "cold", "warm", "humid", "temperate" };

    cout << "*********************************************" << endl;
    cout << "Demonstrating use of function templates" << endl;
    cout << "*********************************************" << endl;

    // Display the array contents - algorithm left here for function template reference
       /*  for (int count = 0; count < SIZE; count++)
                cout << array[count] << " ";
           cout << endl;
       */

       // Display the array contents calling a function template
    cout << "Display unsorted array elements using a printArray function template" << endl;
    printArray(intarray, SIZE);


    // Sort the array. Note: quickSort algorithm will only work for an int array
    quickSort(intarray, 0, SIZE - 1);

    cout << "Displaying sorted array element after calling the non template quickSort algorithm" << endl;
    printArray(intarray, SIZE);

    //Calling the templated printArray function with three different array element data types as arguments
    cout << "\nDisplay unsorted elements of three remaining arrays using a printArray function template" << endl;
    printArray(dbarray, SIZE);
    printArray(charray, SIZE);
    printArray(strarray, SIZE);


    
        //Partial coding interface to test updated quickSort function templates using arrays with different data types
        //Remove multi-line comment to test the quickSort function templates

        cout << "------------------------------------------------------------------------------------------------------- " << endl;
        cout << " Testing the quickSort function template with arrays with different element data types " << endl;

       //Display the array contents calling a printArray function template
       cout << "\nDisplaying unsorted integer array elements" << endl;
       printArray( intarray, SIZE);

       //sort the array calling the updated quickSort function template
       quickSort( intarray, 0, SIZE - 1);

        cout << "Displaying sorted integer array elements after a call to the quickSort function template" << endl;
        printArray( intarray, SIZE);

        // Display the double array contents calling a printArray function template
       cout << "\nDisplaying unsorted double array elements" << endl;
       printArray( dbarray, SIZE);

       //sort the array calling the updated quickSort function template
       quickSort( dbarray, 0, SIZE - 1);

        cout << "Displaying sorted double array elements after a call to a quickSort function template" << endl;
        printArray( dbarray, SIZE);

       // Display the char array contents calling a printArray function template
       cout << "\nDisplaying unsorted char array elements" << endl;
       printArray( charray, SIZE);

       //sort the array calling the updated quickSort function template
       quickSort( charray, 0, SIZE - 1);

        cout << "Displaying sorted char array elements after a call to a quickSort function template" << endl;
        printArray( charray, SIZE);

        // Display the string array contents calling a printArray function template
       cout << "\nDisplaying unsorted string array elements" << endl;
       printArray( strarray, SIZE);

       //sort the array calling the updated quickSort function template
       quickSort( strarray, 0, SIZE - 1);

        cout << "Displaying sorted string array elements after a call to a quickSort function template" << endl;
        printArray( strarray, SIZE);

    return 0;
}

// *******************************************************
// The printArray template function displays the data  *
// elements accessible through the someArray array  *
// parameter and the size parameter,                            *
// ********************************************************
template <class T>
void printArray(T someArray[], int size)
{
    for (int count = 0; count < size; count++)
        cout << someArray[count] << " ";
    cout << endl;
}

//************************************************
// quickSort uses the quicksort algorithm to     *
// sort set, from set[start] through set[end].   *
//************************************************
template <class T>
void quickSort(T set[], int start, int end)
{
    int pivotPoint;

    if (start < end)
    {
        // Get the pivot point.
        pivotPoint = partition(set, start, end);
        // Sort the first sub list.
        quickSort(set, start, pivotPoint - 1);
        // Sort the second sub list.
        quickSort(set, pivotPoint + 1, end);
    }
}

//**********************************************************
// partition selects the value in the middle of the        *
// array set as the pivot. The list is rearranged so       *
// all the values less than the pivot are on its left      *
// and all the values greater than pivot are on its right. *
//**********************************************************
template <class T>
int partition(T set[], int start, int end)
{
    T pivotValue; //an element in the array
    int pivotIndex, mid; //key positions or subscripts

    mid = (start + end) / 2;
    swapping(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (set[scan] < pivotValue)
        {
            pivotIndex++;
            swapping(set[pivotIndex], set[scan]);
        }
    }
    swapping(set[start], set[pivotIndex]);
    return pivotIndex;
}

//**********************************************
// swapping simply exchanges the contents*
// of value1 and value2.                                  *
//**********************************************
template <class T>
void swapping(T& value1, T& value2)
{
    T temp = value1;

    value1 = value2;
    value2 = temp;
}

/* sample build/run output testing the printArray function template

*********************************************
Demonstrating use of function templates
*********************************************
Display unsorted array elements using a printArray function template
7 3 9 2 0 1 8 4 6 5
Displaying sorted array element after calling the non template quickSort algorithm
0 1 2 3 4 5 6 7 8 9

Display unsorted elements of three remaining arrays using a printArray function template
7.5 3.3 9.1 2.3 0 1.5 8.3 4.5 6.45 5.56
P a l i n d r o m e
summer winter autumn fall spring hot cold warm humid temperate

Process returned 0 (0x0)   execution time : 0.954 s
Press any key to continue.

*/

/* SAMPLE OUTPUT: 
Display unsorted elements of three remaining arrays using a printArray function template
7.5 3.3 9.1 2.3 0 1.5 8.3 4.5 6.45 5.56
P a l i n d r o m e
summer winter autumn fall spring hot cold warm humid temperate
-------------------------------------------------------------------------------------------------------
 Testing the quickSort function template with arrays with different element data types

Displaying unsorted integer array elements
0 1 2 3 4 5 6 7 8 9
Displaying sorted integer array elements after a call to the quickSort function template
0 1 2 3 4 5 6 7 8 9

Displaying unsorted double array elements
7.5 3.3 9.1 2.3 0 1.5 8.3 4.5 6.45 5.56
Displaying sorted double array elements after a call to a quickSort function template
0 1.5 2.3 3.3 4.5 5.56 6.45 7.5 8.3 9.1

Displaying unsorted char array elements
P a l i n d r o m e
Displaying sorted char array elements after a call to a quickSort function template
P a d e i l m n o r

Displaying unsorted string array elements
summer winter autumn fall spring hot cold warm humid temperate
Displaying sorted string array elements after a call to a quickSort function template
autumn cold fall hot humid spring summer temperate warm winter
*/
