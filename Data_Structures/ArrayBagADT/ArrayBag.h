#pragma once
/*

Header file for an array-based implementation of the ADT bag.

*/

#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include "BagInterface.h"

namespace cs_bag {
    template<class ItemType>
    class ArrayBag : public BagInterface<ItemType>
    {
    public:
        class CapacityExceededError {};
        class ItemNotFoundError {};

        ArrayBag();
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
        ItemType items[DEFAULT_CAPACITY];
        int numItems;
        int capacity;

        int getIndexOf(const ItemType& target) const;
    };
}

#include "ArrayBag.cpp"
#endif