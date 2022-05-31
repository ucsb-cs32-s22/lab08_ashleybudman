//SimpleList.cpp

#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <iostream>
#include <string>

using namespace std;

template <class T> SimpleList<T>::SimpleList() {
    elements = new T[CAPACITY];
    numElements = 0;
}

template <class T> SimpleList<T>::~SimpleList() {
    delete [] elements;
}

template <class T> T SimpleList<T>::at(int index)const throw(InvalidIndexException) {
    if (index < 0 || index >= numElements) {
        InvalidIndexException d;
        throw d;

    } else {
        return elements[index];
    }
}

template <class T> bool SimpleList<T>::empty() const {
    return(numElements==0);
}

template <class T> T SimpleList<T>::first() const throw(EmptyListException) {
    if (numElements == 0) {
        EmptyListException e;
        throw e;
    } else {
        return elements[0];
    }
}

template <class T> T SimpleList<T>::last () const throw(EmptyListException) {
    if (numElements == 0) {
        EmptyListException e;
        throw e;
    } else {
        return elements[numElements-1];
    }
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T> void SimpleList<T>::insert(T item) throw (FullListException) {
    if (numElements == CAPACITY) {
        FullListException f;
        throw f;
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
        InvalidIndexException i;
        throw i;
    } else {
        for (int i=index+1; i <numElements; i++ ) {
            elements[i-1] = elements[i];
        }
    }
}

//template SimpleList::SimpleList();
//template SimpleList<int>::SimpleList();
//template SimpleList::~SimpleList();
//template SimpleList<int>::~SimpleList();
//template SimpleList<string>::string at(int index)const throw(InvalidIndexException);
//template SimpleList<int>::int at(int index)const throw(InvalidIndexException);
//template bool SimpleList<string>::empty() const;
//template bool SimpleList<int>::empty() const;
//template SimpleList<string>::string first() const throw(EmptyListException);
//template SimpleList<int>::int first() const throw(EmptyListException);
//template SimpleList<string>::string last () const throw(EmptyListException);
//template SimpleList<int>::int last () const throw(EmptyListException);
//template int SimpleList<string>::getNumElements() const;
//template int SimpleList<int>::getNumElements() const;
//template void SimpleList<string>::string insert(string item) throw (FullListException);
//template void SimpleList<int>::int insert(int item) throw (FullListException);
//template void SimpleList<string>::remove(int index) throw (InvalidIndexException, EmptyListException);
//template void SimpleList<int>::remove(int index) throw (InvalidIndexException, EmptyListException);

