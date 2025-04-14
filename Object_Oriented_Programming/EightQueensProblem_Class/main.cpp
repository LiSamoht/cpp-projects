#include <iostream>
#include <vector>
using namespace std;


class Queen {
public:
    void setRow(int inRow);
    int getRow() const;
private:
    int row {-1}; //This has to be done in order for uninitizalied queens rows to not equal 0 when we are checking for attacks...
};




int Queen::getRow() const {
    return row;
}




void Queen::setRow(int inRow) {
    row = inRow;
}






class Board {
public:
    static const int BOARD_SIZE = 8;
    Board();
    void doQueens();
    void display() const;
private:
    bool placeQueens(int row, int col);
    bool findNextSafeSquare(int& row, int col);
    bool isUnderAttack(int row, int col);
    vector<Queen> queens;
};




Board::Board() {
    queens.resize(BOARD_SIZE);
}




void Board::doQueens() {
    if (placeQueens(0, 0)) {
        display();
    }
    else {
        cout << "No solution found." << endl;
    }
}






bool Board::placeQueens(int row, int col) {
    // use the pseudocode above to complete this function.

    bool safeRowExists = findNextSafeSquare(row, col);

    while (safeRowExists) {
        queens[col].setRow(row);

        //Check if last queen is placed...can't use queens.size() because its always 8 (initialized by Board::Board())
        bool isfull = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (queens[i].getRow() == -1) {
                isfull = false;
                break;
            }
        }

        if ( isfull || placeQueens(0, col + 1)) {
            return true;
        }
        else { 
            queens[col].setRow(-1);
            row++;
        }
        safeRowExists = findNextSafeSquare(row, col); //try to find another safe row in the column if the subsequent column was also unable to find a safe row. If fails, function will return false and go to the preceding call to try to find another safe row, etc.
    }

    return false;
}




bool Board::isUnderAttack(int testRow, int testCol) {
    
    for (int i = 0; i < queens.size(); i++) {
        int placedRow = queens[i].getRow();
       
        if (placedRow == -1) {
            break; //end the loop here, because the rest of the queens are empty.
        }

        if (i == testCol) {
            return true;
        }
        if (placedRow == testRow) {
            return true;
        }
        if (abs(i - testCol) == abs(placedRow - testRow)) {
            return true;
        }
    }
    return false;
}




// Sets "row" to the row of the next safe square in column col.  Important note:
// The first square to be considered will be the given row and column. 
// In other words, the given row and col may be the "next safe square". 
// returns true if a safe square is found, false if no safe square is found.  If 
// return value is false, row is undefined.

bool Board::findNextSafeSquare(int& row, int col) {
    for (int i = row; i < BOARD_SIZE; i++) {
        if (!isUnderAttack(i, col)) {
            row = i;
            return true;
        }
    }
    return false;
}




// Displays a visual representation of the current state of the board.  For each position
// on the board, displays "X" if a queen is located at that position, otherwise displays
// "_" (underscore).

void Board::display() const {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (queens[col].getRow() == row) {
                cout <<"X ";
            }
            else {
                cout <<"_ ";
            }
        }
        cout << endl;
    }
}







int main() {
    Board board;
    board.doQueens();
}