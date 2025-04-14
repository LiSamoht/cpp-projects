#pragma once
/*

Header file for an array-based implementation of the ADT bag.

*/
#ifndef ARRAY_SET_H
#define ARRAY_SET_H

#include "SetInterface.h"
#include <stdexcept>


namespace cs_set {
    template<class ItemType>
    class ArraySet : public SetInterface<ItemType>
    {
    public:
        class CapacityExceededError : public std::exception {};
        class ItemNotFoundError : public std::exception {};
        class DuplicateItemError : public std::exception {};

        ArraySet(int newcapacity = DEFAULT_CAPACITY);
        ArraySet(const ArraySet<ItemType>& other);
        
        ArraySet<ItemType>& operator=(const ArraySet<ItemType>& right);
        ~ArraySet();

        int size() const;
        bool empty() const;
        void insert(const ItemType& newEntry);
        void erase(const ItemType& anEntry);
        void clear();
        bool contains(const ItemType& anEntry) const;
        int count(const ItemType& anEntry) const;
        std::vector<ItemType> toVector() const;
    private:
        static const int DEFAULT_CAPACITY = 6;
        ItemType* items;
        int numItems;
        int capacity;

        int getIndexOf(const ItemType& target) const;
    };
}
#include "ArraySet.cpp"
#endif