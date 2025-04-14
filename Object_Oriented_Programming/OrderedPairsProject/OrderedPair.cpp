#include "OrderedPair.h"
#include <iostream>
using namespace std;

namespace cs_pairs {

    template<typename T>
    const T OrderedPair<T>::DEFAULT_VALUE = T();


    template<typename T>
    OrderedPair<T>::OrderedPair(T newFirst, T newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }

    template<typename T>
    void OrderedPair<T>::setFirst(T newFirst) {
        if (newFirst == second && newFirst != DEFAULT_VALUE) {
            throw DuplicateMemberError();
        }
        first = newFirst;
    }

    template<typename T>
    void OrderedPair<T>::setSecond(T newSecond) {
        if (newSecond == first && newSecond != DEFAULT_VALUE) {
            throw DuplicateMemberError();
        }
        second = newSecond;
    }

    template<typename T>
    T OrderedPair<T>::getFirst() const {
        return first;
    }
    
    template<typename T>
    T OrderedPair<T>::getSecond() const {
        return second;
    }
    
    template<typename T>
    OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair<T>& right) const {
        return OrderedPair<T>(first + right.first, second + right.second);
    }

    template<typename T>
    bool OrderedPair<T>::operator<(const OrderedPair<T>& right) const {
        return first + second < right.first + right.second;
    }

    template<typename T>
    void OrderedPair<T>::print() const {
        cout << "(" << first << ", " << second << ")";
    }
}