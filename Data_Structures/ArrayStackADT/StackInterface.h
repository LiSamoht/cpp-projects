#pragma once
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

namespace cs_stack {
    template<class ItemType>
    class StackInterface
    {
    public:

        /** Sees whether this stack is empty.
         @return  True if the stack is empty, or false if not.
        */
        virtual bool empty() const = 0;


        /** Adds a new entry to the top of this stack.
             @post  If the operation was successful, newEntry is at the top of the stack.
             @param newEntry  The object to be added as a new entry.
             @throws CapacityExceededError if entry cannot be pushed because stack is full.
        */
        virtual void push(const ItemType& newEntry) = 0;


        /** Removes the top of this stack.
            @post  If the operation was successful, the top of the stack has been removed.
            @throws StackEmptyError if stack is empty.
        */
        virtual void pop() = 0;


        /** Returns a copy of the top of this stack.
            @pre  The stack is not empty.
            @post  A copy of the top of the stack has been returned, and the stack is unchanged.
            @return  A copy of the top of the stack.
            @throws StackEmptyError if stack is empty.
        */
        virtual ItemType top() const = 0;


        /** Destroys this stack and frees its assigned memory.
        */
        virtual ~StackInterface() { }
    };
}

#endif