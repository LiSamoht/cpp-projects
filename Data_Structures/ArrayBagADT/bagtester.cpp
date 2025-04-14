#include <iostream>
#include <string>
#include "ArrayBag.h"
using namespace std;
using namespace cs_bag;

void displayBag(ArrayBag<string>& bag);
void bagTester(ArrayBag<string>& bag);

int main()
{
    ArrayBag<string> bag;
    cout << "Testing the Array-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    cout << "All done!" << endl;
}






void displayBag(ArrayBag<string>& bag) {
    cout << "The bag contains " << bag.size()
        << " items:" << endl;
    std::vector<string> bagItems = bag.toVector();

    int numEntries = bagItems.size();
    for (int i = 0; i < numEntries; i++) {
        cout << bagItems[i] << " ";
    }
    cout << endl << endl;
}





void bagTester(ArrayBag<string>& bag)
{
    cout << "empty: returns " << bag.empty()
        << "; should be 1 (true)" << endl;
    displayBag(bag);

    std::string items[] = { "one", "two", "three", "four", "five", "one" };
    cout << "Insert 6 items into the bag: " << endl;
    for (int i = 0; i < 6; i++) {
        bag.insert(items[i]);
    }

    displayBag(bag);

    cout << "empty: returns " << bag.empty()
        << "; should be 0 (false)" << endl;

    cout << "size: returns " << bag.size()
        << "; should be 6" << endl;

    try {
        cout << "Try to insert another entry: insert(\"extra\")... ";
        bag.insert("extra");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArrayBag<string>::CapacityExceededError e) {
        cout << "should cause exception and did!" << endl;
    }

    cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" << endl;
    cout << "count(\"one\"): returns "
        << bag.count("one") << " should be 2" << endl;

    try {
        cout << "erase(\"one\")... ";
        bag.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (ArrayBag<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    cout << "count(\"one\"): returns "
        << bag.count("one") << " should be 1" << endl;

    try {
        cout << "erase(\"one\")... ";
        bag.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (ArrayBag<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    try {
        cout << "erase(\"one\")... ";
        bag.erase("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArrayBag<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;

    displayBag(bag);

    cout << "After clearing the bag, ";
    bag.clear();
    cout << "empty: returns " << bag.empty()
        << "; should be 1 (true)" << endl;
}

