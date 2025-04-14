/*
Class Invariant:
- The boolean matrix is a 2D array of size NUM_ROWS x NUM_COLS.
- Each element of the matrix represents a single cell, where true indicates a live cell and false indicates a dead cell.
- NUM_ROWS and NUM_COLUMNS are non-negative.
Private Data Members:
- bool matrix[NUM_ROWS][NUM_COLS]: Represents the boolean matrix.
*/
#include "boolMatrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;


/* 
serves as the constructor for the boolMatrix class, initializing all elements of the boolean matrix to false.
Its purpose is to create a new boolean matrix instance with all cells initially set to false, enabling subsequent 
modifications and analyses
*/
boolMatrix::boolMatrix() {
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			matrix[i][j] = false;
		}
	}
}
 

//Gets the value at the specified row and column, with the assertion that the row and columns are in valid range.
bool boolMatrix::get(/*in*/int row,/*in*/ int col) const {
	assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
	return matrix[row][col];
}


// Set the value at the specified row and column, with the assertion that the row and columns are in the valid range.
void boolMatrix::set(/*in*/int row,/*in*/ int col,/*in*/ bool val) {
	assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
	matrix[row][col] = val;
}


// Get the total count of true's in the specified row, with the assertion that the number of rows are in the valid range
int boolMatrix::rowCount(/*in*/int row) const {
	assert(row >= 0 && row < NUM_ROWS);
	int count = 0;
	for (int j = 0; j < NUM_COLS; ++j) {
		if (matrix[row][j]) {
			count++;
		}
	}
	return count;
}


// Get the total count of true's in the specified column, with the assertion that the number of columns are in the valid range
int boolMatrix::colCount(/*in*/int col) const {
	assert(col >= 0 && col < NUM_COLS);
	int count = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		if (matrix[i][col]) {
			count++;
		}
	}
	return count;
}


// Get the total count of true's in the entire matrix
int boolMatrix::totalCount() const {
	int count = 0;
	for (int i = 0; i < NUM_ROWS; ++i) {
		for (int j = 0; j < NUM_COLS; ++j) {
			if (matrix[i][j]) {
				++count;
			}
		}
	}
	return count;
}


/*
Get the number of neighboring true's for the cell at the specified row and column. Aids in determining the neighborhood of living cells surrounding a particular cell,
facilitating analyses such as Conway's Game of Life.
*/
int boolMatrix::neighborCount(/*in*/int row,/*in*/ int col) const {
	assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
	int count = 0;

	//Get the row and column bounds for where existing neighbors are based on original row, col.
	int rowLower = max(0, row - 1);
	int rowUpper = min(NUM_ROWS - 1, row + 1);
	int colLower = max(0, col - 1);
	int colUpper = min(NUM_COLS - 1, col + 1);

	//Iverson sum(Counting sum) over the bounds. Can be expressed in mathematical notation as 
	//Sigma(Iversonbracket[f(i,j)] * Iversonbracket[rowLower<=i<=rowUpper] * Iversonbracket[colLower <= j <=colUpper]) 
	//where f(i,j) represents our matrix value at the (row, index).
		for (int i = rowLower; i <= rowUpper; i++) {
			for (int j = colLower; j <= colUpper; j++) {
				if (get(i, j)) {
					count++;
				}
			}
		}
		count = count - get(row,col); // Account for the current cell itself

	return count;
}


// Print the boolean matrix to the console by first printing column labels and the rest of the matrix after.
void boolMatrix::print() const {
	//print column labels
	cout << "  ";
	for (int i = 0; i < NUM_COLS; i++) {
		cout << i % 10;
	}
	cout << endl;

	//print contents
	for (int row = 0; row < NUM_ROWS; row++) {
		cout << setw(2) << row; //for formatting
		for (int col = 0; col < NUM_COLS; col++) {
			if (matrix[row][col]) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}