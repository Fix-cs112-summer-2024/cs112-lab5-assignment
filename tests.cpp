#define CATCH_CONFIG_MAIN
#include "Vec.h"
#include "catch.hpp"

TEST_CASE("constructors") {
    SECTION("default") {
        Vec v;
        REQUIRE(v.getSize() == 0);
        REQUIRE(v.getArray() == nullptr);
    }
    SECTION("explicit-value") {
        //	Vec v1(3);
        //	REQUIRE(v1.getSize() == 3);
        //	REQUIRE(v1.getArray() != nullptr);
        //	for (int i = 0; i < 3; ++i) {
        //		REQUIRE(v1.getArray()[i] == 0);
        //	}
        //	Vec v2(8);
        //	REQUIRE(v2.getSize() == 8);
        //	REQUIRE(v2.getArray() != nullptr);
        //	for (int i = 0; i < 8; ++i) {
        //		REQUIRE(v2.getArray()[i] == 0);
        //	}
        //	Vec v3(0);
        //	REQUIRE(v3.getSize() == 0);
        //	REQUIRE(v3.getArray() == nullptr);
    }
    SECTION("copy") {
        //	Vec v1(3);
        //	REQUIRE(v1.getSize() == 3);
        //	REQUIRE(v1.getArray() != nullptr);
        //	for (int i = 0; i < 3; ++i) {
        //		REQUIRE(v1.getArray()[i] == 0);
        //	}
        //	Vec v2(8);
        //	REQUIRE(v2.getSize() == 8);
        //	REQUIRE(v2.getArray() != nullptr);
        //	for (int i = 0; i < 8; ++i) {
        //		REQUIRE(v2.getArray()[i] == 0);
        //	}
        //	Vec v3(0);
        //	REQUIRE(v3.getSize() == 0);
        //	REQUIRE(v3.getArray() == nullptr);
    }
}

TEST_CASE("destructor") {
    SECTION("") {
        //	Vec v(5);
        //	v.~Vec();
        //	REQUIRE(v.getSize() == 0);
        //	REQUIRE(v.getArray() == nullptr);
    }
}

TEST_CASE("assignment") {
    SECTION("empty-to-empty") {
        //	Vec v, v0;
        //	v = v0;
        //	REQUIRE(v.getSize() == 0);
        //	REQUIRE(v.getArray() == nullptr);
    }
    SECTION("empty-to-nonempty") {
        //	Vec v1;
        //	Vec v2(5);
        //	v2 = v1;
        //	REQUIRE(v2.getSize() == 0);
        //	REQUIRE(v2.getArray() == nullptr);
        //	cout << " 1 " << flush;
    }
    SECTION("nonempty-to-empty") {
        //	Vec v3(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v3.getArray()[i] = (i+1);
        //	}
        //	Vec v4;
        //	v4 = v3;
        //	REQUIRE(v4.getSize() == 5);
        //	REQUIRE(v4.getArray() != v3.getArray());
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v4.getArray()[i] == (i+1));
        //	}
    }
    SECTION("nonempty-to-nonempty (larger into smaller)") {
        //	Vec v5(2);
        //	for (unsigned i = 0; i < 2; ++i) {
        //		v5.getArray()[i] = (i+1)*10;
        //	}
        //	v5 = v3;
        //	REQUIRE(v5.getSize() == 5);
        //	REQUIRE(v5.getArray() != v3.getArray());
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v5.getArray()[i] == (i+1));
        //	}
    }
    SECTION("nonempty-to-nonempty (smaller into larger)") {
        //	Vec v6(7);
        //	for (unsigned i = 0; i < 7; ++i) {
        //		v6.getArray()[i] = (i+1)*10;
        //	}
        //	v6 = v3;
        //	REQUIRE(v6.getSize() == 5);
        //	REQUIRE(v6.getArray() != v3.getArray());
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v6.getArray()[i] == (i+1));
        //	}
        //	cout << " 4 " << flush;
        //	// nonempty-to-nonempty (equal sized)
        //	Vec v7(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v7.getArray()[i] = (i+1)*10;
        //	}
        //	v7 = v3;
        //	REQUIRE(v7.getSize() == 5);
        //	REQUIRE(v7.getArray() != v3.getArray());
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v7.getArray()[i] == (i+1));
        //	}
    }
    SECTION("assignment chaining") {
        //	Vec v8;
        //	Vec v9(4);
        //	v9 = v8 = v3;
        //	REQUIRE(v9.getSize() == 5);
        //	REQUIRE(v9.getSize() == 5);
        //	REQUIRE(v8.getArray() != v3.getArray());
        //	REQUIRE(v8.getArray() != v3.getArray());
        //	REQUIRE(v9.getArray() != v8.getArray());
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v8.getArray()[i] == (i+1));
        //		REQUIRE(v9.getArray()[i] == (i+1));
        //	}
    }
}

TEST_CASE("getSize") {
    SECTION("empty and non-empty") {
        //	Vec v1;
        //	REQUIRE(v1.getSize() == 0);
        //	Vec v2(5);
        //	REQUIRE(v2.getSize() == 5);
    }
}

TEST_CASE("setItem") {
    SECTION("empty case") {
        //	Vec v0;
        // REQUIRE_THROWS_AS(v0.setItem(0, 11), range_error);
    }
    SECTION("nonempty case, valid subscript") {
        //	Vec v(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v.setItem(i, i+1);
        //	}
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v.getArray()[i] == (i+1));
        //	}
    }
    SECTION("nonempty case, invalid subscript") {
        //	Vec v2(3);
        // REQUIRE(v2.setItem(3, 33), range_error);
    }
}

TEST_CASE("getItem") {
    SECTION("empty Vec") {
        //	Vec v0;
        //	try {
        //		v0.getItem(0);
        //		cerr << "getItem() succeeded on empty Vec";
        //		exit(1);
        //	} catch (range_error&) {
        //		cout << " 0 " << flush;
        //	}
    }
    SECTION("non-empty, valid access") {
        //	Vec v(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v.setItem(i, i+1);
        //	}
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v.getItem(i) == (i+1));
        //	}
    }
    SECTION("nonempty Vec, invalid index") {
        //	Vec v2(3);
        //	REQUIRE(v2.getItem(3), range_error);
    }
}

TEST_CASE("setSize") {
    SECTION("empty") {
        //	Vec v0;
        //	v0.setSize(3);
        //	REQUIRE(v0.getSize() == 3);
        //	for (unsigned i = 0; i < 3; ++i) {
        //		REQUIRE(v0.getItem(i) == 0);
        //	}
    }
    SECTION("non-empty, increasing") {
        //	Vec v1(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v1.setItem(i, i+1);
        //	}
        //	Item * saveAddress = v1.getArray();
        //	v1.setSize(8);
        //	REQUIRE(v1.getSize() == 8);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v1.getItem(i) == (i+1));
        //	}
        //	for (unsigned i = 5; i < 8; ++i) {
        //		REQUIRE(v1.getItem(i) == 0);
        //	}
        //	REQUIRE(v1.getArray() != saveAddress);
    }
    SECTION("non-empty, decreasing") {
        //	Vec v2(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v2.setItem(i, i+1);
        //	}
        //	saveAddress = v2.getArray();
        //	v2.setSize(3);
        //	REQUIRE(v2.getSize() == 3);
        //	for (unsigned i = 0; i < 3; ++i) {
        //		REQUIRE(v2.getItem(i) == (i+1));
        //	}
        //	REQUIRE(v2.getArray() != saveAddress);
    }
    SECTION("non-empty, same-size") {
        //	Vec v3(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v3.setItem(i, i+1);
        //	}
        //	saveAddress = v3.getArray();
        //	v3.setSize(5);
        //	REQUIRE(v3.getSize() == 5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		REQUIRE(v3.getItem(i) == (i+1));
        //	}
        //	REQUIRE(v3.getArray() == saveAddress);
    }
    SECTION("set size to zero") {
        //	v3.setSize(0);
        //	REQUIRE(v3.getSize() == 0);
        //	REQUIRE(v3.getArray() == nullptr);
    }
}

TEST_CASE("equality") {
    SECTION("empty case") {
        //	Vec v1;
        //	Vec v2;
        //	REQUIRE(v1 == v2);
    }
    SECTION("nonempty, same size, default values") {
        //	Vec v3(5);
        //	Vec v4(5);
        //	REQUIRE(v3 == v4);
    }
    SECTION("nonempty, same size, set values") {
        //	Vec v5(5);
        //	Vec v6(5);
        //	for (unsigned i = 0; i < 5; ++i) {
        //		v5.setItem(i, i+1);
        //		v6.setItem(i, i+1);
        //	}
        //	REQUIRE(v5 == v6);
    }
    SECTION("empty vs nonempty") {
        //	Vec v7;
        //	Vec v8(5);
        //	REQUIRE(!(v7 == v8));
    }
    //	Vec v9(5);
    //	Vec v10(5);
    SECTION("nonempty, same size, first value different") {
        //	v10.setItem(0, 1);
        //	REQUIRE(!(v9 == v10));
    }
    SECTION("nonempty, same size, middle value different") {
        //	Vec v11(5);
        //	v11.setItem(2, 1);
        //	REQUIRE(!(v9 == v11));
    }
    SECTION("nonempty, same size, last value different") {
        //	Vec v12(5);
        //	v12.setItem(4, 1);
        //	REQUIRE(!(v9 == v12));
    }
}

TEST_CASE("writeToStream") {
    SECTION("") {
        //       Vec v1(5);
        //       for (unsigned i = 0; i < 5; ++i) {
        //               v1.setItem(i, i+10);
        //       }
        //	// write to an ofstream instead of cout, to automate the test
        //       ofstream fout("vecStreamOut.txt");
        //       REQUIRE(fout.is_open());
        //       fout << v1.getSize() << "\n";
        //       v1.writeTo(fout);
        //	    fout.close();
        //	// now read in what we just wrote...
        //       ifstream fin("vecStreamOut.txt");
        //       REQUIRE(fin.is_open());
        //       unsigned size;
        //       fin >> size;
        //       REQUIRE(size == 5);
        //       double value;
        //       for (unsigned i = 0; i < 5; ++i) {
        //               fin >> value;
        //               REQUIRE(value == i+10);
        //       }
    }
    //       cout << "Passed! See 'vecStreamOut.txt' for values..." <<
    //       endl;
}

TEST_CASE("readFromStream") {
    SECTION("") {
        //	// an ifstream is-an istream, so use one to automate the test
        //       ifstream fin("vecStreamOut.txt");
        //       REQUIRE(fin.is_open());
        //	// get the size and build the Vec
        //       unsigned size;
        //       fin >> size;
        //       REQUIRE(size == 5);
        //       Vec v(size);
        //	// test readFrom()
        //       v.readFrom(fin);
        //       for (unsigned i = 0; i < 5; ++i) {
        //               REQUIRE(v.getItem(i)== i+10);
        //       }
        //	fin.close();
    }
}
