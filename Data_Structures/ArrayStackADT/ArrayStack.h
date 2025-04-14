#pragma once
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "StackInterface.h"
#include <cassert>

namespace cs_stack {
    template<class ItemType>
    class ArrayStack : public StackInterface<ItemType>
    {
        private:
            static const int DEFAULT_CAPACITY = 1;
            ItemType* items;
            int numItems;
            int capacity;
    
        public:
             class StackEmptyError {};
             ArrayStack();//
             ArrayStack(const ArrayStack& other);//
             ~ArrayStack();//
             ArrayStack& operator=(const ArrayStack& other);//

             bool empty() const;//
             void push(const ItemType& newEntry);
             void pop();
             ItemType top() const;
    };



    /*
   Default constructor for ArrayStack.
   Initializes an empty stack with a default capacity.
   The stack starts with no items, and an array is allocated to hold future entries.
   */
    template<class ItemType>
    ArrayStack<ItemType>::ArrayStack() {
        // Initialize the stack to be empty
        numItems = 0;

        // Set the initial capacity to the default value
        capacity = DEFAULT_CAPACITY;

        // Dynamically allocate an array to hold stack items
        items = new ItemType[capacity];
    }

 /*
   Copy constructor for ArrayStack.
   Creates a deep copy of another ArrayStack, duplicating all items in the stack.
 */
    template<class ItemType>
    ArrayStack<ItemType>::ArrayStack(const ArrayStack& other) {
        // Copy the number of items and capacity from the other stack
        this->numItems = other.numItems;
        this->capacity = other.capacity;

        // Dynamically allocate an array for the new stack with the same capacity
        items = new ItemType[capacity];

        // Copy each item from the other stack to this stack
        for (int i = 0; i < numItems; i++) {
            items[i] = other.items[i];
        }
    }

    template<class ItemType>
    ArrayStack<ItemType>::~ArrayStack() {
        delete[] items;
    }

 /*
 Copy assignment operator for ArrayStack.
 Allows assignment of one ArrayStack to another by copying all items, capacity, and size.
 Ensures deep copying of the array and checks for self-assignment.
 */
    template<class ItemType>
    ArrayStack<ItemType>& ArrayStack<ItemType>::operator=(const ArrayStack& other) {
        // Check for self-assignment (if the same object is assigned to itself)
        if (this != &other) {
            // Deallocate the current array to avoid memory leaks
            delete[] items;

            // Copy the number of items and capacity from the other stack
            numItems = other.numItems;
            capacity = other.capacity;

            // Dynamically allocate a new array for the copied items
            items = new ItemType[capacity];

            // Copy each item from the other stack to this stack
            for (int i = 0; i < numItems; i++) {
                items[i] = other.items[i];
            }
        }
        // Return a reference to this stack
        return *this;
    }

    template<class ItemType>
    bool ArrayStack<ItemType>::empty() const {
        return numItems == 0;
    }






    template<class ItemType>
    void ArrayStack<ItemType>::push(const ItemType& newEntry) {
        if (numItems < capacity) {
            items[numItems] = newEntry;
            numItems++;
        }
        else if (numItems == capacity) {
            capacity = 2 * capacity;
            ItemType* newitems = new ItemType[capacity];

            for (int i = 0; i < numItems; i++) {
                newitems[i] = items[i];
            }
            delete[] items;
            items = newitems;
            
            items[numItems] = newEntry;
            numItems++;
        }
    }






    template<class ItemType>
    void ArrayStack<ItemType>::pop() {
        if (empty()) {
            throw StackEmptyError();
        }
        numItems--;
        if (capacity > 1) {
            if (numItems < capacity / 2) {
                capacity = capacity / 2;
                ItemType* newitems = new ItemType[capacity];

                for (int i = 0; i < numItems; i++) {
                    newitems[i] = items[i];
                }
                delete[] items;
                items = newitems;
            }
        }
    }





    template<class ItemType> 
    ItemType ArrayStack<ItemType>::top() const {
        if (!empty()) {
            return items[numItems - 1];
        } else {
            throw StackEmptyError();
        }
    }
}


#endif