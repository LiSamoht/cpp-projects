/*
    Thomas Li
    CS10C
    08/28/2024
    Instructor: Dave Harden
    main.cpp

    This program reads a series of items from the user, storing each item in a linked list (using the built-in list type in C++). 
    The program expets a series of strings (items) as input from the user; the input terminates when the user enters "-1". The inputs
    are stored in a linked list of 'ListItem' objects. Once all items are added to the linked list, the program outputs each item 
    using the `PrintNodeData()` function from the `ListItem` class. The program is designed to emulate a shopping list where each
    item is stored and displayed in the order it was entered.
*/

#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main() {
    list<ListItem> shoppingList; // Linked list: store shopping items

    string item; // Variable to store the user's input

    getline(cin, item);
    while (item != "-1") { // Continue reading until "-1" is entered
        shoppingList.push_back(item); // Add the item to the linked list
        getline(cin, item); // Read the next item
    }

    for (auto& listItem : shoppingList) { // Iterate through the linked list
        listItem.PrintNodeData(); // Output each item
    }

    return 0; // Return success
}