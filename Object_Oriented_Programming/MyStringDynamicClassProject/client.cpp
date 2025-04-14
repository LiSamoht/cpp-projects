/* //client code - note namespace std and namespace cs_mystring (should be declared as a block in mystring.h and mystring.cpp)
// download and use mystring_data.txt data file content for Basic Test section of client code
 * -------------------
 * These functions are designed to help you test your MyString objects,
 * as well as show the client usage of the class.
 *
 * The BasicTest function builds an array of strings using various
 * constructor options and prints them out.  It also uses the String
 * stream operations to read some strings from a data file.
 *
 * The RelationTest function checks out the basic relational operations
 * (==, !=, <, etc) on Strings and char *s.
 *
 * The ConcatTest functions checks the overloaded + and += operators that
 * do string concatenation.
 *
 * The CopyTest tries out the copy constructor and assignment operators
 * to make sure they do a true deep copy.
 *
 * Although not exhaustive, these tests will help you to exercise the basic
 * functionality of the class and show you how a client might use it.
 *
 * While you are developing your MyString class, you might find it
 * easier to comment out functions you are ready for, so that you don't
 * get lots of compile/link complaints.
 */

#include "mystring.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <string>
#include <cassert>
#include <iostream>
using namespace std;
using namespace cs_mystring;

void BasicTest();
void RelationTest();
void ConcatTest();
void CopyTest();
MyString AppendTest(const MyString& ref, MyString val);
string boolString(bool convertMe);

int main()
{
    cout << "Project#4: MyString class (ADT) client program to test CLASS INVARIANT\n";
    cout << "The class has one private data member defined as follows:\n";
    cout << "char *str;\n";
    cout << "str always represents a valid null-terminated c-string for each instance\n";
    cout << "of a MyString class object class.\n";
    cout << "The client code provides an interface to test correct operations on MyString\n";
    cout << "objects\n";

    cout << "\nHere is a list of tests and the order in which the tests will be conducted\n";
    cout << "1. BasicTest\n";
    cout << "2. RelationTest\n";
    cout << "3. ConcatTest\n";
    cout << "4. CopyTest\n\n";

    BasicTest();
    RelationTest();
    ConcatTest();
    CopyTest();

    cout << "\nProject#4 -MyString class (ADT) testing now concluded.\n";
    cout << "MyString class destructor has been invoked and memory from the heap deallocated\n";
    cout << "Check output for correct results from the MyString class (ADT) implementation.\n";


    return 0;
}


string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    }
    else {
        return "false";
    }
}


void BasicTest()
{
    MyString s;
    int stringLength;

    cout << "***********************************************************************\n";
    cout << "* Basic Test: Testing various member constructor options and nonmember*\n";
    cout << "* friend ostream << operator for basic MyString object creation &     *\n";
    cout << "* printing                                                            *\n";
    cout << "***********************************************************************\n";

    const MyString strs[] =
    { MyString("Wow"), MyString("C++ is neat!"),
     MyString(""), MyString("a-z") };


    for (int i = 0; i < 4; i++) {
        cout << "string [" << i << "] = " << strs[i] << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* Basic Test: Testing nonmember friend istream >> and ostream <<      *\n";
    cout << "* operators for reading and display of MyString objects from data file*\n";
    cout << "***********************************************************************\n";

    cout << endl << "----- first, word by word" << endl;
    ifstream in("mystring_data.txt");
    assert(in);
    while (in.peek() == '#') {
        in.ignore(128, '\n');
    }
    in >> s;
    while (in) {
        cout << "Read string = " << s << endl;
        in >> s;
    }
    in.close();

    cout << "\n*************************************************************************\n";
    cout << "* Basic Test: Testing member function readline read, a nonmember friend *\n";
    cout << "* istream >> and ostream <<operators for reading and display of MyString*\n";
    cout << "* objects from data file                                                *\n";
    cout << "* ***********************************************************************\n";

    cout << endl << "----- now, line by line" << endl;
    ifstream in2("mystring_data.txt");
    assert(in2);
    while (in2.peek() == '#') {
        in2.ignore(128, '\n');
    }
    s.readline(in2, '\n');
    while (in2) {
        cout << "Read string = " << s << endl;
        s.readline(in2, '\n');
    }
    in2.close();

    cout << "\n****************************************************************************\n";
    cout << "* Basic Test: Testing access to characters (using const and non const)     *\n";
    cout << "* using constructors, member function length that returns a cstring length,*\n";
    cout << "* the square bracket [] overloaded operator and a nonmember friend         *\n";
    cout << "* ostream << for display of MyString objects content                       *\n";
    cout << "* **************************************************************************\n";

    cout << endl << "----- Testing access to characters (using const)" << endl;
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    cout << "Whole string is " << s1 << endl;
    cout << "now char by char: ";
    stringLength = s1.length();
    for (int i = 0; i < stringLength; i++) {
        cout << s1[i];
    }


    cout << endl << "\n----- Testing access to characters (using non-const)" << endl;
    MyString s2("abcdefghijklmnopqsrtuvwxyz");
    cout << "Start with " << s2;
    stringLength = s2.length();
    for (int i = 0; i < stringLength; i++) {
        s2[i] = toupper(s2[i]);
    }
    cout << " and convert to " << s2 << endl;
}


void RelationTest()
{

    cout << "\n***********************************************************************\n";
    cout << "* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *\n";
    cout << "*  ==, != relational operators between MyString objects               *\n";
    cout << "***********************************************************************\n";

    const MyString strs[] =
    { MyString("app"), MyString("apple"), MyString(""),
    MyString("Banana"), MyString("Banana") };

    for (int i = 0; i < 4; i++) {
        cout << "Comparing " << strs[i] << " to " << strs[i + 1] << endl;
        cout << "\tIs left < right? " << boolString(strs[i] < strs[i + 1]) << endl;
        cout << "\tIs left <= right? " << boolString(strs[i] <= strs[i + 1]) << endl;
        cout << "\tIs left > right? " << boolString(strs[i] > strs[i + 1]) << endl;
        cout << "\tIs left >= right? " << boolString(strs[i] >= strs[i + 1]) << endl;
        cout << "\tDoes left == right? " << boolString(strs[i] == strs[i + 1]) << endl;
        cout << "\tDoes left != right ? " << boolString(strs[i] != strs[i + 1]) << endl;
    }

    cout << "\n***********************************************************************\n";
    cout << "* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *\n";
    cout << "*  ==, != relational operators between MyString objects and char      *\n";
    cout << "***********************************************************************\n";

    MyString s("he");
    const char* t = "hello";
    cout << "Comparing " << s << " to " << t << endl;
    cout << "\tIs left < right? " << boolString(s < t) << endl;
    cout << "\tIs left <= right? " << boolString(s <= t) << endl;
    cout << "\tIs left > right? " << boolString(s > t) << endl;
    cout << "\tIs left >= right? " << boolString(s >= t) << endl;
    cout << "\tDoes left == right? " << boolString(s == t) << endl;
    cout << "\tDoes left != right ? " << boolString(s != t) << endl;

    MyString u("wackity");
    const char* v = "why";
    cout << "Comparing " << v << " to " << u << endl;
    cout << "\tIs left < right? " << boolString(v < u) << endl;
    cout << "\tIs left <= right? " << boolString(v <= u) << endl;
    cout << "\tIs left > right? " << boolString(v > u) << endl;
    cout << "\tIs left >= right? " << boolString(v >= u) << endl;
    cout << "\tDoes left == right? " << boolString(v == u) << endl;
    cout << "\tDoes left != right ? " << boolString(v != u) << endl;

}


void ConcatTest()
{
    cout << "\n************************************************************************\n";
    cout << "* ConcatTest: Testing nonmember friend binary arithmetic + operator    *\n";
    cout << "* that do concatenation on MyString objects                            *\n";
    cout << "************************************************************************\n";

    cout << "\n----- Testing concatenation on MyStrings\n";
    const MyString s[] =
    { MyString("outrageous"), MyString("milk"), MyString(""),
    MyString("cow"), MyString("bell") };

    for (int i = 0; i < 4; i++) {
        cout << s[i] << " + " << s[i + 1] << " = " << s[i] + s[i + 1] << endl;
    }

    cout << "\n************************************************************************\n";
    cout << "* ConcatTest: Testing nonmember friend binary arithmetic + operator    *\n";
    cout << "* that do concatenation between MyString objects and char*             *\n";
    cout << "************************************************************************\n";

    cout << "\n----- Testing concatenation between MyString and char *\n";
    const MyString a("abcde");
    const char* b = "XYZ";
    cout << a << " + " << b << " = " << a + b << endl;
    cout << b << " + " << a << " = " << b + a << endl;

    cout << "\n************************************************************************\n";
    cout << "* ConcatTest: Testing member binary arithmetic += operator             *\n";
    cout << "* that do concatenation between MyString objects and char*             *\n";
    cout << "************************************************************************\n";

    cout << "\n----- Testing shorthand concat/assign using MyString and char *\n";
    MyString u("I love ");
    const char* v = "programming";
    cout << u << " += " << v << " = ";
    cout << (u += v) << endl;
}


MyString AppendTest(const MyString& ref, MyString val)
{
    val[0] = 'B';
    return val + ref;
}

void CopyTest()
{
    cout << "\n*****************************************************************************\n";
    cout << "* CopyTest: Testing default constructor, copy constructor and member        *\n";
    cout << "* assignment = operator on MyStrings to check for memberwise shallow copy   *\n";
    cout << "* the member square bracket [] overloaded operator and a nonmember friend   *\n";
    cout << "* ostream << for display of MyString objects content                        *\n";
    cout << "* ***************************************************************************\n";
    cout << "\n----- Testing copy constructor and operator= on MyStrings\n";

    MyString orig("cake");


    MyString copy(orig);    // invoke copy constructor

    copy[0] = 'f';  // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy << endl;


    MyString copy2;      // makes an empty string

    copy2 = orig;        // invoke operator=
    copy2[0] = 'f';      // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy2 << endl;

    copy2 = "Copy Cat";
    copy2 = copy2;        // copy onto self and see what happens
    cout << "after self assignment, copy is " << copy2 << endl;


    cout << "Testing pass & return MyStrings by value and ref" << endl;
    MyString val = "winky";
    MyString sum = AppendTest("Boo", val);
    cout << "after calling Append, sum is " << sum << endl;
    cout << "val is " << val << endl;
    val = sum;
    cout << "after assign,  val is " << val << endl;

}
