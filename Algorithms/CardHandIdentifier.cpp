/*
 Thomas Li

This C++ program simulates a simple card game. It prompts the user to enter a hand of numeric cards between 2 and 9, and then determines the type of hand
(e.g., four of a kind, full house, straight, etc.) based on the card values entered. The program uses various helper functions to perform tasks such as 
input validation, calculating card frequencies, and checking for specific hand types.

The CardFrequencies function calculates the frequencies of each card value in the hand. Then, there are several functions
(containsFourOfaKind, containsFullHouse, containsStraight, containsThreeOfaKind, containsTwoPair, containsPair) that check 
for specific hand types by analyzing the frequencies of the card values. These functions return true if the hand matches the specified hand type.

The displayCards function displays the entered cards visually on the screen in rows of five cards or fewer. It uses the symbols function to generate the 
symbols representing each card. The program also includes a inputvalidation function to ensure that the user inputs valid card values. Finally, the main 
function drives the game by repeatedly prompting the user to enter a hand, displaying the hand, determining the hand type, and allowing the user to play 
again if desired.
*/
#include <iostream>
using namespace std;

void CardFrequencies(/*out*/int frequencies[],/*in*/ const int hand[]); //a helper function
void inputvalidation(/*in/out*/int& input, /*in*/ int cardNum); //ensures user inputs valid each time
bool validHand(const int hand[]); //validates the user's entire hand according to a standard deck of 52 cards excluding face cards, aces.

//"card hand type" function prototypes with signatures and data flow comments
bool containsFourOfaKind(/*in*/const int hand[]);
bool containsFullHouse(/*in*/const int hand[]);
bool containsThreeOfaKind(/*in*/const int hand[]);
bool containsTwoPair(/*in*/const int hand[]);
bool containsPair(/*in*/const int hand[]);
bool containsStraight(/*in*/const int hand[]);

//functions to simulate visual card hand type display
void displayCards(/*in*/ const int[]);
string symbols(/*in*/ int, /*in*/ int);

//global constants
const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;
const int CARD_RANGE = HIGHEST_NUM - LOWEST_NUM + 1; //used in cardFrequencies

int main() {

    int hand[HAND_SIZE]; //declare a fixed size array

    char playAgain;

    //A simple Card Game interface
    cout << "\x03 ************************************************ \x03\n";
    cout << "\x04                A simple Card Game                \x04\n";
    cout << "\x05                                                  \x05\n";
    cout << "\x06 ************************************************ \x06\n";

    do {

        // prompt for card deck
        cout << "Enter " << HAND_SIZE << " numeric cards, no face cards.  ";
        cout << "Use " << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;

        // store current card hand
        for (int cardCount = 0; cardCount < HAND_SIZE; cardCount++) {
            int input;
            cout << "Card " << cardCount + 1 << ": ";
            inputvalidation(input, cardCount+1);
            hand[cardCount] = input;
        }

        // display card hand on screen in rows of five cards
        displayCards(hand); //call custom card display function
        cout << endl;

        // you code here with respective conditions and function calls
        if (!validHand(hand)) {
            cout << "Not a valid hand according to a standard deck of 52 cards excluding face cards, aces, etc. There are 4 suits only.";
        }
        else if (containsFourOfaKind(hand)) {
            cout << "Four of a kind!";
        }
        else if (containsFullHouse(hand)) {
            cout << "Full house!";
        }
        else if (containsStraight(hand)) {
            cout << "Straight!";
        }
        else if (containsThreeOfaKind(hand)) {
            cout << "Three of a kind!";
        }
        else if (containsTwoPair(hand)) {
            cout << "Two pair!";
        }
        else if (containsPair(hand)) {
            cout << "One pair!";
        }
        else {
            cout << "High card.";
        }

        cout << "\nType Y to play again: ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << endl;
    cout << "Card game has now concluded. Exiting program ....." << endl;

    return 0;
}



/*
    Ensures valid user input for a card value between 2 and 9. Simultaneously reads in and checks if the cin was valid, as well as checking if the 
    input is between 2 and 9. If the input is not valid or the cin failed, then an invalid input message is output, the error flag is cleared and characters
    are discarded in the input stream until the newline character is found, allowing for new inputs from the user.

    pre: none
    post: input holds a valid card integer value from 2 to 9, or error message is output
*/
void inputvalidation(/*in/out*/int& input, /*in*/ int cardNum) {
    while (!(cin >> input) || input < 2 || input > 9) {
        cout << "Invalid input. Please enter a valid number between 2 and 9." << endl;
        cin.clear(); //clears error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores/discards characters in input until newline character is found.
        cout << "Card " << cardNum << ": ";
    }
}



/*
    This function ensures that the user's hand adheres to a standard deck of 52 cards with 13 ranks in each of the four suits. It initializes a frequencies
    array and counts the frequencies of cards in the user's hand. It then ensures that every card in the user's hand has a frequency no more than 4, since
    each card can only appear a maximum of 4 times (for the 4 suits in a standard deck of 52 cards).

    pre: hand[] consists of 5 numerical values between 2 and 9
    post: the hand is validated according to a standard deck of 52 cards with 13 ranks in each of the four suits.
*/
bool validHand(const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    for (int i = 0; i < CARD_RANGE; i++) {
        if (frequencies[i] > 4) { //if any card shows up more than 4 times, it can't be a standard deck of 52 cards excluding faces and aces.
            return false;
        }
    }

    return true;
}



/*
    Updates an array of frequencies based on the cards in the hand array. Frequencies is as large as CARD_RANGE so that it matches the total possible
    values that can appear in hand[], and Index 0 = frequency of card 2, Index 1 = frequency of card 3, ..., Index 7 = frequency of card 9. A loop
    is used to iterate through the hand array and record the frequencies in the frequencies array.
*/
void CardFrequencies(/*out*/int frequencies[],/*in*/ const int hand[]) {
    //frequencies has indexes 0 to 7. Index 0 = frequency of card 2, Index 1 = frequency of card 3, ..., Index 7 = frequency of card 9
    for (int i = 0; i < HAND_SIZE; i++) {
        frequencies[hand[i] - 2]++;
    }
}



/*
   This determines whether the hand is a four of a kind. It initializes a frequencies array with every element = 0, and gets the frequencies of 
   each card in the hand using the CardFrequencies function. It iterates through the frequencies array, and if any element in the frequencies array
   has the value 4, then it must have appeared 4 times in the hand array. Thus, it returns true if it ever comes across an element == 4 in the frequencies
   array. If it has never found a value of 4, it will default to returning false.

   pre: none
   post: returns true if hand[] contains a four of a kind.
*/

bool containsFourOfaKind(/*in*/const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    for (int i = 0; i < CARD_RANGE; i++) {
        if (frequencies[i] == 4) {
            return true;
        }
    }

    return false;
}




/*
   Determines if the hand is a full house. If the hand contains a pair and three of a kind, it is a full house. The logic is as follows: containsPair will
   only return true if the hand contains EXACTLY (no more, no less) two cards that are the same; containsThreeOfaKind will return true if the hand contains
   EXACTLY (no more, no less) three cards that are the same. This way, they can only both return true the pair and three of a kind are different ranks of card,
   ensuring an accurate output.

   pre: none
   post: returns true if hand[] contains a four of a kind.
*/

bool containsFullHouse(/*in*/const int hand[]) {
    if (containsPair(hand) && containsThreeOfaKind(hand)) {
        return true;
    }

    return false;
}




/*
   Determines whether the hand contains a straight. It initializes a frequencies array with every element set to 0, and obtains the frequencies of 
   each card in the hand using the CardFrequencies function. The function then analyzes the frequencies array to determine if the hand contains a straight.
   
   The logic works as follows: a straight can only occur if we have 5 consecutive cards. This means that, in the frequencies array, a "straight" would
   appear as a sequence of 1's in a chain of 5 consecutive elements (each consecutive card shows up once). This idea is then implemented as follows: a for
   loop iterates through the entire frequencies array. Once an element in the frequencies array is found to be 1, foundFirstCard is set to true, and we keep
   iterating and counting the length of the chain of consecutive elements until the function no longer finds a 1. If the chain of consecutive elements
   ever reaches a count of 5, then it must be a straight. Otherwise, if an element/card was found with a frequency of 1, but the count of consecutive cards
   wasn't 5, then the chain is too short, and no other chain in the frequency array can ever be sufficiently large, so it can't be a straight.

   pre: none
   post: returns true if hand[] contains a four of a kind.
*/

bool containsStraight(/*in*/const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    int CountAdjCards = 0;
    bool foundFirstCard = false;
    for (int i = 0; i < CARD_RANGE; i++) {
        //look for a card with only 1 occurence, keep incrementing counter as keep finding adjacent singular-occurence cards.
        while (i < CARD_RANGE && frequencies[i] == 1) {
            foundFirstCard = true;
            CountAdjCards++;
            i++;
        }
        //if a chain of 5 cards was found adjacent to each other, return true
        if (foundFirstCard && CountAdjCards == 5) {
            return true;
        }
        //if a first occurence of a card was found but a chain of 5 cards wasn't found, it can't be a straight.
        else if (foundFirstCard) {
            return false;
        }
    }

    return false;
}




/* 
   Determines if the hand contains a three of a kind. It initializes a frequencies array with every element set to 0, and obtains the frequencies of 
   each card in the hand using the CardFrequencies function. The function then analyzes the frequencies array to determine if the hand contains three of a 
   kind by iterating through the frequencies array and checking if any card ever has a frequency of three (if so, true is returned; otherwise, false is 
   returned at the end).

   pre: none
   post: returns true if hand[] contains a four of a kind.
*/

bool containsThreeOfaKind(/*in*/const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    for (int i = 0; i < CARD_RANGE; i++) {
        if (frequencies[i] == 3) {
            return true;
        }
    }

    return false;
}




/*
   Determines if the hand contains a two pair. It initializes a frequencies array with every element set to 0, and obtains the frequencies of 
   each card in the hand using the CardFrequencies function. The function then analyzes the frequencies array to determine if the hand contains a 
   two pair by iterating through the frequencies array and counting how many different cards have frequency two. It then returns the boolean value 
   numPairs == 2, which will return true if the function has only found two elements in the frequencies function that were equal to 2, and false otherwise.

   pre: none
   post: returns true if hand[] contains a four of a kind.
*/

bool containsTwoPair(/*in*/const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    int numPairs = 0;
    for (int i = 0; i < CARD_RANGE; i++) {
        if (frequencies[i] == 2) {
            numPairs++;
        }
    }

    return numPairs == 2;
}




/*
   This function takes an array, hand, and passes it to numPairs() to
   find out if the array contains one pair. It initializes a frequencies array with every element set to 0, and obtains the frequencies of each card in the
   hand using the CardFrequencies function. Then, the function iterates through the frequencies array, and if it ever finds a card with a frequency of 2,
   it returns true.

   pre: none
   post: returns true if there is a pair in the hand array
*/

bool containsPair(/*in*/const int hand[]) {
    int frequencies[CARD_RANGE] = { 0 }; //creates a frequency array with size CARD_RANGE = 8 for cards 2 through 9. Index 0 == Card2, Index 1 == Card3, etc.
    CardFrequencies(frequencies, hand);

    for (int i = 0; i < CARD_RANGE; i++) {
        if (frequencies[i] == 2) {
            return true;
        }
    }

    return false;
}



/*
    Given an integer array representing a hand of cards 2-9, displays the cards
    on screen in rows of five or fewer cards

    pre:    Hand size is HAND_SIZE
            Hand contains only integers between 2 and 9
    post:   The hand of card is displayed on screen in rows of five cards
            Last row will have fewer than five cards if HAND_SIZE % 5 != 0
*/

void displayCards(/*in*/ const int hand[]) {

    for (int row = 0; row < HAND_SIZE / 5 + (HAND_SIZE % 5 != 0); row++)
    {
        int card, cardsInRow = (row < HAND_SIZE / 5) * 5 + (row == HAND_SIZE / 5) * (HAND_SIZE % 5);
        for (card = 0; card < cardsInRow; card++)
            cout << " _____ ";
        cout << endl;
        for (card = 0; card < cardsInRow; card++)
            cout << "|" << hand[card + 5 * row] << "    |";
        cout << endl;
        for (card = 0; card < cardsInRow; card++)
            cout << symbols(hand[card + 5 * row], 1);
        cout << endl;
        for (card = 0; card < cardsInRow; card++)
            cout << symbols(hand[card + 5 * row], 2);
        cout << endl;
        for (card = 0; card < cardsInRow; card++)
            cout << symbols(hand[card + 5 * row], 3);
        cout << endl;
        for (card = 0; card < cardsInRow; card++)
            cout << "|____" << hand[card + 5 * row] << "|";
        cout << endl;
    }
}





/*
    Given the value of a card, and the line being generated,
    returns a string representing that line of the card.
    For instance, the symbols on an eight would be
              |^ ^ ^|
              | ^ ^ |
              |^ ^ ^|
    so an input of (8, 1) or (8, 3) would return "|^ ^ ^|"
    whereas an input of (8, 2) would return "| ^ ^ |"

    pre:    cardVal is an integer between 2 and 9
            line is an integer between 1 and 3
    post:   returns a string representing one line of a card
*/

string symbols(/*in*/ int cardVal, /*in*/ int line) {

    if (line == 2 && cardVal < 5)
        return "|     |";
    else if ((line != 2 && cardVal == 2) || (line == 3 && cardVal == 3) || (line == 2 && cardVal == 5))
        return "|  ^  |";
    else if (cardVal == 9 || (cardVal == 7 && line == 2) || (cardVal == 8 && line != 2))
        return "|^ ^ ^|";
    else
        return "| ^ ^ |";
}


/*SAMPLE OUTPUT:
 ************************************************
                A simple Card Game

 ************************************************
Enter 5 numeric cards, no face cards.  Use 2 - 9.
Card 1: dfiakl
Invalid input. Please enter a valid number between 2 and 9.
Card 1: k
Invalid input. Please enter a valid number between 2 and 9.
Card 1: 1
Invalid input. Please enter a valid number between 2 and 9.
Card 1: 10
Invalid input. Please enter a valid number between 2 and 9.
Card 1: ldfk 2123
Invalid input. Please enter a valid number between 2 and 9.
Card 1: 1 keldfa
Invalid input. Please enter a valid number between 2 and 9.
Card 1: 4
Card 2: 4
Card 3: 4
Card 4: 4
Card 5: 4
 _____  _____  _____  _____  _____
|4    ||4    ||4    ||4    ||4    |
| ^ ^ || ^ ^ || ^ ^ || ^ ^ || ^ ^ |
|     ||     ||     ||     ||     |
| ^ ^ || ^ ^ || ^ ^ || ^ ^ || ^ ^ |
|____4||____4||____4||____4||____4|

Not a valid hand according to a standard deck of 52 cards excluding face cards, aces, etc. There are 4 suits only.
Type Y to play again: Y

Enter 5 numeric cards, no face cards.  Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 8
Card 4: 2
Card 5: 7
 _____  _____  _____  _____  _____
|8    ||7    ||8    ||2    ||7    |
|^ ^ ^|| ^ ^ ||^ ^ ^||  ^  || ^ ^ |
| ^ ^ ||^ ^ ^|| ^ ^ ||     ||^ ^ ^|
|^ ^ ^|| ^ ^ ||^ ^ ^||  ^  || ^ ^ |
|____8||____7||____8||____2||____7|

Two pair!
Type Y to play again: Y

Enter 5 numeric cards, no face cards.  Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 4
Card 4: 6
Card 5: 5
 _____  _____  _____  _____  _____
|8    ||7    ||4    ||6    ||5    |
|^ ^ ^|| ^ ^ || ^ ^ || ^ ^ || ^ ^ |
| ^ ^ ||^ ^ ^||     || ^ ^ ||  ^  |
|^ ^ ^|| ^ ^ || ^ ^ || ^ ^ || ^ ^ |
|____8||____7||____4||____6||____5|

Straight!
Type Y to play again: Y

Enter 5 numeric cards, no face cards.  Use 2 - 9.
Card 1: 9
Card 2: 2
Card 3: 3
Card 4: 4
Card 5: 5
 _____  _____  _____  _____  _____
|9    ||2    ||3    ||4    ||5    |
|^ ^ ^||  ^  || ^ ^ || ^ ^ || ^ ^ |
|^ ^ ^||     ||     ||     ||  ^  |
|^ ^ ^||  ^  ||  ^  || ^ ^ || ^ ^ |
|____9||____2||____3||____4||____5|

High card.
Type Y to play again: N


Card game has now concluded. Exiting program .....


*/