// settester.cpp

#include <iostream>
#include <string>  
#include <ctime> // for time()
#include <cstdlib> // for srand()(
#include "LinkedSet.h"
#include "LinkedSet.cpp"

using std::cout;
using std::endl;
using std::string;
using namespace cs_set;


template <class T>
void displaySet(const LinkedSet<T>& set);



int main() {
    //srand(static_cast<unsigned>(time(nullptr)));    
    LinkedSet<string> set;
    cout << "isEmpty: returns " << set.empty()
        << "; should be 1 (true)" << endl;
    displaySet(set);

    string items[] = { "one", "two", "three", "four", "five", "one" };
    cout << "Add 6 items to the set.  Exactly one should cause duplicate error " << endl;
    for (int i = 0; i < 6; i++)
    {
        try {
            set.insert(items[i]);
        }
        catch (LinkedSet<string>::DuplicateItemError e) {
            cout << "Tried to add a duplicate item." << endl;
        }
    }

    displaySet(set);

    cout << "isEmpty: returns " << set.empty()
        << "; should be 0 (false)" << endl;

    cout << "getCurrentSize: returns " << set.size()
        << "; should be 5" << endl;

    set.insert("extra");


    cout << "contains(\"three\"): returns " << set.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << set.contains("ten")
        << "; should be 0 (false)" << endl;



    try {
        cout << "remove(\"one\")... ";
        set.erase("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }


    try {
        cout << "remove(\"one\")... ";
        set.erase("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;


    //displaySet(set);

    cout << "After clearing the set, ";
    set.clear();
    cout << "isEmpty: returns " << set.empty()
        << "; should be 1 (true)" << endl;


    LinkedSet<int> set1, set2, set3;
    for (int i = 0; i < 20; i++) {
        set1.clear();
        set2.clear();
        int randomSize1 = rand() % 7;
        int randomSize2 = rand() % 7;
        for (int j = 0; j < randomSize1; j++) {
            try {
                set1.insert(rand() % 10);
            }
            catch (LinkedSet<int>::DuplicateItemError e) {
            }
        }
        for (int j = 0; j < randomSize2; j++) {
            try {
                set2.insert(rand() % 10);
            }
            catch (LinkedSet<int>::DuplicateItemError e) {
            }
        }


        cout << "*********** TESTING SET OPERATIONS, TEST #" << i + 1 << " *************" << endl;
        cout << "Set1: ";
        displaySet(set1);
        cout << "Set2: ";
        displaySet(set2);

        LinkedSet<int> set10;
        std::vector<int> set1Items = set1.toVector();

        for (int i = 0; i < set1.size(); i++) {
            try {
                set10.insert(set1Items[i]);
            }
            catch (LinkedSet<int>::DuplicateItemError e) {
            }
        }

        std::vector<int> set2Items = set2.toVector();
        for (int i = 0; i < set2.size(); i++) {
            try {
                set10.insert(set2Items[i]);
            }
            catch (LinkedSet<int>::DuplicateItemError e) {
            }
        }

        cout << "union: " << endl;
        set3 = set1.setUnion(set2);
        cout << "The set contains " << set3.size() << " items." << endl;

        std::vector<int> set3Items = set3.toVector();
        std::vector<int> set10Items = set10.toVector();

        bool testPassed1 = true;
        if (set10.size() != set3.size()) {
            cout << "setUnion() did not pass testing" << endl;
        }
        else {
            for (int i = 0; i < set10.size(); i++) {
                if (!set3.contains(set10Items[i])) {
                    cout << "setUnion()did not pass testing" << endl;
                    testPassed1 = false;
                }
            }
            if (testPassed1) {
                cout << "setUnion() passed testing" << endl;
            }
        }
        cout << endl;



        cout << "intersection: " << endl;
        //displaySet(set1.setIntersection(set2));

        LinkedSet<int> intersectionSet;
        for (int i = 0; i < set1.size(); i++) {
            for (int j = 0; j < set2.size(); j++) {
                if (set1Items[i] == set2Items[j]) {
                    try {
                        intersectionSet.insert(set2Items[j]);
                    }
                    catch (LinkedSet<int>::DuplicateItemError e) {
                    }
                }
            }
        }

        LinkedSet<int> set200 = set1.setIntersection(set2);
        std::vector<int> intersectionSetItems = intersectionSet.toVector();
        std::vector<int> set200Items = set200.toVector();


        cout << "The set contains " << set200.size() << " items." << endl;

        bool testPassed2 = true;
        if (intersectionSet.size() != set200.size()) {
            cout << "setIntersection() did not pass testing." << endl;
        }
        else {
            for (int i = 0; i < set200.size(); i++) {
                if (!intersectionSet.contains(set200Items[i])) {
                    cout << "setIntersection() did not pass testing." << endl;
                    testPassed2 = false;
                }
            }
            if (testPassed2) {
                cout << "setIntersection() passed testing" << endl;
            }
        }
        cout << endl;



        cout << "set1 - set2: " << endl;
        LinkedSet<int> set300 = set1.setDifference(set2);

        LinkedSet<int> differenceSet1 = set1;
        for (int i = 0; i < set1.size(); i++) {
            for (int j = 0; j < set2.size(); j++) {
                if (set1Items[i] == set2Items[j]) {
                    differenceSet1.erase(set2Items[j]);
                }
            }
        }

        std::vector<int> differenceSet1Items = differenceSet1.toVector();
        std::vector<int> set300Items = set300.toVector();

        bool testPassed3 = true;
        cout << "The set contains " << set300.size() << " items." << endl;
        if (differenceSet1.size() != set300.size()) {
            cout << "setDifference() did not pass testing." << endl;
        }
        else {
            for (int i = 0; i < set300.size(); i++) {
                if (!differenceSet1.contains(set300Items[i])) {
                    cout << "setDifference() did not pass testing." << endl;
                    testPassed3 = false;
                }
            }
            if (testPassed3) {
                cout << "setDifference() passed testing." << endl;
            }
        }
        cout << endl;


        cout << "set2 - set1: " << endl;
        LinkedSet<int> set400 = set2.setDifference(set1);

        LinkedSet<int> differenceSet2 = set2;
        for (int i = 0; i < set2.size(); i++) {
            for (int j = 0; j < set1.size(); j++) {
                if (set2Items[i] == set1Items[j]) {
                    differenceSet2.erase(set1Items[j]);
                }
            }
        }

        cout << "The set contains " << set400.size() << " items." << endl;
        std::vector<int> set400Items = set400.toVector();

        bool testPassed4 = true;
        if (differenceSet2.size() != set400.size()) {
            cout << "setDifference() did not pass testing." << endl;
        }
        else {
            for (int i = 0; i < set400.size(); i++) {
                if (!differenceSet2.contains(set400Items[i])) {
                    cout << "setDifference() did not pass testing." << endl;
                    testPassed4 = false;
                }
            }
            if (testPassed4) {
                cout << "setDifference() passed testing." << endl;
            }
        }
        cout << endl;



        cout << "*********** TESTING COPY CONSTRUCTOR *************" << endl;
        set3.clear();
        for (int i = 0; i < 6; i++) {
            set3.insert(i);
        }
        LinkedSet<int> set4 = set3;

        cout << "set3: ";
        displaySet(set3);

        cout << "set4 is a copy of set3.  Here it is: ";
        displaySet(set4);

        cout << "Now delete the 3 from set 4.  Here's the result: ";
        set4.erase(3);
        //displaySet(set4);
        cout << endl;

        if (!set4.contains(5) && !set4.contains(4) && !set4.contains(2) && !set4.contains(1) && !set4.contains(0) && set4.contains(3)) {
            cout << "set 4 does not contain the proper items." << endl;
        }
        else {
            cout << "set 4 contains the proper items." << endl;
        }


        cout << "But set 3 should still have the 3.  Here's set3: ";
        displaySet(set3);






        cout << "*********** TESTING ASSIGNMENT OPERATOR *************" << endl;
        set3.clear();
        for (int i = 0; i < 6; i++) {
            set3.insert(i);
        }

        set4 = set3;

        cout << "set3: ";
        displaySet(set3);

        cout << "set4 is a copy of set3.  Here it is: ";
        displaySet(set4);

        cout << "Now delete the 3 from set 4.  Here's the result: ";
        set4.erase(3);
        //displaySet(set4);
        cout << endl;

        if (!set4.contains(5) && !set4.contains(4) && !set4.contains(2) && !set4.contains(1) && !set4.contains(0) && set4.contains(3)) {
            cout << "set 4 does not contain the proper items." << endl;
        }
        else {
            cout << "set 4 contains the proper items." << endl;
        }

        cout << "But set 3 should still have the 3.  Here's set3: ";
        displaySet(set3);
    }
}






template <class T>
void displaySet(const LinkedSet<T>& set)
{
    cout << "The set contains " << set.size()
        << " items:" << endl;

    std::vector<T> setItems = set.toVector();

    int numberOfEntries = setItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << setItems[i] << " ";
    }
    cout << endl << endl;
}

