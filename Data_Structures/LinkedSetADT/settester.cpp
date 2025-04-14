#include <iostream>
#include <string>
#include "LinkedSet.cpp"
#include "Node.cpp"
using namespace std;
using namespace cs_set;

void displaySet(LinkedSet<string>& set);
void copyConstructorTester();
void setTester();

int main() {
    copyConstructorTester();
    setTester();
}




void displaySet(LinkedSet<string>& set) {
    vector<string> setItems = set.toVector();

    int numberOfEntries = setItems.size();
    for (int i = 0; i < numberOfEntries; i++) {
        cout << setItems[i] << " ";
    }
}





void copyConstructorTester() {
    cout << "Testing copy constructor:" << endl;
    LinkedSet<string> set;
    string items[] = { "zero", "one", "two", "three", "four", "five" };
    for (int i = 0; i < 6; i++) {
        cout << "inserting " << items[i] << endl;
        set.insert(items[i]);
    }

    cout << "The original set: ";
    displaySet(set);
    cout << endl;

    LinkedSet<string> copyOfSet(set);
    cout << "Copy of set: ";
    displaySet(copyOfSet);
    cout << endl;

    cout << "Removing 'one' from copy of set." << endl;
    copyOfSet.erase("one");

    cout << "The original set: ";
    displaySet(set);
    cout << endl;

    cout << "Copy of set: ";
    displaySet(copyOfSet);
    cout << endl;
}






void setTester() {
    LinkedSet<string> set;
    cout << "Testing the Link-Based Set:" << endl;
    cout << "empty(): returns " << set.empty()
        << "; should be 1 (true)" << endl;
    displaySet(set);
    cout << endl;

    string items[] = { "one", "two", "three", "four", "five", "one" };
    cout << "insert 6 items to the set: " << endl;
    for (int i = 0; i < 6; i++) {
        set.insert(items[i]);
    }

    displaySet(set);
    cout << endl;

    cout << "empty(): returns " << set.empty()
        << "; should be 0 (false)" << endl;

    cout << "size: returns " << set.size()
        << "; should be 6" << endl;

    cout << "insert another entry: insert(\"extra\") " << endl;
    set.insert("extra");

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
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    cout << "count(\"one\"): returns "
        << set.count("one") << " should be 1" << endl;

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    try {
        cout << "erase(\"one\")... ";
        set.erase("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;

    displaySet(set);
    cout << endl;

    cout << "After clearing the set, ";
    set.clear();

    cout << "empty(): returns " << set.empty()
        << "; should be 1 (true)" << endl;
}




