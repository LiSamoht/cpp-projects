#pragma once
#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H


/*
Class: boolMatrix
Description: Represents a boolean matrix and provides functionalities for managing and manipulating it.
Author: Thomas Li

Public Member Functions:
    boolMatrix()
    pre: None
    post: Initializes an empty boolean matrix with all elements set to false.

    bool get(int row, int col) const
    pre: 0 <= row < NUM_ROWS && 0 <= col < NUM_COLS
    post: Returns the value (true or false) at the specified row and column.

    void set(int row, int col, bool val)
    pre: 0 <= row < NUM_ROWS && 0 <= col < NUM_COLS
    post: Sets the value at the specified row and column to the given value.

    int rowCount(int row) const
    pre: 0 <= row < NUM_ROWS
    post: Returns the total count of living cells in the specified row.

    int colCount(int col) const
    pre: 0 <= col < NUM_COLS
    post: Returns the total count of living cells in the specified column.

    int totalCount() const
    pre: None
    post: Returns the total count of living cells in the entire matrix.

    int neighborCount(int row, int col) const
    pre: 0 <= row < NUM_ROWS && 0 <= col < NUM_COLS
    post: Returns the number of living neighbors for the cell at the specified row and column.

    void print() const
    pre: None
    post: Prints the boolean matrix to the console.

Private Data Members:
    bool matrix[NUM_ROWS][NUM_COLS]: Represents the boolean matrix.
*/


class boolMatrix {
public:
	static const int NUM_ROWS = 21;
	static const int NUM_COLS = 22;
	boolMatrix();

	bool get(/*in*/int row,/*in*/ int col) const;
	void  set(/*in*/int row,/*in*/ int col,/*in*/ bool val);
	int rowCount(/*in*/int row) const;
	int colCount(/*in*/int col) const;
	int totalCount() const;
	int neighborCount(/*in*/int row,/*in*/ int col) const;
	void print() const;
private:
  bool matrix[NUM_ROWS][NUM_COLS];
};

#endif