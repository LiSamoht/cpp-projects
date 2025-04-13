/*
Thomas Li
Instructor: Sarkar S
CS10B, Spring 2024
Assignment 2b [20 points]—Pattern Displays
(b) Pyramids from Giza  (actually: three Pyramids)

This C++ code implements a program that draws three pyramids of Giza (hollow triangles formed using asterisks) based on user input 
for the pyramid height. The program utilizes a do-while loop to allow the user to attempt drawing pyramids multiple times. Inside the
loop, the user is prompted to enter the pyramid height, and the program validates the input to ensure it is an integer within the range 
of 2 to 8. The pyramids are then drawn using nested loops, with the following implementation: Our outermost for loop handles the drawing
of each row in the pyramid. We then notice that, between pyramids, there is a constant pattern for the space between pyramids, but
there is an irregularity with the leftmost pyramid; so, we print spaces in each row to shift the printing to proper alignment. Then,
we print the left spaces and asterisks (which are calculated using algorithms), and output the three pyramids. After drawing the pyramids,
the user is given the option to try again by typing 'Y' or exit by pressing any other key. The program continues to execute as long as 
the user chooses to try again.
*/
#include <iostream>
using namespace std;

int main() {

	char tryAgain; // Variable to determine if the user wants to draw another set of pyramids. 'Y' means yes, any other key implies no.
	do {
		cout << "*****************************************************" << endl; // Display asterisks for formatting.
		cout << "              Three Pyramids of Giza" << endl;
		cout << "*****************************************************" << endl;

		// FORMATTING, GETTING INPUT, AND INPUT VALIDATION

		int PyrHeight; // Variable to store the user-specified height of the pyramid
		bool validHeight = false;

		// While the user does not enter a valid height, continue prompting:
		while (!validHeight) {
			cout << "Enter Pyramid height (input range 2-8): ";

			// Get input from the user and immediately check if the input is an integer.
			if (!(cin >> PyrHeight)) {
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
				cout << "OOPS, incorrect height input." << std::endl; // Output invalid input to the user
			}
			else if (PyrHeight < 2 || PyrHeight > 8) {
				cout << "OOPS, incorrect height input." << endl; // Output invalid input to the user if PyrHeight is not in the correct range.
			}
			else {
				validHeight = true;  // Valid input, output printing prompt, exit the loop
				cout << "Now drawing the pyramids......." << endl << endl;
			}
		}

		// ALGORITHM FOR PRINTING THE 3 PYRAMIDS

		for (int row = 0; row < PyrHeight; row++) { //Print each individual horizontal Row of 3 pyramids
			//"shift" to the correct place to easily print three pyramids.
			int LeftSpaces = row;
			for (int i = 0; i < LeftSpaces; i++) {
				cout << ' ';
			}

			//print the three pyramids (technically the actual rows of the three pyramids)
			for (int pyrNum = 0; pyrNum < 3; pyrNum++) {

				//print the white space coming before each row in each pyramid
				int OuterPyrSpaces = 15 - 2 * row;
				for (int j = 0; j < OuterPyrSpaces; j++) {
					cout << ' ';
				}
				//print the pyramid in the pyramid row itself, includes the asterisks and the possible spaces
				if (row == 0 || (row == PyrHeight - 1)) {
					for (int asterisks = 0; asterisks < (2 * row + 1); asterisks++) {
						cout << "*";
					}
				}
				else {
					cout << '*';
					int InnerPyrSpaces = 2 * row - 1;
					for (int k = 0; k < InnerPyrSpaces; k++) {
						cout << ' ';
					}
					cout << '*';
				}
			}
			cout << endl;
		}

		cout << "Try again, Type Y for yes or any other key to exit: ";
		cin >> tryAgain;
		cout << endl;

	} while (tryAgain == 'Y'); //while the user types 'Y' for yes, continue iterating to try again

	cout << endl << "Now exiting the Pyramids of Giza program........" << endl; //Ending message
}
/*
 To begin, the entire program itself is encased within a posttest loop (do-while) that automatically asks the user for a pyramid height
 and outputs three pyramids; at the end, it asks whether or not the user wants to try again, and depending on the user's input, the
 posttest while-loop may iterate again.

 Next, for input validation, the program uses a pre-test while loop, utilizing the boolean validHeight and initializing it to false.
 It gets the input using if (!(cin >> PyrHeight)) {...}, instantly checking whether the cin was successful and if the input wasn't 
 valid, cin >> PyrHeight fails and so !(cin >> PyrHeight) returns true: the program then clears the error, discards the invald input
 and outputs the invalid input message. On the other hand, if the cin was successful, an integer was entered, so the program simply
 checks if the input is in the correct range (2-8) and outputs respective messages. In any case, if the input is invald, the boolean
 validHeight is still false and the loop will execute again; else, if the input is valid, validHeight becomes true and the loop exits.
 
 ALGORITHM EXPLANATION:
 Overrall Idea: Print each Row {(1) leftmost white space irregular so print spaces to make regular again, (2) Print the three
 pyramid rows {(3). print the constant white space in each row, (4) print the pyramid row itself using asterisks and spaces}}

Now we will focus on the main algorithm that prints the three pyramids; the rest of the code is simply formatting and input 
validation that can be understood from reading the comments within the code itself. We start with the for-loop (pre-testing the
bound) so that it iterates however many rows there will be in the pyramid (Our outermost loop gives us how the whole pyramid will be
printed, and in this case, the pyramid will be printed through each horizontal row.

(1)Now, we encounter the for loop (inside the outermost loop):  
			int LeftSpaces = row;
			for (int i = 0; i < LeftSpaces; i++) {
				cout << ' ';
			}
Notice that, for each of the three pyramids printed, there is a constant amount of white space between each pyramid, EXCEPT for the
first pyramid, which has a different amount of white space before it. We don't like that because it would be really nice if they all
were the same amount of white space before...so, we notice that if we shift the top row 0 spaces, we get the same number of spaces
between 3 pyramids; if we shift the next-bottom row 1 space, we get the same number of spaces between 3 pyramids... it just so happens
that our row number gives us the exact same amount of spaces that we need to shift each row so that it becomes "regular", which is 
why LeftSpaces = row. Then, the for loop prints out the spaces.

(2) Next, we encounter the for loop: for (int pyrNum = 0; pyrNum < 3; pyrNum++) {...}. This iterates three times to print out
what will become each pyramid; it really prints out each horizontal row of the pyramid. Now that our leftmost pyramid has been shifted 
to the right place, we can start printing (and repeat 3 times to get each of them). We'll now enter this for loop for the rest of the
algorithm, and the first for loop in here is: 
(3)  			int OuterPyrSpaces = 15 - 2 * row;
				for (int j = 0; j < OuterPyrSpaces; j++) {
					cout << ' ';
				}
here, we are printing the white space that comes between each pyramid (or the leftmost space before printing any pyramid). We notice
that it starts at 15 (with row 0 to row 7, or a total of 8 rows), then decreases to 13, then to 11, and we generalize that the 
number of spaces between each pyramid row is 15 - 2 * row. We then use a for loop to print out our spaces.

Next, our white space is all good, and we need to print out our actual pyramids. The following is still within (2):
(4)					if (row == 0 || (row == PyrHeight - 1)) {
					for (int asterisks = 0; asterisks < (2 * row + 1); asterisks++) {
						cout << "*";
					}
				}
				else {
					cout << '*';
					int InnerPyrSpaces = 2 * row - 1;
					for (int k = 0; k < InnerPyrSpaces; k++) {
						cout << ' ';
					}
					cout << '*';
				}
The general idea is as follows: we count asterisks and spaces inside the pyramid...we will use a total of 8 rows in order to gather our 
mental model.
Asterisks (from row 0 to row 7): {1,2,2,2,2,2,2,15}, InnerSpaces (from row 0 to row 7): {0,1,3,5,7,9,12,0}
Ah-ha! if our row is 0 or the last, we will need to print out ONLY ASTERISKS. This is done with the first condition "if", and
a for loop is used to print out the correct number of asterisks for those two rows. Note that 2 * row + 1 yields 1 asterisk on row 0 and
15 on row 7...Perfect!
However, if our row is not this special case, we'll need 2 asterisks and spaces that follow the pattern {1, 3, 5, 7, ...}.
The "else" statement covers this, printing out an asterisk before and after the spaces. The spaces is determined since we have a linear
relationship between row and the number of inner spaces, yielding InnerPyrSpaces = 2 * row - 1... ex: in row 1, we have 2 * 1 - 1 == 1.
in row 2 we have 2 * 2 - 1 == 3, it works. We use a for loop to print out the inner spaces.

Note that (3) and (4) only print out a horizontal row for only ONE of the three pyramids, which is why we iterate 3 times in (2) for
all three pyramids. We also have to include a very important cout << endl; at the end of each iteration printing out each row... I spent
a considerable amount of time wondering why my pyramids weren't printing properly.


HERE IS THE FLOWCHART: : Print each Row { (1) leftmost white space irregular so print spaces to make regular again, (2) Print the three
 pyramid rows  {(3). print the constant white space in each row, (4) print the pyramid row itself using asterisks and spaces} } 
*/