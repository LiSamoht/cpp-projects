#pragma once
#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

/* precondition for setFirst and setSecond: the argument cannot be such that the values of
first and second will become equal, unless the argument is equal to DEFAULT_VALUE.
*/


namespace cs_pairs {

    template<typename T>
    class OrderedPair {
    public:

        
        static const T DEFAULT_VALUE;
        
        OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
        
        void setFirst(T newFirst);
        void setSecond(T newSecond);

        T getFirst() const;
        T getSecond() const;

        OrderedPair<T> operator+(const OrderedPair<T>& right) const;
        bool operator<(const OrderedPair<T>& right) const;
        void print() const;

        class DuplicateMemberError {};
    private:
        T first;
        T second;
    };
}

#endif