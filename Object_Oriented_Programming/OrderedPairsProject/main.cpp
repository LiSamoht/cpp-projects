#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "OrderedPair.h"
#include "OrderedPair.cpp"
using namespace std;
using namespace cs_pairs;





int main() {
    int num1, num2;
    OrderedPair<int> myList[10];

    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList[0].print();
    cout << endl;

    for (int i = 0; i < 10; i++) {
        myList[i].setFirst(rand() % 50);
        myList[i].setSecond(rand() % 50 + 50);
    }

    myList[2] = myList[0] + myList[1];

    if (myList[0] < myList[1]) {
        myList[0].print();
        cout << " is less than ";
        myList[1].print();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        myList[i].print();
        cout << endl;
    }

    cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
    cin >> num1 >> num2;
    OrderedPair<int> x;

    try {
        x.setFirst(num1);
        x.setSecond(num2);
    } catch (OrderedPair<int>::DuplicateMemberError e) {
        cout << "Error, you attempted to set both members of the OrderedPair to the same number."
             << endl;
        x.setFirst(OrderedPair<int>::DEFAULT_VALUE);
        x.setSecond(OrderedPair<int>::DEFAULT_VALUE);
    }

    cout << "The resulting OrderedPair: ";
    x.print();
    cout << endl;



    string str1, str2;
    OrderedPair<string> myStrList[10];

    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myStrList[0].print();
    cout << endl;


    string empty = "";
    for (int i = 0; i < 10; i++) {
        myStrList[i].setFirst(empty + char('a' + rand() % 26));
        myStrList[i].setSecond(empty + char('A' + rand() % 26));
    }

    myStrList[2] = myStrList[0] + myStrList[1];

    if (myStrList[0] < myStrList[1]) {
        myStrList[0].print();
        cout << " is less than ";
        myStrList[1].print();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        myStrList[i].print();
        cout << endl;
    }

    cout << "Enter two strings to use in an OrderedPair.  Make sure they are different strings: ";
    cin >> str1 >> str2;
    OrderedPair<string> y;

    try {
        y.setFirst(str1);
        y.setSecond(str2);
    }
    catch (OrderedPair<string>::DuplicateMemberError e) {
        cout << "Error, you attempted to set both members of the OrderedPair to the same string."
            << endl;
        y.setFirst(OrderedPair<string>::DEFAULT_VALUE);
        y.setSecond(OrderedPair<string>::DEFAULT_VALUE);
    }

    cout << "The resulting OrderedPair: ";
    y.print();
    cout << endl;

    return 0;
}