#pragma once
#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType>* nextPtr;

public:
    HashedEntry();
    HashedEntry(ItemType newEntry, KeyType searchKey);
    HashedEntry(ItemType newEntry, KeyType searchKey,
        HashedEntry<KeyType, ItemType>* nextEntryPtr);
    void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
    HashedEntry<KeyType, ItemType>* getNext() const;
};

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() 
{
    nextPtr = nullptr;
}

template<class KeyType, class ItemType> 
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey) 
    : Entry<KeyType, ItemType>(newEntry, searchKey)
{
    nextPtr = nullptr;
}


template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey, 
    HashedEntry<KeyType, ItemType>* nextEntryPtr)
    : Entry<KeyType, ItemType>(newEntry, searchKey)
{
    this->nextPtr = nextEntryPtr;
}



template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr) {
    nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const {
    return nextPtr;
}
#endif