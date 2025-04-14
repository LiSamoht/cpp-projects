/*
 Thomas Li
 CS10C
 08/28/2024
 Instructor: Dave Harden
 main.cpp
 
 This program simulates a ticketing queue where multiple people are waiting in line to purchase tickets. 
 The program reads the names of people in the queue from the input, with the special name "You" representing 
 the user's position in the queue. The program then outputs the user's position in the queue and simulates 
 the process of people purchasing tickets until the user is at the front of the line and can purchase their ticket.
 The program expects a series of names entered by the user, one per line, ending with "-1". The Name "You" represents
 the user's position in the queue.
 
*/
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string personName = "";
    int youPosition = -1;

    queue<string> peopleInQueue;

    //Obtains Queue line and "You" position
    getline(cin, personName);
    while (personName != "-1") {
        peopleInQueue.push(personName);
        if (personName == "You") {
            youPosition = peopleInQueue.size();
        }
        getline(cin, personName);
    }


    //If "You" is in the queue, output process until when we can purchase our ticket
    if (youPosition > 0) {
        cout << "Welcome to the ticketing service... " << endl;
        cout << "You are number " << youPosition << " in the queue." << endl;

        while (youPosition > 1) {
            cout << peopleInQueue.front() << " has purchased a ticket." << endl;
            peopleInQueue.pop();
            cout << "You are now number " << --youPosition << endl;
        }
        if (youPosition == 1) {
            cout << "You can now purchase your ticket!" << endl;
        }
    }
    //We're not in the line... youPosition == -1
    else {
        cout << "You are not in line" << endl;
    }
}