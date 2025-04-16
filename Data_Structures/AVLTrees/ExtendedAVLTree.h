#pragma once
#ifndef EXTENDEDAVLTREE_H
#define EXTENDEDAVLTREE_H

#include "AVLTree.h"
#include "ExtendedAVLNode.h"

class ExtendedAVLTree : public AVLTree {
protected:
    // Each node in an ExtendedAVLTree is an ExtendedAVLNode
    virtual BSTNode* MakeNewNode(int key) override {
        return new ExtendedAVLNode(key);
    }

    virtual void InsertNode(BSTNode* node) override {
        AVLTree::InsertNode(node);

        BSTNode* currNode = node;
        while (currNode) {
            ExtendedAVLNode* extended = dynamic_cast<ExtendedAVLNode*>(currNode);
            if (extended) {
                extended->UpdateSubtreeKeyCount();
            }
            currNode = currNode->GetParent();
        }

        // Rebalance starting from the parent of the inserted node
        currNode = node;
        BSTNode* parent = currNode->GetParent();
        while (parent) {
            // Safely cast to AVLNode and rebalance if needed
            AVLNode* avlParent = dynamic_cast<AVLNode*>(parent);
            if (avlParent) {
                Rebalance(avlParent);  // Perform rebalance on the AVLNode
            }
            parent = parent->GetParent();
        }
    }

    virtual bool RemoveNode(BSTNode* nodeToRemove) override {
        if (!nodeToRemove) {
            return false;
        }

        // Parent needed for rebalancing and updating subtreeKeyCount.
        BSTNode* parent = nodeToRemove->GetParent();

        // Case 1: Internal node with 2 children
        if (nodeToRemove->GetLeft() && nodeToRemove->GetRight()) {
            // Find the in-order successor (smallest node in the right subtree)
            BSTNode* successorNode = nodeToRemove->GetRight();
            while (successorNode->GetLeft()) {
                successorNode = successorNode->GetLeft();
            }

            // Copy the key from the successor
            nodeToRemove->SetKey(successorNode->GetKey());

            // Now remove the successor node (which will be a leaf or have one child)
            RemoveNode(successorNode);

            // Rebalance the tree and update subtreeKeyCount for affected nodes
            RecountAndRebalance(parent);
            return true;
        }

        // Case 2: Root node (with 1 or 0 children)
        else if (nodeToRemove == root) {
            if (nodeToRemove->GetLeft()) {
                root = (AVLNode*)nodeToRemove->GetLeft();
            }
            else {
                root = (AVLNode*)nodeToRemove->GetRight();
            }

            if (root) {
                root->SetParentToNull();
            }

            // Delete the node and update subtree key counts and rebalance
            delete nodeToRemove;
            RecountAndRebalance(parent);
            return true;
        }

        // Case 3: Node with left child only
        else if (nodeToRemove->GetLeft()) {
            parent->ReplaceChild(nodeToRemove, nodeToRemove->GetLeft());
            delete nodeToRemove;
            RecountAndRebalance(parent);
            return true;
        }

        // Case 4: Node with right child only OR leaf node
        else {
            parent->ReplaceChild(nodeToRemove, nodeToRemove->GetRight());
            delete nodeToRemove;
            RecountAndRebalance(parent);
            return true;
        }
    }

private:
    void RecountAndRebalance(BSTNode* startNode) {
        // Traverse back up the tree, updating subtreeKeyCounts and rebalancing
        BSTNode* currNode = startNode;
        while (currNode) {
            // Safely cast to ExtendedAVLNode to access subtreeKeyCount
            ExtendedAVLNode* extendedNode = dynamic_cast<ExtendedAVLNode*>(currNode);
            if (extendedNode) {
                extendedNode->UpdateSubtreeKeyCount();  // Update the subtreeKeyCount
            }

            // Rebalance if needed (we do it here instead of within RemoveNode to ensure
            // subtreeKeyCount is updated before any rebalancing)
            AVLNode* avlNode = dynamic_cast<AVLNode*>(currNode);
            if (avlNode) {
                Rebalance(avlNode);  // Perform rebalancing if needed
            }

            // Move to the parent node
            currNode = currNode->GetParent();
        }
    }
public:
    virtual int GetNthKey(int n) override {
        ExtendedAVLNode* curr = dynamic_cast<ExtendedAVLNode*>(this->root);

        
        while (curr) {
            int leftSize = 0;
            if (curr->GetLeft()) {
                leftSize = dynamic_cast<ExtendedAVLNode*>(curr->GetLeft())->GetSubtreeKeyCount();
           }

            if (n < leftSize) { //the desired key is in the left subtree.
                curr = dynamic_cast<ExtendedAVLNode*>(curr->GetLeft());
            }
            else if (n == leftSize) { 
                //found the node (There are "n" nodes before curr, but if indexing from 0 to n, that means that we seek the (n+1)th node).
                //Thus, adding on curr to the subtree gives that node.
                return curr->GetKey();
            }
            else if (n > leftSize) { //the desired key is in the right subtree, update n
                n = n - (leftSize + 1); //subtract off all the nodes in the left subtree, and the current node because we know the nth node can't be one of them.
                curr = dynamic_cast<ExtendedAVLNode*>(curr->GetRight());
            }
        }
        return 0;
    }
};

#endif