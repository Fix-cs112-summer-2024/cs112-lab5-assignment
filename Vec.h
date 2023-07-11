/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
    Vec();
    virtual ~Vec();
    Vec(unsigned size);
    Vec(const Vec& original);

    unsigned getSize() const;
    Item getItem(unsigned index) const;
    void setItem(unsigned index, const Item& it);
    void setSize(unsigned newSize);

    // assignment operator: e.g., v2 = original;
    Vec& operator=(const Vec& original);
    // equality operator: e.g., v1 == v2
    bool operator==(const Vec& v2) const;
    void writeTo(ostream& out) const;
    void readFrom(istream& in);

    Item& operator[](unsigned index);
    const Item& operator[](unsigned index) const;
    Vec operator+(const Vec& rhs) const;
    Vec operator-(const Vec& rhs) const;

private:
    unsigned mySize;
    Item* myArray;
};

#endif /*VEC_H_*/
