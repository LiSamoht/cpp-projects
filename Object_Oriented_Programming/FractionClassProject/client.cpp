//client code - note namespace std and namespace cs10b_fraction (should be declared as a block in fraction.h and fraction.cpp)
// download and use frac_data.txt data file content for Basic Test section of client code
#include <iostream>
#include "fraction.h"
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
using namespace cs10b_fraction;

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
bool eof(/*inout*/ifstream& in);
string boolString(/*in*/bool convertMe);


int main()
{
    cout << "Project#2: Fraction class (ADT) client program to test CLASS INVARIANT\n";
    cout << "There are two data members used to represent the denominator and numerator\n";
    cout << "for each instance of a Fraction class object class.\n";
    cout << "The client code provides an interface to test correct operations on fraction  \n";
    cout << "objects that are negative, improper (larger numerator than denominator), \n";
    cout << "or whole numbers (denominator of 1).\n";
    cout << "Here is a list test type and order in which the tests will be conducted\n\n";
    cout << "1. BasicTest\n";
    cout << "2. RelationTest\n";
    cout << "3. BinaryMathTest\n";
    cout << "4. MathAssignTest\n\n";

    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();

    cout << "\nProject#2 -Fraction class (ADT) testing now concluded.\n";
    cout << "Check output for correct results from the Fraction class (ADT) implementation.\n";

    return 0;
}

// Function provides the interface to test the following Fraction class member implementation algorithms
// Class constructor, a fraction reduction algorithm in simplify, and two nonmember friend ostream << and istream >> operator functions
void BasicTest()
{
    cout << "***********************************************************************\n";
    cout << "* Basic Test: Testing member constructor, simplify() and nonmember    *\n";
    cout << "* friend ostream << operator for basic Fraction object creation &     *\n";
    cout << "* printing(Fractions should be in reduced form, and as mixed numbers.)*\n";
    cout << "***********************************************************************\n";

    const Fraction fr[] = { Fraction(4, 8), Fraction(-15,21),
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12) };

    for (int i = 0; i < 7; i++) {
        cout << "Fraction [" << i << "] = " << fr[i] << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* Basic Test: Testing simplify() and nonmember friend istream >> and  *\n";
    cout << "* ostream << operators for reading and display of Fraction objects    *\n";
    cout << "* from data file                                                      *\n";
    cout << "***********************************************************************\n";

    string fileName;

    cout << "Enter file name with fraction data to read: ";
    cin >> fileName;

    ifstream in(fileName);

    while (!in)
    {
        cin.ignore(200, '\n');
        cout << fileName << " not found!" << endl;
        cout << "Make sure the fraction data file to read is in the project folder." << endl;
        cout << "Enter file name with fraction data to read: ";
        cin >> fileName;
        in.open(fileName);
    }

    while (!eof(in)) {
        Fraction f;
        if (in.peek() == '/' || in.peek() == '*' || isalpha(in.peek())) {
            in.ignore(200, '\n');   //skip this line, it's a comment
        }
        else {
            in >> f;
            cout << "Read Fraction = " << f << endl;
        }
    }
}


bool eof(ifstream& in)
{
    char ch;
    in >> ch;
    in.putback(ch);
    return !in;
}


string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    }
    else {
        return "false";
    }
}

// Function provides the interface to test the following Fraction class member implementation algorithms
// Various nonmember friend binary Boolean such as  <, <=, >, >=, ==, != operator functions
void RelationTest()
{
    cout << "\n***********************************************************************\n";
    cout << "* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *\n";
    cout << "*  ==, != relational operators between Fractions                      *\n";
    cout << "***********************************************************************\n";

    const Fraction fr[] = { Fraction(3, 6), Fraction(-15, 30), Fraction(1, 2),
                            Fraction(1,10), Fraction(0,1), Fraction(0,2) };

    for (int i = 0; i < 5; i++) {
        cout << "Comparing " << fr[i] << " to " << fr[i + 1] << endl;
        cout << "\tIs left < right? " << boolString(fr[i] < fr[i + 1]) << endl;
        cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i + 1]) << endl;
        cout << "\tIs left > right? " << boolString(fr[i] > fr[i + 1]) << endl;
        cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i + 1]) << endl;
        cout << "\tDoes left == right? " << boolString(fr[i] == fr[i + 1]) << endl;
        cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i + 1]) << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *\n";
    cout << "* ==, != relations between Fractions and integers                     *\n";
    cout << "***********************************************************************\n";
    Fraction f(-3, 6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;

    Fraction g(1, 4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}

// Function provides the interface to test the following Fraction class member implementation algorithms
// Various nonmember friend binary arithmetic +, -, *, / operator functions
void BinaryMathTest()
{

    cout << "\n***********************************************************************\n";
    cout << "* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *\n";
    cout << "* / operators between Fractions                                       *\n";
    cout << "***********************************************************************\n";

    const Fraction fr[] = { Fraction(1, 6), Fraction(1,3),
                           Fraction(-2,3), Fraction(5), Fraction(-4,3) };

    for (int i = 0; i < 4; i++) {
        cout << fr[i] << " + " << fr[i + 1] << " = " << fr[i] + fr[i + 1] << endl;
        cout << fr[i] << " - " << fr[i + 1] << " = " << fr[i] - fr[i + 1] << endl;
        cout << fr[i] << " * " << fr[i + 1] << " = " << fr[i] * fr[i + 1] << endl;
        cout << fr[i] << " / " << fr[i + 1] << " = " << fr[i] / fr[i + 1] << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *\n";
    cout << "* / operators between Fractions and integers                          *\n";
    cout << "***********************************************************************\n";
    Fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;

    Fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}


// Function provides the interface to test the following Fraction class member implementation algorithms
// Various member shorthand arithmetic assignment +=, -=, *=, /= as wells as increment/decrement prefix and postfix operator functions
void MathAssignTest()
{
    cout << "\n***********************************************************************\n";
    cout << "* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *\n";
    cout << "* -=, *=, /= operators on Fractions                                   *\n";
    cout << "***********************************************************************\n";

    Fraction fr[] = { Fraction(1, 6), Fraction(4),
                     Fraction(-1,2), Fraction(5) };

    for (int i = 0; i < 3; i++) {
        cout << fr[i] << " += " << fr[i + 1] << " = ";
        cout << (fr[i] += fr[i + 1]) << endl;
        cout << fr[i] << " -= " << fr[i + 1] << " = ";
        cout << (fr[i] -= fr[i + 1]) << endl;
        cout << fr[i] << " *= " << fr[i + 1] << " = ";
        cout << (fr[i] *= fr[i + 1]) << endl;
        cout << fr[i] << " /= " << fr[i + 1] << " = ";
        cout << (fr[i] /= fr[i + 1]) << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *\n";
    cout << "* -=, *=, /= operators using integers                                 *\n";
    cout << "***********************************************************************\n";
    Fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n***********************************************************************\n";
    cout << "* MathAssignTest: Testing member increment/decrement prefix and       *\n";
    cout << "* postfix operators                                                   *\n";
    cout << "***********************************************************************\n";
    Fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}

// download and use frac_data.txt data file content for Basic Test section of client code

