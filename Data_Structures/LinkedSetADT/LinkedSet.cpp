#include "Node.h"
#include "LinkedSet.h"
#include <cstddef>

namespace cs_set {

    template<class ItemType>
    LinkedSet<ItemType>::LinkedSet() {
        headPtr = nullptr;
        itemCount = 0;
    }

    /**
    Copies all elements from another LinkedSet to this LinkedSet.
    This is a private helper function that creates a deep copy
    of another LinkedSet's nodes.
    pre: aSet: The LinkedSet object to copy from
    post: The current LinkedSet will contain same elements
    as Aset in the same order, but as completely separate Node objects
 */
    template<class ItemType>
    void LinkedSet<ItemType>::copy(const LinkedSet<ItemType>& aSet) {
        itemCount = aSet.itemCount;
        Node<ItemType>* origChainPtr = aSet.headPtr;

        if (origChainPtr == nullptr) {
            headPtr = nullptr;
        }
        else {
            // Copy first node
            headPtr = new Node<ItemType>(origChainPtr->getItem());
            Node<ItemType>* newChainPtr = headPtr;
            origChainPtr = origChainPtr->getNext();

            // Copy remaining nodes
            while (origChainPtr != nullptr) {
                ItemType nextItem = origChainPtr->getItem();
                Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
                newChainPtr->setNext(newNodePtr);
                newChainPtr = newChainPtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }

            newChainPtr->setNext(nullptr);  // End the new chain
        }
    }


    /*
    Copy constructor that utilizes the copy() function to create a deep copy of aSet
    */
    template<class ItemType>
    LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {
        copy(aSet);
    }


    /*
     This function allows one LinkedSet object to be assigned the values of 
     another LinkedSet object. It first checks for self-assignment to avoid 
     unnecessary copying. If the objects are not the same, it clears the 
     current LinkedSet, then uses the private `copy()` function to deep copy 
     the elements of the right-hand-side (rhs) LinkedSet into this LinkedSet.
    */
    template<class ItemType>
    LinkedSet<ItemType>& LinkedSet<ItemType>::operator=(const LinkedSet<ItemType>& aSet) {
        if (this != &aSet) {  // Check for self-assignment
            clear();          // Clear current data
            copy(aSet);       // Copy data from the right-hand side
        }
        return *this;         // Return the updated object
    }


    template<class ItemType>
    LinkedSet<ItemType>::~LinkedSet() {
        clear();
    }





    template<class ItemType>
    bool LinkedSet<ItemType>::empty() const {
        return itemCount == 0;
    }





    template<class ItemType>
    int LinkedSet<ItemType>::size() const {
        return itemCount;
    }





    template<class ItemType>
    void LinkedSet<ItemType>::insert(const ItemType& newEntry) {
        if (contains(newEntry)) {
            throw DuplicateItemError();
        }
        Node<ItemType>* nextNodePtr = new Node<ItemType>();
        nextNodePtr->setItem(newEntry);
        nextNodePtr->setNext(headPtr);

        headPtr = nextNodePtr;          // New node is now first node
        itemCount++;
    }





    template<class ItemType>
    std::vector<ItemType> LinkedSet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        Node<ItemType>* curPtr = headPtr;
        while ((curPtr != nullptr)) {
            setContents.push_back(curPtr->getItem());
            curPtr = curPtr->getNext();
        }

        return setContents;
    }





    template<class ItemType>
    void LinkedSet<ItemType>::erase(const ItemType& anEntry) {
        Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
        if (entryNodePtr == nullptr) {
            throw ItemNotFoundError();
        }
        else {
            // replace data of node to delete with data from first node
            entryNodePtr->setItem(headPtr->getItem());

            // Delete first node
            Node<ItemType>* nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;

            itemCount--;
        }
    }





    template<class ItemType>
    void LinkedSet<ItemType>::clear() {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        while (headPtr != nullptr) {
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;
            nodeToDeletePtr = headPtr;
        }

        headPtr = nullptr;
        itemCount = 0;
    }





    template<class ItemType>
    int LinkedSet<ItemType>::count(const ItemType& anEntry) const {
        int frequency = 0;
        int counter = 0;
        Node<ItemType>* curPtr = headPtr;
        while ((curPtr != nullptr) && (counter < itemCount)) {
            if (anEntry == curPtr->getItem()) {
                frequency++;
            }

            counter++;
            curPtr = curPtr->getNext();
        }

        return frequency;
    }





    template<class ItemType>
    bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {
        return (getPointerTo(anEntry) != nullptr);
    }





    // private
    // Returns either a pointer to the node containing a given entry 
    // or nullptr if the entry is not in the set.

    template<class ItemType>
    Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& anEntry) const {
        bool found = false;
        Node<ItemType>* curPtr = headPtr;

        while (!found && (curPtr != nullptr)) {
            if (anEntry == curPtr->getItem()) {
                found = true;
            }
            else {
                curPtr = curPtr->getNext();
            }
        }

        return curPtr;
    }
    
    /*
     This function creates a new set that contains all unique elements from both
     the current set and the provided set `aSet`. Duplicates are avoided by 
     ensuring that no item is added twice.
    */
    template<class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setUnion(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> result;
        Node<ItemType>* thisChainPtr = this->headPtr;
        Node<ItemType>* resultChainPtr = result.headPtr; //IMPORTANT: don't initialize this to nullptr...resultChainPtr needs to be pointing to the same memory location as result!

        while (thisChainPtr != nullptr) {
            ItemType currItem = thisChainPtr->getItem();
            Node<ItemType>* newNode = new Node<ItemType>();
            newNode->setItem(currItem);

            if (result.headPtr == nullptr) {
                result.headPtr = newNode;
            }
            else {
                resultChainPtr->setNext(newNode);
            }
            resultChainPtr = newNode;
            result.itemCount++;  // Increment itemCount when adding an item
            thisChainPtr = thisChainPtr->getNext();
        }

        Node<ItemType>* aSetChainPtr = aSet.headPtr;
        while (aSetChainPtr != nullptr) {
            ItemType currItem = aSetChainPtr->getItem();
            if (!result.contains(currItem)) {  // Avoid adding duplicates
                Node<ItemType>* newNode = new Node<ItemType>();
                newNode->setItem(currItem);
                if (result.headPtr == nullptr) {
                    result.headPtr = newNode;
                }
                else {
                    resultChainPtr->setNext(newNode);
                }
                resultChainPtr = newNode;
                result.itemCount++;  // Increment itemCount here as well
            }
            aSetChainPtr = aSetChainPtr->getNext();
        }

        return result;
    }


    /*
     This function creates a new set that contains only the elements that are 
     present in both the current set and the provided set `aSet`.
    */
    template<class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setIntersection(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> result;
        Node<ItemType>* thisChainPtr = this->headPtr;
        Node<ItemType>* resultChainPtr = result.headPtr; 

        while (thisChainPtr != nullptr) {
            ItemType thisItem = thisChainPtr->getItem();
            if (aSet.contains(thisItem)) {
                Node<ItemType>* newNode = new Node<ItemType>();
                newNode->setItem(thisItem);

                if (result.headPtr == nullptr) {
                    result.headPtr = newNode;
                    result.itemCount++;
                }
                else {
                    resultChainPtr->setNext(newNode);
                    result.itemCount++;
                }
                resultChainPtr = newNode;
            }
            thisChainPtr = thisChainPtr->getNext();
        }
        return result;
   }
    

    /*
    This function creates a new set that contains only the elements that are 
    present in the current set but not in the provided set `aSet`.
    */
    template<class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setDifference(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> result;
        Node<ItemType>* thisChainPtr = this->headPtr;
        Node<ItemType>* resultChainPtr = result.headPtr;

        while (thisChainPtr != nullptr) {
            ItemType currItem = thisChainPtr->getItem();
            if (!(aSet.contains(currItem))) {
                Node<ItemType>* newNode = new Node<ItemType>();
                newNode->setItem(currItem);

                if (result.headPtr == nullptr) {
                    result.headPtr = newNode; // First item added
                    result.itemCount++;
                }
                else {
                    resultChainPtr->setNext(newNode); // Link the new node
                    result.itemCount++;
                }
                resultChainPtr = newNode; // Update resultChainPtr
            }
            thisChainPtr = thisChainPtr->getNext();
        }
        return result;
    }

}

