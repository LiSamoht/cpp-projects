/*
The client file begins by including necessary libraries and the "boolMatrix.h" header file, which defines the boolMatrix class
and its member functions.It then declares several utility functions such as readGrid, getGenerations, determineNextGeneration, 
determineFateOfSingleCell, and printResults.In the main function, it instantiates a boolMatrix object named life and prompts the 
user to input the number of generations.It then iterates over each generation, determining the next generation's state based on the 
rules defined in determineFateOfSingleCell and updating the life matrix accordingly. After processing all generations, it prints the 
final results, including the matrix state and various statistical data such as the total count of alive cells, dead cells, and
specific counts for rows and columns. Overall, the client file demonstrates the lifecycle of the boolMatrix object, reads data 
from a file, performs generation updates, and displays the results to the user.
*/
#include <iostream>
#include <fstream>
#include "boolmatrix.h"

using namespace std;

void readGrid(/*out*/ boolMatrix& life);
void getGenerations(/*out*/ int& numGenerations);
void determineNextGeneration(/*inout*/ boolMatrix& life);
void determineFateOfSingleCell(/*in*/ const boolMatrix& life, /*out*/ boolMatrix& life2, /*int*/ int row, /*in*/ int col);
void printResults(/*in*/ const boolMatrix& life, /*in*/ int numGenerations);

int main() {
	boolMatrix life;
	int numGenerations;

	readGrid(life);
	getGenerations(numGenerations);
	for (int count = 0; count < numGenerations; count++) {
		determineNextGeneration(life);
	}

	printResults(life, numGenerations);
    return 0;
}

//Reads cell coordinates from a file named "lifedata.txt" and sets the corresponding cells in the provided boolMatrix object to true.
void readGrid(/*out*/boolMatrix& life) {
    //pre: The file "lifedata.txt" exists in the current directory and contains valid integer pairs representing row and column coordinates.
    //post: The boolMatrix object 'life' has its cells set to true at positions specified by the coordinates read from the file.
    ifstream inFile("lifedata.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file lifedata.txt" << endl;
        exit(1);
    }

    int row, col;
    while (inFile >> row >> col) {
        life.set(row, col, true);
    }

    inFile.close();
}

//Gets the user's desired number of generations for the game.
void getGenerations(/*out*/int& numGenerations) {
    //Preconditions: None.
    //Postconditions: 'numGenerations' holds the number of generations input by the user.
    cout << "Enter number of generations: ";
    cin >> numGenerations;
}

// Determines the state of the next generation of cells based on the rules of the game of life and updates the provided boolMatrix object accordingly.
void determineNextGeneration(/*in/out*/ boolMatrix& life) {
    //pre: 'life' holds the current generation's cell states.
    //post: 'life' is updated to reflect the next generation's cell states according to the rules of the game of life.
    boolMatrix nextGeneration = life;
    for (int i = 0; i < boolMatrix::NUM_ROWS; i++) {
        for (int j = 0; j < boolMatrix::NUM_COLS; j++) {
            determineFateOfSingleCell(life, nextGeneration, i, j);
        }
    }
    life = nextGeneration;
}

// Determines the fate of a single cell in the next generation based on its current state and the number of alive neighbors.
void determineFateOfSingleCell(/*in*/ const boolMatrix& life, /*out*/ boolMatrix& life2, /*int*/ int row, /*in*/ int col) {
    //pre: 'life' holds the current generation's cell states. 'life2' is an empty boolMatrix object. 'row' and 'col' specify the coordinates of the cell.
    //post: 'life2' is updated to reflect the next generation's cell state for the specified cell based on the rules of the game of life.
    bool alive = life.get(row, col);
    int aliveNeighbors = life.neighborCount(row, col);
        // Cell is currently alive
        if (alive) {
            if (aliveNeighbors == 1 || aliveNeighbors == 0) {
                // Dies of loneliness
                life2.set(row, col, false);
            }
            else if (aliveNeighbors >= 4) {
                // Dies of overcrowding
                life2.set(row, col, false);
            }
            else {
                // Survives
                life2.set(row, col, true);
            }
        }
        //cell is currently dead
        else {
            if (aliveNeighbors == 3) {
                // Comes to life
                life2.set(row, col, true);
            }
            else {
                // Remains dead
                life2.set(row, col, false);
            }
        }
}

// Prints the final state of the boolMatrix object 'life' and various statistical data to the console.
void printResults(/*in*/ const boolMatrix& life, /*in*/ int numGenerations) {
    //pre: 'life' holds the final state of the cell matrix after processing all generations. 'numGenerations' holds the total number of generations processed.
    // Results and matrix are printed to console.
    cout << endl;
    life.print();

    cout << endl << "========================================" << endl;
    cout << "Partial grid statistical data displayed" << endl;
    cout << "Grid size: " << boolMatrix::NUM_ROWS << " x " << boolMatrix::NUM_COLS << endl;
    cout << "Generation: " << numGenerations << endl;
    cout << "==============================" << endl;
    cout << "Total alive in row 10 = " << life.rowCount(10) << endl;
    cout << "Total alive in col 10 = " << life.colCount(10) << endl;
    cout << "Total dead in row 16 = " << (boolMatrix::NUM_COLS - life.rowCount(16)) << endl;
    cout << "Total dead in col 1 = " << (boolMatrix::NUM_ROWS - life.colCount(1)) << endl;
    cout << "Total alive = " << life.totalCount() << endl;
    cout << "Total dead = " << (boolMatrix::NUM_ROWS * boolMatrix::NUM_COLS - life.totalCount()) << endl;
    cout << "==============================" << endl;
}

/*
ALGORITHM WRITE-UP: 

int boolMatrix::neighborCount(int row,int col) const {
    assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
    int count = 0;

    //Get the row and column bounds for where existing neighbors are based on original row, col.
    int rowLower = max(0, row - 1);
    int rowUpper = min(NUM_ROWS - 1, row + 1);
    int colLower = max(0, col - 1);
    int colUpper = min(NUM_COLS - 1, col + 1);

    for (int i = rowLower; i <= rowUpper; i++) {
        for (int j = colLower; j <= colUpper; j++) {
            if (get(i, j)) {
                count++;
            }
        }
    }
    count = count - get(row, col); // Account for the current cell itself

    return count;
}
1. The function starts by checking if the provided row and column indices are within the valid range of the boolean matrix. This is done using an assertion 
to ensure that the indices are non-negative and do not exceed the matrix dimensions. Now, the most important part about this function is the way it finds bounds over
where it should check. Let's analyze: 
    int rowLower = max(0, row - 1);
    int rowUpper = min(NUM_ROWS - 1, row + 1);
    int colLower = max(0, col - 1);
    int colUpper = min(NUM_COLS - 1, col + 1);
If (row, col) is in the "middle" of the array, or simply not on the "boundary" of the array, then the neighbors we will have to check will be: row-1 <=row <= row+1 and 
col-1<=col <= col+1. But, if (row,col) is on the boundary of the array, we must ensure that its bounds are adjusted accordingly. For instance, if row := 0, then we can't check
anything smaller than row 0... so we have to set 0 as the least value for our lower bound for the row... this can be written as rowLower = max(0, row-1). If row is not 0,
then this will always take on the value row-1. Doing similar analysis on colLower yields the same logic. Now what about the upper bounds? Well, again, if (row,column) is 
in the middle of the array, we will simply have to check row-1 <=row <= row+1 and col-1<=col <= col+1 neighbors. But, what if row == NUM_ROWS - 1... or the last row in the
matrix? Then, we can't check row+1 in this case... so we need to set a bound, or a cap at NUM_ROWS - 1. Notice min(NUM_ROWS - 1, row+1) successfully calculates this
upper bound... if row == NUM_ROWS - 1, min(NUM_ROWS - 1, NUM_ROWS) successfully caps our upper bound at NUM_ROWS - 1. Again, this logic applies to columns too.

Great! We now have successfully calculated correct lower and upper bounds for our rows and columns that we must check (this overrall bound on rows and columns represents our
neighbors). We now use a double loop to iterate through these bounds and check each cell, adding 1 to our count if the matrix value at i,j is true. In discrete mathematics or
concrete mathematics, we refer to this as a counting sum that can be expressed mathematically using Iverson's brackets. Sigma(Iversonbracket[f(i,j)] * 
Iversonbracket[rowLower<=i<=rowUpper] * Iversonbracket[colLower <= j <=colUpper]) where f(i,j) represents our matrix value at the (row, index).

Finally, at the end, we have count = count - get(row, col) to account for current cell itself not being a neighbor. That is, the algorithm subtracts one from the count if the 
original cell itself is alive. This adjustment is necessary to avoid counting the original cell as its own neighbor.

2. void determineNextGeneration (boolMatrix& life);
Here are the rules: 
1.If the cell is currently empty:
 -If the cell has exactly three living neighbors, it will come to life in the next generation.
 -If the cell has any other number of living neighbors, it will remain empty.
2. If the cell is currently living:
 -If the cell has one or zero living neighbors, it will die of loneliness in the next generation.
 -If the cell has four or more living neighbors, it will die of overcrowding in the next generation.
 -If the cell has two or three neighbors, it will remain living.
3. All births and deaths occur simultaneously. This point is critical to the correct result.

The function determineNextGeneration is responsible for updating the state of the boolean matrix life to reflect the next generation's cell states based on Conway's
Game of Life rules. It begins by creating a copy of the current generation's matrix called nextGeneration. Then, using nested loops, it iterates over each cell in 
the life matrix. For each cell, it calls the determineFateOfSingleCell function to determine its fate in the next generation. After iterating over all cells, the
life matrix is updated to match the cell states in the nextGeneration matrix. The determineFateOfSingleCell function is designed to determine the fate of a 
single cell in the next generation based on Conway's Game of Life rules. It takes as input the current generation's matrix life, an empty matrix life2 to
hold the next generation's cell states, and the coordinates (row, col) of the cell to be evaluated. First, it retrieves the current state of the cell and 
the number of alive neighbors using the get and neighborCount functions, respectively. Then, based on whether the cell is currently alive or dead, and the
number of alive neighbors, it applies the rules of the game. If the cell is alive, it may survive to the next generation, die of loneliness, or die of overcrowding.
If the cell is dead, it may come to life if it has exactly three alive neighbors. Finally, the function updates the state of the cell in the life2 matrix accordingly.
*/