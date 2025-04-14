#pragma once
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"
#include <iostream>

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
public:
    ArrayQueue();
    ArrayQueue(const ArrayQueue& other);
    ~ArrayQueue();
    ArrayQueue& operator=(const ArrayQueue& other);

    bool empty() const;
    void push(const ItemType& newEntry);
    void pop();
    ItemType front() const;
    void print() const;
private:
    static const int DEFAULT_CAPACITY = 1;
    int capacity;
    ItemType* items;
    int qfront;
    int back;
    int numItems;
};




template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    capacity = DEFAULT_CAPACITY;
    items = new ItemType[capacity];
    qfront = 0;
    back = capacity - 1; //0
    numItems = 0;
}




/*
The copy constructor creates a new ArrayQueue instance as a copy of an existing 
ArrayQueue object. It allocates memory for a new array and copies all relevant
properties and items from the other queue, ensuring that the new queue maintains
the same circular structure.
*/
template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue& other) {
    capacity = other.capacity;
    qfront = other.qfront;
    back = other.back;
    numItems = other.numItems;
    items = new ItemType[capacity];
    for (int i = qfront; i != back; i = (i + 1) % capacity) {
        items[i] = other.items[i];
    }
}


/*
The destructor releases any dynamically allocated memory used by the ArrayQueue instance.
It ensures that when a queue object goes out of scope, its associated resources are properly 
cleaned up, preventing memory leaks.
*/
template<class ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {
    delete[] items;
}



/*
The assignment operator allows for the assignment of one ArrayQueue object to another. 
It first checks for self-assignment, then frees any existing memory held by the current
object. It then allocates new memory for the array and copies the properties and items 
from the other queue.
*/
template<class ItemType>
ArrayQueue<ItemType>& ArrayQueue<ItemType>::operator=(const ArrayQueue<ItemType>& other) {
    if (this != &other) {
        delete[] items;
        capacity = other.capacity;
        qfront = other.qfront;
        back = other.back;
        numItems = other.numItems;
        items = new ItemType[capacity];
        for (int i = qfront; i != back; i = (i + 1) % capacity) {
            items[i] = other.items[i];
        }
    }
    return *this;
}




template<class ItemType>
bool ArrayQueue<ItemType>::empty() const {
    return numItems == 0;
}





template<class ItemType>
void ArrayQueue<ItemType>::push(const ItemType& newEntry)
{
    if (numItems == capacity) {
        int newcapacity = capacity * 2;
        ItemType* newItems = new ItemType[newcapacity];
        for (int i = 0; i < numItems; i++) {
            newItems[i] = items[(qfront + i) % capacity];
        }
        delete[] items;
        items = newItems;
        capacity = newcapacity;
        qfront = 0;
        back = numItems;
    }
    items[back] = newEntry;
    back = (back + 1) % capacity;
    numItems++;
}





template<class ItemType>
void ArrayQueue<ItemType>::pop()
{
    if (empty()) {
        throw PrecondViolatedExcep();
    }

    qfront = (qfront + 1) % capacity;
    numItems--;

    if (numItems < capacity / 2 && capacity > DEFAULT_CAPACITY) {
        int newcapacity = capacity / 2; 
        ItemType* newItems = new ItemType[newcapacity];
        for (int i = 0; i < numItems; i++) {
            newItems[i] = items[(qfront + i) % capacity];
        }
        delete[] items;
        items = newItems;
        qfront = 0;
        back = numItems;
    }
}




template<class ItemType>
ItemType ArrayQueue<ItemType>::front() const
{
    if (empty()) {
        throw PrecondViolatedExcep("peekFront() called with empty queue");
    }

    return items[qfront];
}





template<class ItemType>
void ArrayQueue<ItemType>::print() const {
    std::cout << "Here is the queue: ";
    if (empty()) {
        std::cout << "empty";
    }
    else {
        for (int i = qfront; i != back; i = (i + 1) % capacity) {
            std::cout << items[i] << " ";
        }
        std::cout << items[back];
    }
}


#endif