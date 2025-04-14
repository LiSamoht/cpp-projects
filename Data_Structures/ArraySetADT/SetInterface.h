#pragma once
/*

   This class is to be used as an interface class for implementation
   of a Bag ADT.


   // post: Returns the number of entries currently in the Bag.
   virtual int size() const = 0;



   // post: Returns true if the Bag is empty, or false if not.
   virtual bool empty() const = 0;



   // Inserts a new entry into this Bag.
   // post:  If successful, newEntry is stored in the Bag and
   //        the count of items in the Bag has increased by 1.
   //        Otherwise, throws an appropriate exception
   //        (CapacityExceededError).

   virtual void insert(const ItemType& newEntry) = 0;



   // Erases the given entry from this Set, if it exists.
   // post: If successful, anEntry has been removed from the Bag.
   //       Otherwise, throws an ItemNotFoundError

   virtual void erase(const ItemType& anEntry) = 0;



   // Erases all items from this Bag.
   // post: the Bag is empty, and the count of items is 0.

   virtual void clear() = 0;



   // post: Returns the number of times anEntry appears in the Bag

   virtual int count(const ItemType& anEntry) const = 0;



   // post: Returns true if Bag contains anEntry, or false otherwise.

   virtual bool contains(const ItemType& anEntry) const = 0;



   // post: Returns a vector containing all the entries in the Bag.

   virtual std::vector<ItemType> toVector() const = 0;



   // post: This Bag has been destroyed and its assigned memory deallocated.

   virtual ~BagInterface() { }
*/


#ifndef SET_INTERFACE
#define SET_INTERFACE
#include <vector>


namespace cs_set {
    template<class ItemType>    
    class SetInterface
    {
    public:
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual void insert(const ItemType& newEntry) = 0;
        virtual void erase(const ItemType& anEntry) = 0;
        virtual void clear() = 0;
        virtual int count(const ItemType& anEntry) const = 0;
        virtual bool contains(const ItemType& anEntry) const = 0;
        virtual std::vector<ItemType> toVector() const = 0;
        virtual ~SetInterface() { }
    };
}
#endif