namespace cs_bag {

    template<class ItemType>
    void ArrayBag<ItemType>::insert(const ItemType& newEntry) {
        if (numItems >= capacity) {
            throw CapacityExceededError();
        }
        else {
            items[numItems] = newEntry;
            numItems++;
        }
    }




    template<class ItemType>
    ArrayBag<ItemType>::ArrayBag() {
        numItems = 0;
        capacity = DEFAULT_CAPACITY;
    }





    template<class ItemType>
    int ArrayBag<ItemType>::size() const {
        return numItems;
    }





    template<class ItemType>
    bool ArrayBag<ItemType>::empty() const {
        return numItems == 0;
    }




    template<class ItemType>
    std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
        std::vector<ItemType> bagContents;
        for (int i = 0; i < numItems; i++) {
            bagContents.push_back(items[i]);
        }

        return bagContents;
    }




    template <class ItemType>
    bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == anEntry) {
                return true;
            }
        }
        return false;
    }





    template<class ItemType>
    void ArrayBag<ItemType>::clear() {
        numItems = 0;
    }





    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.

    template<class ItemType>
    int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
        for (int i = 0; i < numItems; i++) {
            if (items[i] == target) {
                return i;
            }
        }

        return -1;
    }






    template<class ItemType>
    void ArrayBag<ItemType>::erase(const ItemType& anEntry) {
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
    int ArrayBag<ItemType>::count(const ItemType& anEntry) const {
        int frequency = 0;
        int curIndex = 0;
        while (curIndex < numItems) {
            if (items[curIndex] == anEntry) {
                frequency++;
            }
            curIndex++;
        }

        return frequency;
    }
}