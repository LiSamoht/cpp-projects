#include <iostream>
#include <string>
#include "Node.h"
#include "BSTChecker.h"
using namespace std;

int main() {
    Node* badNode;
    Node* userRoot;
    string inputString;

    inputString = "(10, (20), (30, (29), (31)))";
    userRoot = Node::Parse(inputString);

    if (userRoot) {
        badNode = BSTChecker::CheckBSTValidity(userRoot);
        cout << "Output should be: 20" << endl;
        if (badNode) {
            cout << to_string(badNode->key) << endl;
        }
        else {
            cout << "No violation" << endl;
        }
    }
    else {
        cout << "Failed to parse input tree" << endl;
    }

    Node::DeleteTree(userRoot);




    inputString = "(20, (10), (30, (29), (31)))";
    userRoot = Node::Parse(inputString);

    if (userRoot) {
        badNode = BSTChecker::CheckBSTValidity(userRoot);
        cout << "Output should be: No violation" << endl;
        if (badNode) {
            cout << to_string(badNode->key) << endl;
        }
        else {
            cout << "No violation" << endl;
        }
    }
    else {
        cout << "Failed to parse input tree" << endl;
    }

    Node::DeleteTree(userRoot);





    inputString = "(80, (60, (40, (20, None, (50)), None), None), None)";
    userRoot = Node::Parse(inputString);

    if (userRoot) {
        badNode = BSTChecker::CheckBSTValidity(userRoot);
        cout << "Output should be: 50" << endl;
        if (badNode) {
            cout << to_string(badNode->key) << endl;
        }
        else {
            cout << "No violation" << endl;
        }
    }
    else {
        cout << "Failed to parse input tree" << endl;
    }

    Node::DeleteTree(userRoot);






    Node* root = new Node(68);
    root->InsertAll({ 77, 75, 73, 71, 76, 54, 19, 91, 12 });
    Node* userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (nullptr == userResult) {
        cout << "BSTChecker::CheckBSTValidity() correctly returned nullptr" << endl;
    }
    else {
        cout << "BSTChecker::CheckBSTValidity() returned something other than nullptr ";
        cout << "for a valid BST. Expected return value is nullptr." << endl;
    }

    Node::DeleteTree(root);









    Node* node22 = new Node(22, new Node(11), new Node(33));
    badNode = new Node(40, nullptr, new Node(50));
    root = new Node(44, node22, badNode);

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    bool pass = false;
    if (badNode == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
        pass = true;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node." << endl;
    }

    Node::DeleteTree(root);





    badNode = new Node(86);
    root = new Node(
        90,
        new Node(
            80,
            badNode, // violation
            new Node(89)
        ),
        new Node(
            91,
            nullptr,
            new Node(98, nullptr, new Node(99))
        )
    );

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (badNode == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node." << endl;
    }

    Node::DeleteTree(root);










    badNode = new Node(55);
    root = new Node(
        59,
        new Node(38, new Node(37), new Node(41)),
        new Node(
            71,
            new Node(65, new Node(62), nullptr),
            new Node(
                84,
                badNode, // violation
                nullptr
            )
        )
    );

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (badNode == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node." << endl;
    }

    Node::DeleteTree(root);







    root = new Node(77);
    Node* cur = root;
    Node* previous = nullptr;

    // Create and add another 77 node 50 times
    for (int i = 0; i < 50; i++) {
        cur->left = new Node(77);
        previous = cur;
        cur = cur->left;
    }

    // Set the current node's right child to the root's left child
    cur->right = root->left;

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (cur == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node. The node with either the left or right ";
        cout << "child pointing to an ancestor must be returned." << endl;
    }

    // Remove the circular reference, then delete the tree
    cur->right = nullptr;
    Node::DeleteTree(root);






    root = new Node(77);
    cur = root;
    previous = nullptr;

    // Create and add another 77 node 50 times
    for (int i = 0; i < 50; i++) {
        cur->left = new Node(77);
        previous = cur;
        cur = cur->left;
    }

    // Set the current node's right child to the an ancestor
    cur->right = root->left->left->left->left->left->left->left->left->left;

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (cur == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node. The node with either the left or right ";
        cout << "child pointing to an ancestor must be returned." << endl;
    }

    // Remove the circular reference, then delete the tree
    cur->right = nullptr;
    Node::DeleteTree(root);






    Node* rootRight = new Node(89);
    root = new Node(87, new Node(51), rootRight);
    badNode = new Node(91, rootRight, nullptr);
    rootRight->right = badNode;

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (badNode == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node." << endl;
    }

    // Remove the circular reference, then delete the tree
    rootRight->right = nullptr;
    Node::DeleteTree(root);








    // Create the invalid tree wherein a node has a child that references an 
    // ancestor. The ancestor is NOT the immediate parent, nor the root.
    root = new Node(51, new Node(27, new Node(14), nullptr), nullptr);
    badNode = new Node(92);
    Node* node83 = new Node(83, new Node(77), badNode);
    Node* node72 = new Node(72, nullptr, node83);
    badNode->left = node72;
    root->right = node72;

    // Call the user's CheckBSTValidity() function
    userResult = BSTChecker::CheckBSTValidity(root);

    // Check the user's result
    if (badNode == userResult) {
        cout << "CheckBSTValidity() correctly returned the rule-violating node." << endl;
    }
    else if (nullptr == userResult) {
        cout << "CheckBSTValidity() returned nullptr for an invalid tree." << endl;
    }
    else {
        cout << "CheckBSTValidity() returned a node that is not the BST ";
        cout << "rule-violating node." << endl;
    }

    // Remove the circular reference, then delete the tree
    badNode->left = nullptr;
    Node::DeleteTree(root);





}