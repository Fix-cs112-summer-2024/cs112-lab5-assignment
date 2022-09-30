#define CATCH_CONFIG_MAIN
#include <cassert>

#include "Vec.h"
#include "catch.hpp"

// TEST_CASE("constructors") {
//     SECTION("default") {
//         Vec<double> v;
//         REQUIRE(v.getSize() == 0);
//         REQUIRE(v.getArray() == nullptr);
//     }
//     SECTION("explicit-value") {
//         Vec<double> v1(3);
//         REQUIRE(v1.getSize() == 3);
//         REQUIRE(v1.getArray() != nullptr);
//         for (int i = 0; i < 3; ++i) {
//             REQUIRE(v1.getArray()[i] == 0);
//         }
//         Vec<double> v2(8);
//         REQUIRE(v2.getSize() == 8);
//         REQUIRE(v2.getArray() != nullptr);
//         for (int i = 0; i < 8; ++i) {
//             REQUIRE(v2.getArray()[i] == 0);
//         }
//         Vec<double> v3(0);
//         REQUIRE(v3.getSize() == 0);
//         REQUIRE(v3.getArray() == nullptr);
//     }
//     SECTION("copy") {
//         Vec<double> v1(3);
//         REQUIRE(v1.getSize() == 3);
//         REQUIRE(v1.getArray() != nullptr);
//         for (int i = 0; i < 3; ++i) {
//             REQUIRE(v1.getArray()[i] == 0);
//         }
//         Vec<double> v2(8);
//         REQUIRE(v2.getSize() == 8);
//         REQUIRE(v2.getArray() != nullptr);
//         for (int i = 0; i < 8; ++i) {
//             REQUIRE(v2.getArray()[i] == 0);
//         }
//         Vec<double> v3(0);
//         REQUIRE(v3.getSize() == 0);
//         REQUIRE(v3.getArray() == nullptr);
//     }
// }

// TEST_CASE("destructor") {
//     SECTION("") {
//         Vec<double> v(5);
//         v.~Vec<double>();
//         REQUIRE(v.getSize() == 0);
//         REQUIRE(v.getArray() == nullptr);
//     }
// }

// TEST_CASE("assignment") {
//     Vec<double> v3(5);
//     for (unsigned i = 0; i < 5; ++i) {
//         v3.getArray()[i] = (i + 1);
//     }
//     SECTION("empty-to-empty") {
//         Vec<double> v, v0;
//         v = v0;
//         REQUIRE(v.getSize() == 0);
//         REQUIRE(v.getArray() == nullptr);
//     }
//     SECTION("empty-to-nonempty") {
//         Vec<double> v1;
//         Vec<double> v2(5);
//         v2 = v1;
//         REQUIRE(v2.getSize() == 0);
//         REQUIRE(v2.getArray() == nullptr);
//         cout << " 1 " << flush;
//     }
//     SECTION("nonempty-to-empty") {
//         for (unsigned i = 0; i < 5; ++i) {
//             v3.getArray()[i] = (i + 1);
//         }
//         Vec<double> v4;
//         v4 = v3;
//         REQUIRE(v4.getSize() == 5);
//         REQUIRE(v4.getArray() != v3.getArray());
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v4.getArray()[i] == (i + 1));
//         }
//     }
//     SECTION("nonempty-to-nonempty (larger into smaller)") {
//         Vec<double> v5(2);
//         for (unsigned i = 0; i < 2; ++i) {
//             v5.getArray()[i] = (i + 1) * 10;
//         }
//         v5 = v3;
//         REQUIRE(v5.getSize() == 5);
//         REQUIRE(v5.getArray() != v3.getArray());
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v5.getArray()[i] == (i + 1));
//         }
//     }
//     SECTION("nonempty-to-nonempty (smaller into larger)") {
//         Vec<double> v6(7);
//         for (unsigned i = 0; i < 7; ++i) {
//             v6.getArray()[i] = (i + 1) * 10;
//         }
//         v6 = v3;
//         REQUIRE(v6.getSize() == 5);
//         REQUIRE(v6.getArray() != v3.getArray());
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v6.getArray()[i] == (i + 1));
//         }
//         cout << " 4 " << flush;
//         // nonempty-to-nonempty (equal sized)
//         Vec<double> v7(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v7.getArray()[i] = (i + 1) * 10;
//         }
//         v7 = v3;
//         REQUIRE(v7.getSize() == 5);
//         REQUIRE(v7.getArray() != v3.getArray());
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v7.getArray()[i] == (i + 1));
//         }
//     }
//     SECTION("assignment chaining") {
//         Vec<double> v8;
//         Vec<double> v9(4);
//         v9 = v8 = v3;
//         REQUIRE(v9.getSize() == 5);
//         REQUIRE(v9.getSize() == 5);
//         REQUIRE(v8.getArray() != v3.getArray());
//         REQUIRE(v8.getArray() != v3.getArray());
//         REQUIRE(v9.getArray() != v8.getArray());
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v8.getArray()[i] == (i + 1));
//             REQUIRE(v9.getArray()[i] == (i + 1));
//         }
//     }
// }

// TEST_CASE("getSize") {
//     SECTION("empty and non-empty") {
//         Vec<double> v1;
//         REQUIRE(v1.getSize() == 0);
//         Vec<double> v2(5);
//         REQUIRE(v2.getSize() == 5);
//     }
// }

// TEST_CASE("setItem") {
//     SECTION("empty case") {
//         Vec<double> v0;
//         REQUIRE_THROWS_AS(v0.setItem(0, 11), range_error);
//     }
//     SECTION("nonempty case, valid subscript") {
//         Vec<double> v(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v.setItem(i, i + 1);
//         }
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v.getArray()[i] == (i + 1));
//         }
//     }
//     SECTION("nonempty case, invalid subscript") {
//         Vec<double> v2(3);
//         REQUIRE_THROWS_AS(v2.setItem(3, 33), range_error);
//     }
// }

// TEST_CASE("getItem") {
//     SECTION("empty Vec<double>") {
//         Vec<double> v0;
//         try {
//             v0.getItem(0);
//             cerr << "getItem() succeeded on empty Vec<double>";
//             exit(1);
//         } catch (range_error&) {
//             cout << " 0 " << flush;
//         }
//     }
//     SECTION("non-empty, valid access") {
//         Vec<double> v(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v.setItem(i, i + 1);
//         }
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v.getItem(i) == (i + 1));
//         }
//     }
//     SECTION("nonempty Vec, invalid index") {
//         Vec<double> v2(3);
//         REQUIRE_THROWS_AS(v2.getItem(3), range_error);
//     }
// }

// TEST_CASE("setSize") {
//     SECTION("empty") {
//         Vec<double> v0;
//         v0.setSize(3);
//         REQUIRE(v0.getSize() == 3);
//         for (unsigned i = 0; i < 3; ++i) {
//             REQUIRE(v0.getItem(i) == 0);
//         }
//     }
//     SECTION("non-empty, increasing") {
//         Vec<double> v1(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v1.setItem(i, i + 1);
//         }
//         Item* saveAddress = v1.getArray();
//         v1.setSize(8);
//         REQUIRE(v1.getSize() == 8);
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v1.getItem(i) == (i + 1));
//         }
//         for (unsigned i = 5; i < 8; ++i) {
//             REQUIRE(v1.getItem(i) == 0);
//         }
//         REQUIRE(v1.getArray() != saveAddress);
//     }
//     SECTION("non-empty, decreasing") {
//         Vec<double> v2(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v2.setItem(i, i + 1);
//         }
//         Item* saveAddress = v2.getArray();
//         v2.setSize(3);
//         REQUIRE(v2.getSize() == 3);
//         for (unsigned i = 0; i < 3; ++i) {
//             REQUIRE(v2.getItem(i) == (i + 1));
//         }
//         REQUIRE(v2.getArray() != saveAddress);
//     }
//     SECTION("non-empty, same-size") {
//         Vec<double> v3(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v3.setItem(i, i + 1);
//         }
//         Item* saveAddress = v3.getArray();
//         v3.setSize(5);
//         REQUIRE(v3.getSize() == 5);
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v3.getItem(i) == (i + 1));
//         }
//         REQUIRE(v3.getArray() == saveAddress);
//     }
//     SECTION("set size to zero") {
//         Vec<double> v3(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v3.setItem(i, i + 1);
//         }
//         v3.setSize(0);
//         REQUIRE(v3.getSize() == 0);
//         REQUIRE(v3.getArray() == nullptr);
//     }
// }

// TEST_CASE("equality") {
//     SECTION("empty case") {
//         Vec<double> v1;
//         Vec<double> v2;
//         REQUIRE(v1 == v2);
//     }
//     SECTION("nonempty, same size, default values") {
//         Vec<double> v3(5);
//         Vec<double> v4(5);
//         REQUIRE(v3 == v4);
//     }
//     SECTION("nonempty, same size, set values") {
//         Vec<double> v5(5);
//         Vec<double> v6(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v5.setItem(i, i + 1);
//             v6.setItem(i, i + 1);
//         }
//         REQUIRE(v5 == v6);
//     }
//     SECTION("empty vs nonempty") {
//         Vec<double> v7;
//         Vec<double> v8(5);
//         REQUIRE(!(v7 == v8));
//     }
//     Vec<double> v9(5);
//     Vec<double> v10(5);
//     SECTION("nonempty, same size, first value different") {
//         v10.setItem(0, 1);
//         REQUIRE(!(v9 == v10));
//     }
//     SECTION("nonempty, same size, middle value different") {
//         Vec<double> v11(5);
//         v11.setItem(2, 1);
//         REQUIRE(!(v9 == v11));
//     }
//     SECTION("nonempty, same size, last value different") {
//         Vec<double> v12(5);
//         v12.setItem(4, 1);
//         REQUIRE(!(v9 == v12));
//     }
// }

// TEST_CASE("writeToStream") {
//     SECTION("") {
//         Vec<double> v1(5);
//         for (unsigned i = 0; i < 5; ++i) {
//             v1.setItem(i, i + 10);
//         }
//         // write to an ofstream instead of cout, to automate the test
//         ofstream fout("vecStreamOut.txt");
//         REQUIRE(fout.is_open());
//         fout << v1.getSize() << "\n";
//         v1.writeTo(fout);
//         fout.close();
//         // now read in what we just wrote...
//         ifstream fin("vecStreamOut.txt");
//         REQUIRE(fin.is_open());
//         unsigned size;
//         fin >> size;
//         REQUIRE(size == 5);
//         double value;
//         for (unsigned i = 0; i < 5; ++i) {
//             fin >> value;
//             REQUIRE(value == i + 10);
//         }
//     }
//     cout << "Passed! See 'vecStreamOut.txt' for values..." << endl;
// }

// TEST_CASE("readFromStream") {
//     SECTION("") {
//         // an ifstream is-an istream, so use one to automate the test
//         ifstream fin("vecStreamOut.txt");
//         REQUIRE(fin.is_open());
//         // get the size and build the Vec<double>
//         unsigned size;
//         fin >> size;
//         REQUIRE(size == 5);
//         Vec<double> v(size);
//         // test readFrom()
//         v.readFrom(fin);
//         for (unsigned i = 0; i < 5; ++i) {
//             REQUIRE(v.getItem(i) == i + 10);
//         }
//         fin.close();
//     }
// }

// void testConstSubscript(const Vec<double>& v) {
//     assert(v[0] == 11);
//     assert(v[1] == 22);
//     assert(v[2] == 33);
// }

// TEST_CASE("subscript") {
//     SECTION("empty case") {
//         Vec<double> v0;
//         REQUIRE_THROWS_AS(v0[0], range_error);
//     }
//     SECTION("non-empty case, non-const version") {
//         Vec<double> v1(3);
//         v1[0] = 11;
//         v1[1] = 22;
//         v1[2] = 33;
//         REQUIRE(v1.getItem(0) == 11);
//         REQUIRE(v1.getItem(1) == 22);
//         REQUIRE(v1.getItem(2) == 33);
//     }
//     SECTION("non-empty case, const version") {
//         Vec<double> v1(3);
//         v1[0] = 11;
//         v1[1] = 22;
//         v1[2] = 33;
//         testConstSubscript(v1);
//     }
// }

// TEST_CASE("addition") {
//     Vec<double> v1(3);
//     Vec<double> v2(3);
//     SECTION("nonempty") {
//         v1.setItem(0, 1);
//         v1.setItem(1, 2);
//         v1.setItem(2, 3);
//         v2.setItem(0, 2);
//         v2.setItem(1, 4);
//         v2.setItem(2, 6);
//         Vec<double> v3 = v1 + v2;
//         REQUIRE(v3.getItem(0) == 3);
//         REQUIRE(v3.getItem(1) == 6);
//         REQUIRE(v3.getItem(2) == 9);
//     }
//     SECTION("left operand not changed") {
//         v1.setItem(0, 1);
//         v1.setItem(1, 2);
//         v1.setItem(2, 3);
//         Vec<double> saveV1 = v1;
//         Vec<double> v3 = v1 + v2;
//         REQUIRE(v1.getItem(0) == saveV1.getItem(0));
//         REQUIRE(v1.getItem(1) == saveV1.getItem(1));
//         REQUIRE(v1.getItem(2) == saveV1.getItem(2));
//     }
//     SECTION("empty") {
//         Vec<double> v4, v5;
//         Vec<double> v3 = v4 + v5;
//         REQUIRE(v3.getSize() == 0);
//         REQUIRE(v3.getArray() == nullptr);
//     }
//     SECTION("different sizes") {
//         Vec<double> v3(1);
//         Vec<double> v2(2);
//         Vec<double> v4(3);
//         REQUIRE_THROWS_AS(v3 = v2 + v4, invalid_argument);
//     }
// }

// TEST_CASE("subtraction") {
//     Vec<double> v1(3);
//     Vec<double> v2(3);
//     SECTION("nonempty") {
//         v1.setItem(0, 1);
//         v1.setItem(1, 2);
//         v1.setItem(2, 3);
//         v2.setItem(0, 2);
//         v2.setItem(1, 4);
//         v2.setItem(2, 6);
//         Vec<double> v3 = v1 - v2;
//         REQUIRE(v3.getItem(0) == -1);
//         REQUIRE(v3.getItem(1) == -2);
//         REQUIRE(v3.getItem(2) == -3);
//     }
//     SECTION("should not change the left operand") {
//         v1.setItem(0, 1);
//         v1.setItem(1, 2);
//         v1.setItem(2, 3);
//         Vec<double> saveV1 = v1;
//         Vec<double> v3 = v1 - v2;
//         REQUIRE(v1.getItem(0) == saveV1.getItem(0));
//         REQUIRE(v1.getItem(1) == saveV1.getItem(1));
//         REQUIRE(v1.getItem(2) == saveV1.getItem(2));
//     }
//     SECTION("empty") {
//         Vec<double> v4, v5;
//         Vec<double> v3 = v4 - v5;
//         REQUIRE(v3.getSize() == 0);
//         REQUIRE(v3.getArray() == nullptr);
//     }
//     SECTION("different sizes") {
//         Vec<double> v3(1);
//         Vec<double> v2(2);
//         Vec<double> v4(3);
//         REQUIRE_THROWS_AS(v3 = v2 - v4, invalid_argument);
//     }
// }
