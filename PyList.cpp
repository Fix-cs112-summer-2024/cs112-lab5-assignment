/*
 * PyList.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "PyList.h"

PyList::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

PyList::PyList(int capacity) {
    mySize = capacity;
    myCapacity = capacity;
    myArray = new Item[myCapacity]();
}

PyList::PyList(const PyList &orig) {
    // cout << "copy ctor called with object " << &orig << endl;
    mySize = orig.mySize;
    myCapacity = orig.myCapacity;
    if (myCapacity == 0) {
        myArray = nullptr;
    } else {
        // deep copy.
        myArray = new Item[mySize]();
        for (int i = 0; i < mySize; i++) {
            myArray[i] = orig.myArray[i];
        }
    }
}

// called when object goes out of scope.
PyList::~PyList() {
    delete[] myArray;
}

void PyList::append(const Item &value) {
    if (mySize >= myCapacity) {
        // Note: double the capacity, unless it was 0, then make it 1.
        int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
        Item *tmp = new Item[newCapacity]();
        for (int i = 0; i < mySize; i++) {
            tmp[i] = myArray[i];
        }
        myCapacity = newCapacity;
        delete[] myArray;
        myArray = tmp;
    }
    myArray[mySize] = value;
    mySize++;
}

int PyList::getSize() const {
    return mySize;
}

Item PyList::getValue(int index) const {
    if (index >= mySize) {
        throw range_error("index " + to_string(index) + " out of range");
    }
    return myArray[index];
}

void PyList::setValue(int index, const Item &value) {
    if (index >= mySize) {
        throw range_error("index " + to_string(index) + " out of range");
    }
    myArray[index] = value;
}

// return a reference to the index-th location.
Item &PyList::operator[](int index) const {
    if (index >= mySize) {
        throw range_error("index " + to_string(index) + " out of range");
    }
    return myArray[index];
}

PyList &PyList::operator+(const PyList &rhs) const {
    PyList *result = new PyList(mySize + rhs.mySize);
    for (int i = 0; i < mySize; i++) {
        (*result)[i] = myArray[i];
    }
    for (int i = 0; i < rhs.mySize; i++) {
        (*result)[mySize + i] = rhs[i];
    }
    return *result;
}

ostream &operator<<(ostream &out, const PyList &rhs) {
    out << "[";
    for (int i = 0; i < rhs.getSize(); i++) {
        out << rhs[i];
        if (i < rhs.getSize() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
