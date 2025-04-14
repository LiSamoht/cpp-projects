#pragma once
#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <string>
// provide the HashedDictionary class declaration
template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType>** hashTable; // Array of pointers to entries
    int itemCount; // Count of dictionary entries
    int hashTableSize; // Table size must be prime
    static const int DEFAULT_SIZE = 101;
    void copyTable(const HashedDictionary& other);
    
    class NotFoundException{};
public: 
    HashedDictionary();
    HashedDictionary(const HashedDictionary<KeyType, ItemType>& other);
    ~HashedDictionary();
    HashedDictionary& operator=(const HashedDictionary<KeyType, ItemType>& other);

    int getHashIndex(const KeyType& searchKey) const;
    bool add(const KeyType& searchKey, const ItemType& newItem) override;//
    bool remove(const KeyType& searchKey) override;//
    bool isEmpty() const override; //
    int getNumberOfItems() const override; //
    void clear() override;
    ItemType getItem(const KeyType& searchKey) const override;
    bool contains(const KeyType& searchKey) const override;
};

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary() {
    itemCount = 0;
    hashTableSize = DEFAULT_SIZE;
    hashTable = new HashedEntry<KeyType, ItemType>*[hashTableSize]();
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const HashedDictionary<KeyType, ItemType>& other) {
    copyTable(other);
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::copyTable(const HashedDictionary& other) {
    itemCount = other.itemCount;
    hashTableSize = other.hashTableSize;
    hashTable = new HashedEntry<KeyType, ItemType>* [hashTableSize]();

    for (int i = 0; i < hashTableSize; i++) {
        if (other.hashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType>* otherPtr = other.hashTable[i];
            hashTable[i] = new HashedEntry<KeyType, ItemType>(otherPtr->getItem(), otherPtr->getKey());  // Deep copy the first entry
            HashedEntry<KeyType, ItemType>* thisEntryPtr = hashTable[i];

            otherPtr = otherPtr->getNext();
            while (otherPtr != nullptr) {
                HashedEntry<KeyType, ItemType>* newEntryPtr = new HashedEntry<KeyType, ItemType>(otherPtr->getItem(), otherPtr->getKey());
                thisEntryPtr->setNext(newEntryPtr);
                thisEntryPtr = newEntryPtr;
                otherPtr = otherPtr->getNext();
            }
            thisEntryPtr->setNext(nullptr);
        }
    }
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>& HashedDictionary<KeyType, ItemType>::operator=(const HashedDictionary<KeyType, ItemType>& other) {
    if (this != &other) {
        clear();
        delete[] hashTable;

        itemCount = 0;
        hashTableSize = other.hashTableSize;
        hashTable = new HashedEntry<KeyType, ItemType>* [hashTableSize]();

        copyTable(other);
    }
    return *this;
}


template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    clear();
    delete[] hashTable;
}


template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    for (int i = 0; i < hashTableSize; i++) {
        HashedEntry<KeyType, ItemType>* currEntry = hashTable[i];
        while (currEntry != nullptr) {
            HashedEntry<KeyType, ItemType>* tempEntry = currEntry;
            currEntry = currEntry->getNext();
            delete tempEntry;
        }
        hashTable[i] = nullptr;
    }
    itemCount = 0;
}


template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& searchKey) const {
    int hashIndex = 0;
    for (size_t i = 0; i < searchKey.size(); i++) {
        hashIndex += searchKey[i];
    }

    return hashIndex % hashTableSize;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const {
    int hashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType>* currEntry = hashTable[hashIndex];

    while (currEntry != nullptr) {
        if (currEntry->getKey() == searchKey) {
            return currEntry->getItem();
        }
        currEntry = currEntry->getNext();
    }

    throw NotFoundException();
}


template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const {
    int hashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType>* currEntry = hashTable[hashIndex];

    while (currEntry != nullptr) {
        if (currEntry->getKey() == searchKey) {
            return true;
        }
        currEntry = currEntry->getNext();
    }
    return false;
}

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
    // Create entry to add to dictionary
    HashedEntry<KeyType, ItemType>* entryToAddPtr =
        new HashedEntry<KeyType, ItemType>(newItem, searchKey);

    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);

    // Add the entry to the chain at itemHashIndex
    if (hashTable[itemHashIndex] == nullptr)
    {
        hashTable[itemHashIndex] = entryToAddPtr;
    }
    else
    {
        entryToAddPtr->setNext(hashTable[itemHashIndex]);
        hashTable[itemHashIndex] = entryToAddPtr;
    }

    itemCount++;
    return true;
}






template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
    bool itemFound = false;

    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    if (hashTable[itemHashIndex] != nullptr)
    {
        // Special case - first node has target
        if (searchKey == hashTable[itemHashIndex]->getKey())
        {
            HashedEntry<KeyType, ItemType>* entryToRemovePtr =
                hashTable[itemHashIndex];
            hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
            delete entryToRemovePtr;

            itemCount--;
            itemFound = true;
        }
        else // Search the rest of the chain
        {
            HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
            HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
            while ((curPtr != nullptr) && !itemFound)
            {
                // Found item in chain so remove that node
                if (searchKey == curPtr->getKey())
                {
                    prevPtr->setNext(curPtr->getNext());
                    delete curPtr;

                    itemCount--;
                    itemFound = true;
                }
                else // Look at next entry in chain
                {
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
            }
        }
    }

    return itemFound;
}