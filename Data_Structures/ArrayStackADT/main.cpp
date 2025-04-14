// File: stack-client.cpp

#include <iostream>
#include "ArrayStack.h"
using namespace std;
using namespace cs_stack;



int main() {
    ArrayStack<char> s0;
    for (int i = 0; i < 10; i++) {
        s0.push(char(i + 'A'));
    }

    cout << "Pushing 'A' through 'J'" << endl;
    cout << "Now popping them all off and printing as we go: " << endl;
    while (!s0.empty()) {
        cout << s0.top() << endl;
        s0.pop();
    }



}