#pragma once
#ifndef QUEUE_INTERFACE_
#define QUEUE_INTERFACE_

template<class ItemType>
class QueueInterface

{
public:
    // returns True if the queue is empty, or false if not. */
    virtual bool empty() const = 0;

    /** Adds a new entry to the back of this queue.
     @post If the operation was successful, newEntry is at the
        back of the queue.
     @param newEntry  The object to be added as a new entry.
     @return True if the addition is successful or false if not. */
    virtual void push(const ItemType& newEntry) = 0;

    /** Removes the front of this queue.
     @post If the operation was successful, the front of the queue
        has been removed.
     @return True if the removal is successful or false if not. */
    virtual void pop() = 0;

    /** Returns the front of this queue.
     @pre The queue is not empty.
     @post The front of the queue has been returned, and the
        queue is unchanged.
     @return The front of the queue. */
    virtual ItemType front() const = 0;


    /** Destroys object and frees memory allocated by object. */
    virtual ~QueueInterface() { }
};
#endif