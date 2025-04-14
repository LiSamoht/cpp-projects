#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
using namespace std;
#include "HashedDictionary.h"

struct FamousPerson {
    string id;
    char taxStatus;
    string lastname;
    string firstname;
    int age;
    string street;
    string zip;
};





void readOnePerson(istream& infile, FamousPerson& readMe);


// the insertion operator overload is just here so that the HashedDictionary
// display function can use it to print FamousPerson objects.
ostream& operator<<(ostream& out, const FamousPerson& printMe);

/*
int main() {
    HashedDictionary<string, FamousPerson> h;
    FamousPerson tempPerson;
    ifstream infile("famous.txt");
    assert(infile);

    readOnePerson(infile, tempPerson);
    while (infile) {
        h.add(tempPerson.lastname, tempPerson);
        readOnePerson(infile, tempPerson);
    }

    //h.display();
    cout << "This is a test." << endl;
}
*/

int main() {
    HashedDictionary<string, FamousPerson> h;
    FamousPerson tempPerson;
    ifstream infile("famous.txt");
    string line;
    //assert(infile);

   // Read each line from the file and print it
    while (getline(infile, line)) {
        // Process each line as needed

        cout << line << endl;
        stringstream liness(line);
        readOnePerson(liness, tempPerson);
        cout << tempPerson.lastname << endl;
        h.add(tempPerson.lastname, tempPerson);
    }

    // Always close the file when done
    infile.close();

    //readOnePerson(infile, tempPerson);
    //while (getline(cin,line) {
    //h.add(tempPerson.lastname, tempPerson);
    //readOnePerson(infile, tempPerson);
    //}

    //h.display();
    cout << "This is a test." << endl;
}



ostream& operator<<(ostream& out, const FamousPerson& printMe) {
    out << printMe.id << " ";
    out << printMe.taxStatus << " ";
    out << printMe.lastname << " ";
    out << printMe.firstname << " ";
    out << printMe.age << " ";
    out << printMe.street << " ";
    out << printMe.zip;
    return out;
}





void readOnePerson(istream& infile, FamousPerson& readMe) {
    infile >> readMe.id;
    infile >> readMe.taxStatus;
    infile >> readMe.lastname;
    infile >> readMe.firstname;
    infile >> readMe.age;
    infile >> readMe.street;
    infile >> readMe.zip;
}