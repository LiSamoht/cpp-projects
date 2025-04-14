#pragma once
/*

 This class implements the Set ADT using a dynamic array.
   The `ArraySet` class provides basic set operations including insertion,
   removal, membership checking, and conversion to a vector, all while ensuring
   that no duplicates are present.

   The class uses a fixed-capacity array, specified during construction.
   The array cannot resize dynamically, so attempting to insert more items
   than the current capacity allows will result in a `CapacityExceededError` exception.
   Duplicate entries are not permitted; an attempt to insert a duplicate
   will result in a `DuplicateItemError`. Similarly, trying to remove
   an item that is not present in the set will throw an `ItemNotFoundError`.

   Exceptions:
   - `CapacityExceededError`: Thrown if an insertion is attempted when the set is full.
   - `DuplicateItemError`: Thrown if an insertion is attempted with a duplicate entry.
   - `ItemNotFoundError`: Thrown if an attempt is made to erase an item that does not exist in the set.

   Key Member Functions:

   1. `size`:
      - Returns the number of entries currently in the Set.
      - post: The number of items in the set is returned.

   2. `empty`:
      - Checks if the Set is empty.
      - post: Returns true if the set contains no items, false otherwise.

   3. `insert`:
      - Inserts a new entry into this Set. The set does not allow duplicates.
      - post: If the insertion is successful, `newEntry` is added to the set and
              the size of the set is increased by 1.
              If the set is full, `CapacityExceededError` is thrown.
              If `newEntry` is already in the set, `DuplicateItemError` is thrown.

   4. `erase`:
      - Removes the given entry from the Set, if it exists.
      - post: If successful, the specified entry is removed and the size is reduced by 1.
              If the entry is not found, `ItemNotFoundError` is thrown.

   5. `clear`:
      - Removes all items from the Set.
      - post: The Set becomes empty, and the size is set to 0.

   6. `count`:
      - Returns the number of times the given entry appears in the Set.
      - post: Returns 1 if the entry exists in the Set, 0 if it does not.

   7. `contains`:
      - Checks if the Set contains the given entry.
      - post: Returns true if the entry is found in the Set, false otherwise.

   8. `toVector`:
      - Converts the Set into a vector of all the items.
      - post: Returns a vector containing all the entries currently in the Set.

   9. Destructor:
      - Cleans up the dynamically allocated memory used by the Set.
      - post: The Set is destroyed and its allocated memory is deallocated.

*/
#ifndef ARRAY_SET_H
#define ARRAY_SET_H

#include "SetInterface.h"

namespace cs_set {

    template<class ItemType>
    class SetInterface;

    template<class ItemType>
    class ArraySet : public SetInterface<ItemType>
    {
    public:
        class CapacityExceededError {};
        class ItemNotFoundError {};
        class DuplicateItemError {};

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
        ArraySet<ItemType> setUnion(const ArraySet<ItemType>& other);
        ArraySet<ItemType> setIntersection(const ArraySet<ItemType>& other);
        ArraySet<ItemType> setDifference(const ArraySet<ItemType>& other);

    private:
        static const int DEFAULT_CAPACITY = 6;
        ItemType* items;
        int numItems;
        int capacity;

        int getIndexOf(const ItemType& target) const;
    };
}
#endif
