#ifndef LINKED_SET
#define LINKED_SET

#include "SetInterface.h"
#include "Node.cpp"

namespace cs_set {

    template<class ItemType>
    class LinkedSet : public SetInterface<ItemType>
    {
    public:
        class ItemNotFoundError {};
        class DuplicateItemError {};

        LinkedSet();
        LinkedSet(const LinkedSet<ItemType>& aSet);
        virtual ~LinkedSet();

        LinkedSet<ItemType>& operator= (const LinkedSet<ItemType>& aSet);

        int size() const;
        bool empty() const;
        void insert(const ItemType& newEntry);
        void erase(const ItemType& anEntry);
        void clear();
        bool contains(const ItemType& anEntry) const;
        int count(const ItemType& anEntry) const;
        std::vector<ItemType> toVector() const;

        LinkedSet<ItemType> setUnion(const LinkedSet<ItemType>& aSet) const;
        LinkedSet<ItemType> setIntersection(const LinkedSet<ItemType>& aSet) const;
        LinkedSet<ItemType> setDifference(const LinkedSet<ItemType>& aSet) const;

    private:
        Node<ItemType>* headPtr;
        int itemCount;

        // Returns either a pointer to the node containing a given entry
        // or nullptr if the entry is not in the set.
        Node<ItemType>* getPointerTo(const ItemType& target) const;
        void copy(const LinkedSet<ItemType>& aSet);
    };
}
#endif