/*
Thomas Li
Instructor: Sarkar S
CS10B, Spring 2024
Assignment 2a [20 points]—A guessing game

This program implements a simple number-guessing game. The user is asked to think of a number between 1 and 100. 
The program then iteratively guesses the number using a binary search algorithm, adapting its guesses based on user 
feedback ('h' for higher, 'l' for lower, 'c' for correct). The program tracks the number of guesses needed to arrive 
at the correct answer and displays the result after each round. The user has the option to play the game multiple times,
with the program adjusting its guessing strategy for each new round. The overall goal is to efficiently determine the user's 
chosen number within the specified range.
*/
#include <iostream>

using namespace std;

int main() {
	char userwantstoplay; //Store character value determining if user wants to play: 'y' means yes
	do {
		cout << "Think of a number between 1 and 100." << endl;
		char userinput; //store user's input of higher 'h', lower 'l', or correct 'c'
		int guess = 50; //initialize the computer's guess to be 50
		int countguesses = 0; //counter for the number of computer guesses
		int lowerbound = 1; //lower bound of guessing
		int higherbound = 100; //higher bound of guessing
		do {
			//get input from user, no input validation required
			cout << "My guess is " << guess << ". Enter \'l\' if your number is lower, \'h\' if it is higher, \'c\' if it is correct: ";
			cin >> userinput;
			//for every iteration, 1 guess will be made, so our counter will go up.
			countguesses++;

			if (userinput == 'h') {/*if the user says answer higher than guess, lower bound becomes the guess + 1 and our new guess is 
									the midpoint between the lower and higher bounds*/
				lowerbound = guess + 1;
				guess = (lowerbound + higherbound) / 2;
			}
			else if (userinput == 'l') { /*if the user says answer lower than guess, higher bound becomes guess - 1 and new guess is 
											midpoint between lower and higher bounds*/
				higherbound = guess - 1;
				guess = (lowerbound + higherbound) / 2;
			}
		} while (userinput != 'c'); //while the user hasn't said that we got the right answer

		cout << endl << "Great! Based on user inputs, the computer algorithm took " << countguesses << " tries to determine your number.";
		cout << endl << "Do you want to play again (y/n)? ";
		cin >> userwantstoplay;
		cout << endl << endl;
	} while (userwantstoplay == 'y'); //continue playing the game until the user doesn't want to anymore
}