//SimpleList.cpp

#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <iostream>
#include <string>

using namespace std;

template <class T> void destroy(T element) {
}

template <class T> void destroy (T* element) {
    delete element;
}

template <class T> void function1(T x) {
    if (is_pointer<T>::value) {
        destroy(x[0]);
    } else {
        destroy(x[0]);
    }
}



template <class T> SimpleList<T>::SimpleList() {
    elements = new T[CAPACITY];
    numElements = 0;
}

template <class T> SimpleList<T>::~SimpleList() {
    function1(elements);
}

template <class T> T SimpleList<T>::at(int index)const throw(InvalidIndexException) {
    if (index < 0 || index >= numElements) {
        InvalidIndexException a;
        throw a;

    } else {
        return elements[index];
    }
}

template <class T> bool SimpleList<T>::empty() const {
    return(numElements==0);
}

template <class T> T SimpleList<T>::first() const throw(EmptyListException) {
    if (numElements == 0) {
        EmptyListException b;
        throw b;
    } else {
        return elements[0];
    }
}

template <class T> T SimpleList<T>::last () const throw(EmptyListException) {
    if (numElements == 0) {
        EmptyListException c;
        throw c;
    } else {
        return elements[numElements-1];
    }
}

template <class T> int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T> void SimpleList<T>::insert(T item) throw (FullListException) {
    if (numElements == CAPACITY) {
        FullListException d;
        throw d;
    } else {
        elements[numElements] = item;
        numElements++;
    }
}

template <class T> void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException) {
    if (numElements == 0) {
        EmptyListException e;
        throw e;
    } else if (index < 0 || index >= numElements) {
        InvalidIndexException f;
        throw f;
    } else {
        for (int i = index+1; i <numElements; i++ ) {
            elements[i-1] = elements[i];
        }
    }
}


