/*
Thomas Li
10/20/2024

The following functions evaluate any infix expression. The function evaluateInfix() first converts the expression to a postfix expression
which is then easily readily evaluated. The function also uses the precedence function to keep track of the order in which the expression is 
evaluated (when converting to a postfix expression).
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluateInfix(const string& infix);
string infixToPostfix(const string& infix);
int precedence(const char op);

int main() {
	string infixExpr;

	// Test case 1
	infixExpr = "3+(2*2)-4";
	cout << "Infix: " << infixExpr << " = " << evaluateInfix(infixExpr) << endl;

	// Test case 2
	infixExpr = "(1+3)*(2-1)";
	cout << "Infix: " << infixExpr << " = " << evaluateInfix(infixExpr) << endl;

	// Test case 3
	infixExpr = "6/3+2*(4-2)";
	cout << "Infix: " << infixExpr << " = " << evaluateInfix(infixExpr) << endl;

	return 0;
}

/*
This function evaluates the numerical value of infix. It first converts the infix to a postfix expression. Then, it 
creates a value stack that is consistently updated until, by the end, it only contains the end result. 
It pushes any digit it sees to a value stack, and when it finds an operator, it calculates the operation based on the 2 operands preceding it,
replacing them with the result of the operation. This is repeated (collapsing down), until only the end result remains. Then, the top of the stack 
is returned.
*/
int evaluateInfix(const string& infix) {
	string postfix = infixToPostfix(infix);
	stack<int> valueStack;
	for (char c : postfix) {
		if (isdigit(c)) {
			valueStack.push(c-'0');
		}
		else {
			int op2 = valueStack.top();
			valueStack.pop();
			int op1 = valueStack.top();
			valueStack.pop();

			int result;
			switch (c) {
			case '+': result = op1 + op2; break;
			case '-': result = op1 - op2; break;
			case '*': result = op1 * op2; break;
			case '/': result = op1 / op2; break;
			}
			valueStack.push(result);
		}
	}
	return valueStack.top();
}

/*
This function converts an infix to a postfix expression. 
Algorithm: 
P: It first creates an operator stack and an output string. Then, it iterates through each character in the infix. 
1. If it finds a character, it appends the character to the end of the string.
2. If it finds an opening '(', it pushes that to the operator stack. 
3. When it finds an actual operator, there are a few things to check which make
logical and intuitive sense: if the stack has just opened a '(', then the operation must wait until another ')' is found or another operator is found
in order to ensure the operator isn't used too quickly (ex: if (a+b-c) is found somewhere, then (+- and abc. Notice that we can't append + too quickly
because the - must come first: abc-+.) But, we must also be careful that higher precedence operators are printed first because those operations will
occur first. So, we check whether the current operator has a lower precedence than the one before it...if so, then it is time to print the one before it.
4. after all characters are processed, pop and append any remaining characters from the stack onto the string.
5. return the string.
*/
string infixToPostfix(const string& infix) {
	stack<char> opStack;
	string postfix;
	for (char c: infix) {
		if (isdigit(c)) {
			postfix+=(c);
		}
		else if (c == '(') {
			opStack.push(c);
		}
		else if ((c == '+' || c == '-' || c == '*' || c == '/')) {
			while (!opStack.empty() && opStack.top() != '(' && precedence(c) <= precedence(opStack.top())) {
				postfix += opStack.top();
				opStack.pop();
			}
			opStack.push(c);
		}
		else if (c == ')') {
			while (!opStack.empty() && opStack.top() != '(') {
				postfix += opStack.top();
				opStack.pop();
			}
			if (opStack.top() == '(') opStack.pop();
		}
	}

	while (!opStack.empty()) {
		postfix += opStack.top();
		opStack.pop();
	}

	return postfix;
}

/*
This simply calculates the precedence values for each operator. * and / have higher precedence than + and -.
*/
int precedence(const char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}