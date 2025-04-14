namespace cs_set {

    template<class ItemType>
    ArraySet<ItemType>::ArraySet(int newcapacity) {
        capacity = newcapacity;
        numItems = 0;
        items = new ItemType[capacity];
    }

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

    template<class ItemType>
    ArraySet<ItemType>::ArraySet(const ArraySet<ItemType>& other) {
        capacity = other.capacity;
        numItems = other.numItems;
        items = new ItemType[capacity];

        for (int i = 0; i < numItems; i++) {
            items[i] = other.items[i];
        }
    }

    template<class ItemType>
    ArraySet<ItemType>::~ArraySet() {
        delete[] items;
    }

    template<class ItemType>
    void ArraySet<ItemType>::insert(const ItemType& newEntry) {
        try
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
        catch (...)
        {
            //ignore
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
        try {
            int locatedIndex = getIndexOf(anEntry);
            if (locatedIndex > -1) {
                numItems--;
                items[locatedIndex] = items[numItems];
            }
            else {
                throw ItemNotFoundError();
            }
        }
        catch (...) {
            //ignore
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
}