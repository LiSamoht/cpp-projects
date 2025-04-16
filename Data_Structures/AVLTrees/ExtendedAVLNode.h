#pragma once
#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H
#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
private: 
    int subtreeKeyCount;
public: 
    ExtendedAVLNode(int nodekey) : AVLNode(nodekey) {
        subtreeKeyCount = 1;
    }

    virtual int GetSubtreeKeyCount() override {
        return subtreeKeyCount;
    }

    virtual void SetLeft(BSTNode* newLeftChild) override {
        AVLNode::SetLeft(newLeftChild);
        UpdateSubtreeKeyCount();
    }

    virtual void SetRight(BSTNode* newRightChild) override {
        AVLNode::SetRight(newRightChild);
        UpdateSubtreeKeyCount();
    }

    void UpdateSubtreeKeyCount() {
        subtreeKeyCount = 1;  // Start with this node

        // Add left subtree key count, if available
        if (GetLeft()) {
            // Cast only if we are sure GetLeft is ExtendedAVLNode
            ExtendedAVLNode* leftNode = dynamic_cast<ExtendedAVLNode*>(GetLeft());
            if (leftNode) {
                subtreeKeyCount += leftNode->GetSubtreeKeyCount();
            }
        }

        // Add right subtree key count, if available
        if (GetRight()) {
            // Cast only if we are sure GetRight is ExtendedAVLNode
            ExtendedAVLNode* rightNode = dynamic_cast<ExtendedAVLNode*>(GetRight());
            if (rightNode) {
                subtreeKeyCount += rightNode->GetSubtreeKeyCount();
            }
        }
    }
};


#endif



/*#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H

#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
private:
    int subtreeKeyCount;

        

public:
    ExtendedAVLNode(int nodeKey) : AVLNode(nodeKey) {
        subtreeKeyCount = 1;
    }

    virtual int GetSubtreeKeyCount() override {
        return subtreeKeyCount;
    }

};

#endif
*/