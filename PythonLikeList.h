/*
 * CS112List.h
 *
 *  Created on: Feb 4, 2022
 *      Author: vtn2
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <string>
using namespace std;

typedef string Item;

class PythonLikeList {
public:
	PythonLikeList();
	PythonLikeList(int size);
	PythonLikeList(const PythonLikeList &orig); // copy ctor
	virtual ~PythonLikeList();

	// getters
	int getSize() const;
	Item getValue(int index) const;
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);

	// others
	void append(const Item &value);

	PythonLikeList & operator+(const PythonLikeList &rhs) const;

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
};

// make it so we can do cout << aList.
ostream& operator<<(ostream &out, const PythonLikeList &rhs);

#endif /* CS112LIST_H_ */
