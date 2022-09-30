/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include <stdexcept>
using namespace std;
#include "Vec.h"

Vec::Vec() {
    mySize = 0;
    myArray = nullptr;
}

Vec::~Vec() {
    delete[] myArray;
    myArray = nullptr;
    mySize = 0;
}

Vec::Vec(unsigned size) {
    mySize = size;
    if (size > 0) {
        myArray = new Item[size]();
    } else {
        myArray = nullptr;
    }
}

// copy constructor
Vec::Vec(const Vec& original) {
    mySize = original.mySize;
    if (original.mySize > 0) {
        myArray = new Item[original.mySize]();
        for (int i = 0; i < original.mySize; i++) {
            myArray[i] = original.myArray[i];
        }
    } else {
        myArray = nullptr;
    }
}

unsigned Vec::getSize() const {
    return mySize;
}

Item* Vec::getArray() const {
    return myArray;
}

// assignment operator: e.g., v2 = original;
Vec& Vec::operator=(const Vec& original) {
    if (this != &original) {
        if (mySize != original.mySize) {
            if (mySize > 0) {
                delete[] myArray;
                myArray = nullptr;
            }
            if (original.mySize > 0) {
                myArray = new Item[original.mySize];
            }
            mySize = original.mySize;
        }
        for (int i = 0; i < mySize; i++) {
            myArray[i] = original.myArray[i];
        }
    }
    return *this;
}

void Vec::setItem(unsigned index, const Item& it) {
    if (index < 0 || index >= mySize) {
        throw range_error("Bad index");
    }
    myArray[index] = it;
}

Item Vec::getItem(unsigned index) const {
    if (index < 0 || index >= mySize) {
        throw range_error("Bad index");
    }
    return myArray[index];
}

void Vec::setSize(unsigned newSize) {
    if (mySize != newSize) {
        if (newSize == 0) {
            delete[] myArray;
            myArray = nullptr;
            mySize = 0;
        } else {
            Item* newArray = new Item[newSize]();
            if (mySize < newSize) {
                for (int i = 0; i < mySize; i++) {
                    newArray[i] = myArray[i];
                }
            } else {
                for (int i = 0; i < newSize; i++) {
                    newArray[i] = myArray[i];
                }
            }
            mySize = newSize;
            delete[] myArray;
            myArray = newArray;
        }
    }
}

bool Vec::operator==(const Vec& v2) const {
    if (mySize != v2.mySize) {
        return false;
    }
    for (int i = 0; i < mySize; i++) {
        if (myArray[i] != v2.myArray[i]) {
            return false;
        }
    }
    return true;
}

void Vec::writeTo(ostream& out) const {
    for (int i = 0; i < mySize; i++) {
        out << myArray[i] << ' ';
    }
}

void Vec::readFrom(istream& in) {
    for (int i = 0; i < mySize; i++) {
        in >> myArray[i];
    }
}

Item& Vec::operator[](unsigned index) {
    if (index < 0 || index >= mySize) {
        throw range_error("Bad index");
    }
    return myArray[index];
}

const Item& Vec::operator[](unsigned index) const {
    if (index < 0 || index >= mySize) {
        throw range_error("Bad index");
    }
    return myArray[index];
}

Vec Vec::operator+(const Vec &rhs) const {
    if (mySize != rhs.mySize) {
        throw invalid_argument("Cannot add vectors of different sizes");
    }
    Vec res(mySize);
    for (int i = 0; i < mySize; i++) {
        res[i] = myArray[i] + rhs[i];
    }
    return res;
}

Vec Vec::operator-(const Vec& rhs) const {
    if (mySize != rhs.mySize) {
        throw invalid_argument("Cannot add vectors of different sizes");
    }
    Vec res(mySize);
    for (int i = 0; i < mySize; i++) {
        res[i] = myArray[i] - rhs[i];
    }
    return res;
}


