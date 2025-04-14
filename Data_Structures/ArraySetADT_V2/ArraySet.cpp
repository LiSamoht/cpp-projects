#include "ArraySet.h"
#include <vector>

namespace cs_set {
    /*
    Constructor that initializes an ArraySet with the specified capacity. The set starts empty,
    and memory is allocated dynamically to hold the entries. newcapacity is the number of items the new
    set can hold.
    post: The ArraySet is initialized with the given capacity, no items are added initially,
          and the internal array is dynamically allocated to store up to 'newcapacity' items.
    */
    template<class ItemType>
    ArraySet<ItemType>::ArraySet(int newcapacity) {
        capacity = newcapacity;
        numItems = 0;
        items = new ItemType[capacity];
    }

    /*
    Copy assignment operator that makes a deep copy of the entries.
     Parameters:
    - right: The ArraySet being assigned to the current object.

    post: The current ArraySet is assigned the same entries and capacity as 'right'.
          All items in 'right' are copied into the current object, and any previously
          allocated memory for the current object is deallocated to avoid memory leaks.
          If 'right' and the current object are the same, no operation is performed.
    */
    template<class ItemType>
    ArraySet<ItemType>& ArraySet<ItemType>::operator=(const ArraySet<ItemType>& right) {
        if (this != &right) { //avoid self assignment issues
            delete[] items;

            capacity = right.capacity; //initial assignment
            numItems = right.numItems;
            items = new ItemType[capacity]; //allocate memory for deep copy

            for (int i = 0; i < numItems; i++) { //create deep copy.
                items[i] = right.items[i];
            }
        }
        return *this;
    }


    /*
    Copy Constructor that constructs a new ArraySet by making a deep copy of another ArraySet.
    Parameters:
    - other: The ArraySet to be copied.

    post: The new ArraySet contains the same items and capacity as 'other',
          with its own dynamically allocated memory. All items from 'other'
          are copied to the new ArraySet.
    */
    template<class ItemType>
    ArraySet<ItemType>::ArraySet(const ArraySet<ItemType>& other) {
        capacity = other.capacity;
        numItems = other.numItems;
        items = new ItemType[capacity];

        for (int i = 0; i < numItems; i++) {
            items[i] = other.items[i];
        }
    }


    /*
    Destructor that deallocates the dynamically allocated memory used to store the items in the ArraySet.

    post: The internal array holding the set items is deleted, freeing memory resources
          used by the set.
    */
    template<class ItemType>
    ArraySet<ItemType>::~ArraySet() {
        delete[] items;
    }

    template<class ItemType>
    void ArraySet<ItemType>::insert(const ItemType& newEntry) {
        {
            if (contains(newEntry)) {
                throw DuplicateItemError();
            }

            if (numItems >= capacity) {
                throw CapacityExceededError();
            }

            items[numItems] = newEntry;
            numItems++;
        }

    }




    template<class ItemType>
    int ArraySet<ItemType>::size() const {
        return numItems;
    }





    template<class ItemType>
    bool ArraySet<ItemType>::empty() const {
        return numItems == 0;
    }




    template<class ItemType>
    std::vector<ItemType> ArraySet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        for (int i = 0; i < numItems; i++) {
            setContents.push_back(items[i]);
        }

        return setContents;
    }




    template <class ItemType>
    bool ArraySet<ItemType>::contains(const ItemType& anEntry) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == anEntry) {
                return true;
            }
        }
        return false;
    }





    template<class ItemType>
    void ArraySet<ItemType>::clear() {
        numItems = 0;
    }





    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.

    template<class ItemType>
    int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == target) {
                return i;
            }
        }

        return -1;
    }






    template<class ItemType>
    void ArraySet<ItemType>::erase(const ItemType& anEntry) {

        int locatedIndex = getIndexOf(anEntry);
        if (locatedIndex > -1) {
            numItems--;
            items[locatedIndex] = items[numItems];
        }
        else {
            throw ItemNotFoundError();
        }
    }







    template<class ItemType>
    int ArraySet<ItemType>::count(const ItemType& anEntry) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == anEntry) {
                return 1;
            }
        }
        return 0;
    }


    /*
     * Union of Two Sets:
     *
     * This method creates a new set containing all unique items that are present in either of the
     * two sets. It performs the union operation using the calling set as the first operand and the
     * provided set as the second operand.
     *
     * post: Returns a new ArraySet containing all distinct items from both the calling set and
     *       the provided set. If the result exceeds the capacity of the ArraySet, a CapacityExceededError
     *       is thrown.
     */
    template<class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setUnion(const ArraySet<ItemType>& other) {
        ArraySet<ItemType> result(DEFAULT_CAPACITY);

        for (int i = 0; i < numItems; i++) {
            result.insert(items[i]);
        }

        for (int i = 0; i < other.numItems; i++) {
            if (!result.contains(other.items[i])) {
                result.insert(other.items[i]);
            }
        }

        if (result.numItems > result.capacity) {
            throw CapacityExceededError();
        }

        return result;
    }

    /*
     * Intersection of Two Sets:
     *
     * This method creates a new set containing only the items that are present in both the calling
     * set and the provided set. It performs the intersection operation using the calling set as the
     * first operand and the provided set as the second operand.
     *
     * post: Returns a new ArraySet containing only the items that are present in both the calling
     *       set and the provided set.
     *
     */
    template<class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setIntersection(const ArraySet<ItemType>& other) {
        ArraySet<ItemType> result(DEFAULT_CAPACITY);

        // Iterate through the items in the current set (this)
        for (int i = 0; i < numItems; i++) {
            // If an item exists in both sets, insert it into the result set
            if (other.contains(items[i])) {
                result.insert(items[i]);
            }
        }

        return result;
    }

    /*
     * Difference of Two Sets:
     *
     * This method creates a new set containing items that are present in the calling set but not
     * in the provided set. It performs the difference operation using the calling set as the first
     * operand and the provided set as the second operand.
     *
     * post: Returns a new ArraySet containing the items that are in the calling set but not in the
     *       provided set.
     *
     */
    template<class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setDifference(const ArraySet<ItemType>& other) {
        ArraySet<ItemType> result(DEFAULT_CAPACITY);

        // Add all items from the calling set to the result
        for (int i = 0; i < numItems; i++) {
            result.insert(items[i]);
        }

        // Remove items that are also in the provided set
        for (int i = 0; i < numItems; i++) {
            if (other.contains(items[i])) {
                result.erase(items[i]);
            }
        }

        return result;
    }

}