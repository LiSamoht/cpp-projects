#pragma once
#ifndef BSTCHECKER_H
#define BSTCHECKER_H

// Your code here (include additional header files, if needed)
#include "Node.h"
#include <unordered_set>
/* 
The BSTChecker class provides utility functions to check the validity of a binary search tree (BST).
It determines whether a given binary tree adheres to the properties of a BST by recursively
traversing the tree and ensuring that:
BOUNDS CHECKING: Each node's key is greater than all keys in its left subtree,Each node's key is less than all keys in its right subtree.
NO ANCESTORS: No node's left or right child references an ancestor node.*/
class BSTChecker {
public:

    /*
    Checks the validity of a binary search tree under standard/conventional understanding. Returns violating nodes if:
    A node in the left subtree of an ancestor with a lesser key.
    A node in the right subtree of an ancestor with a greater key
    A node with the left or right member variable pointing to an ancestor

    pre: none
    post: returns the invalid node or nullptr if found none.
    */
    static Node* CheckBSTValidity(Node* root) {
        // Use a set to track ancestors
        std::unordered_set<Node*> ancestors;
        return IsBSTHelper(root, nullptr, nullptr, ancestors);
    }

    /*
    Checks if the left or right child of the given node is an ancestor of the node.
    pre: none
    post: determines if the node's children are referencing any ancestors.
    */
    static bool CheckForRefAncestors(Node* node, std::unordered_set<Node*>& ancestors) {
        if (node->left != nullptr && ancestors.find(node->left) != ancestors.end()) {
            return true;  // Left child references an ancestor
        }
        if (node->right != nullptr && ancestors.find(node->right) != ancestors.end()) {
            return true;  // Right child references an ancestor
        }

        return false;
    }

    /*
    This is the main recursive algorithm/body that determines whether a node is valid. It uses/tracks a minNode and a maxNode to take care of bounds checking, 
    as well as an unordered set to keep track of the ancestors that have been covered already.
    */
    static Node* IsBSTHelper(Node* node, Node* minNode, Node* maxNode, std::unordered_set<Node*>& ancestors) {
        // Base case: if the node is nullptr, the tree is valid
        if (node == nullptr) {
            return nullptr;
        }

        if (CheckForRefAncestors(node, ancestors)) {
            return node;
        }
        // Add the current node to the ancestors set for the recursive call
        ancestors.insert(node);

        // Check if the node violates the min/max constraints
        if ((minNode != nullptr && node->key < minNode->key) ||
            (maxNode != nullptr && node->key > maxNode->key)) {
            ancestors.erase(node);  // Remove node from ancestors before returning
            return node;  // This node violates the BST property
        }

        // Check the left subtree with the updated max constraint
        Node* leftViolation = IsBSTHelper(node->left, minNode, node, ancestors);
        if (leftViolation != nullptr) {
            ancestors.erase(node);
            return leftViolation;  // Found a violation in the left subtree
        }

        // Check the right subtree with the updated min constraint
        Node* rightViolation = IsBSTHelper(node->right, node, maxNode, ancestors);
        if (rightViolation != nullptr) {
            ancestors.erase(node);  // Remove node from ancestors before returning
            return rightViolation;  // Found a violation in the right subtree
        }

        // If no violations found, return nullptr indicating the tree is valid
        return nullptr;
    }
};

#endif