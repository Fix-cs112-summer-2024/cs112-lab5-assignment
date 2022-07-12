#include <cassert>
#include <iostream>

#include "PythonLikeList.h"
using namespace std;


int main() {
    cout << "Test constructors...\n";
    PythonLikeList lst;
    assert(lst.getSize() == 0);

    PythonLikeList lst2(5);
    assert(lst2.getSize() == 5);

    cout << "Testing getValue\n";
    assert(lst2.getValue(0) == "");
    assert(lst2.getValue(4) == "");
    try {
        assert(lst2.getValue(5) == "");
        assert(false);
    } catch (const range_error &re) {
        // do nothing here: All is well!
    }

    cout << "testing setValue\n";
    lst2.setValue(0, "hi");
    assert(lst2.getValue(0) == "hi");
    try {
        assert(lst2.getValue(5) == "");
        assert(false);
    } catch (const range_error &re) {
        // do nothing here: All is well!
    }

    cout << "Testing []\n";
    assert(lst2[0] == "hi");  // getting the value
    lst2[1] = "hello";        // setting the value.
    assert(lst2[1] == "hello");
    try {
        assert(lst2[5] == "");
        assert(false);
    } catch (const range_error &re) {
        // do nothing here: All is well!
    }

    cout << "Test copy constructor\n";
    PythonLikeList lst3(lst2);
    assert(lst3.getSize() == lst2.getSize());
    lst2[2] = "please work!";
    assert(lst3[2] != "please work!");

    cout << "Testing printing...\n";
    PythonLikeList lst4(2);
    lst4[0] = "Emma";
    lst4[1] = "Wang";
    cout << "This is a list -->" << lst4 << "<--\n";

    cout << "Testing append...\n";
    PythonLikeList aList;
    assert(aList.getSize() == 0);
    aList.append("Alex");
    assert(aList.getSize() == 1);
    assert(aList[0] == "Alex");
    cout << aList << endl;

    aList.append("Heyab");
    assert(aList.getSize() == 2);
    assert(aList[0] == "Alex");
    assert(aList[1] == "Heyab");
    cout << aList << endl;

    aList.append("Prof Norman is weird.");
    cout << aList << endl;

    cout << "Testing operator+" << endl;
    PythonLikeList l1;
    l1.append("Hi");
    PythonLikeList l2;
    l2.append("Nihao");
    l2.append("Konnichiwa");
    PythonLikeList l3 = l1 + l2;
    cout << l3 << endl;
    assert(l3.getSize() == 3);
    assert(l3[0] == "Hi");
    assert(l3[1] == "Nihao");
    assert(l3[2] == "Konnichiwa");

    // cout << "Testing negative indexes..." << endl;
    // assert(l3[-1] == "Konnichiwa");
    //assert(l3[-2] == "Nihao");
    // assert(l3.getItem(-2) == "Nihao");
    // try {
 //	l3[-4];
 //	assert(false);
    // } catch (const range_error &re) {
     //	// nothing here.
    // }
    // l3[-1] = "AufWiedersehen";
    // assert(l3[2] == "AufWiedersehen");
    // l3.setItem(-1, "Hallo");
    // assert(l3[2] == "Hallo");

    cout << "All tests passed!\n";
    return 0;
}
