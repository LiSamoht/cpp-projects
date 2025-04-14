#pragma once
#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry {
private:
    ItemType item;
    KeyType searchKey;

protected:
    void setKey(const KeyType& searchKey);

public:
    Entry();
    Entry(ItemType newEntry, KeyType searchKey);
    ItemType getItem() const;
    KeyType getKey() const;
    void setItem(const ItemType& newEntry);
};

template<class KeyType, class ItemType>
void Entry<KeyType,ItemType>::setKey(const KeyType& searchKey) {
    this->searchKey = searchKey;
}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry() {
    this->item = ItemType();
    this->searchKey = KeyType();
}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType searchKey) {
    this->item = newEntry;
    this->searchKey = searchKey;
}

template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const {
    return this->item;
}

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const {
    return searchKey;
}

template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newEntry) {
    item = newEntry;
}

#endif