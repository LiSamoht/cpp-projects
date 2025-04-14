#include <iostream>
#include <string>
#include "ArraySet.h"

using namespace std;
using namespace cs_set;

void displaySet(ArraySet<string>& set);
void setTester(ArraySet<string>& set);

int main()
{
    ArraySet<string> set;
    cout << "Testing the Array-Based Set:" << endl;
    cout << "The initial set is empty." << endl;
    setTester(set);
    cout << "All done!" << endl;
}





void displaySet(ArraySet<string>& set) {
    cout << "The set contains " << set.size()
        << " items:" << endl;
    std::vector<string> setItems = set.toVector();

    int numEntries = setItems.size();
    for (int i = 0; i < numEntries; i++) {
        cout << setItems[i] << " ";
    }
    cout << endl << endl;
}





void setTester(ArraySet<string>& set)
{
    cout << "empty: returns " << set.empty()
        << "; should be 1 (true)" << endl;
    displaySet(set);

    std::string items[] = { "one", "two", "three", "four", "five", "one" };
    cout << "Insert 6 items into the set: " << endl;
    for (int i = 0; i < 6; i++) {
        set.insert(items[i]);
    }

    displaySet(set);

    cout << "empty: returns " << set.empty()
        << "; should be 0 (false)" << endl;

    cout << "size: returns " << set.size()
        << "; should be 6" << endl;

    try {
        cout << "Try to insert another entry: insert(\"extra\")... ";
        set.insert("extra");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArraySet<string>::CapacityExceededError e) {
        cout << "should cause exception and did!" << endl;
    }

    cout << "contains(\"three\"): returns " << set.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << set.contains("ten")
        << "; should be 0 (false)" << endl;
    cout << "count(\"one\"): returns "
        << set.count("one") << " should be 2" << endl;

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    cout << "count(\"one\"): returns "
        << set.count("one") << " should be 1" << endl;

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;

    displaySet(set);

    cout << "After clearing the set, ";
    set.clear();
    cout << "empty: returns " << set.empty()
        << "; should be 1 (true)" << endl;
}
