/*
 * PyList.h
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <string>
using namespace std;

typedef string Item;

class PyList {
public:
	PyList();
	PyList(int size);
	PyList(const PyList &orig); // copy ctor
	virtual ~PyList();

	// getters
	int getSize() const;
	Item getValue(int index) const;
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);

	// others
	void append(const Item &value);

	PyList & operator+(const PyList &rhs) const;

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
};

// make it so we can do cout << aList.
ostream& operator<<(ostream &out, const PyList &rhs);

#endif /* CS112LIST_H_ */
