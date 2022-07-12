/*
 * PythonLikeList.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#include <stdexcept>
#include <iostream>
using namespace std;
#include "PythonLikeList.h"

PythonLikeList::PythonLikeList() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

PythonLikeList::PythonLikeList(int size) {
	mySize = myCapacity = size;
	myArray = new Item[size]();
}

PythonLikeList::PythonLikeList(const PythonLikeList &orig) {
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
PythonLikeList::~PythonLikeList() {
	delete [] myArray;
}

void PythonLikeList::append(const Item &value) {
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

int PythonLikeList::getSize() const {
	return mySize;
}

Item PythonLikeList::getValue(int index) const {
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range");
	}
	return myArray[index];
}

void PythonLikeList::setValue(int index, const Item &value) {
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range");
	}
	myArray[index] = value;
}

// return a reference to the index-th location.
Item & PythonLikeList::operator[](int index) const {
	if (index >= mySize) {
		throw range_error("index " + to_string(index) + " out of range");
	}
	return myArray[index];
}

PythonLikeList & PythonLikeList::operator+(const PythonLikeList &rhs) const {
	PythonLikeList *result = new PythonLikeList(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

ostream& operator<<(ostream &out, const PythonLikeList &rhs) {
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


