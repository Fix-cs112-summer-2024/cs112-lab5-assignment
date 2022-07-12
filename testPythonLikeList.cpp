#define CATCH_CONFIG_MAIN
#include <iostream>

#include "PythonLikeList.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("constructors") {
    PythonLikeList lst;
    PythonLikeList lst2(5);
    SECTION("empty") { REQUIRE(lst.getSize() == 0); }
    SECTION("nonempty") { REQUIRE(lst2.getSize() == 5); }
    SECTION("getValue") {
        REQUIRE(lst2.getValue(0) == "");
        REQUIRE(lst2.getValue(4) == "");
        REQUIRE_THROWS_AS(lst2.getValue(5), range_error);
    }
    SECTION("setValue") {
        lst2.setValue(0, "hi");
        REQUIRE(lst2.getValue(0) == "hi");
        REQUIRE_THROWS_AS(lst2.getValue(5), range_error);
    }
    SECTION("subscripting") {
        REQUIRE(lst2[0] == "hi");  // getting the value
        lst2[1] = "hello";         // setting the value.
        REQUIRE(lst2[1] == "hello");
        REQUIRE_THROWS_AS(lst2[5], range_error);
    }
    SECTION("copy constructor") {
        PythonLikeList lst3(lst2);
        REQUIRE(lst3.getSize() == lst2.getSize());
        lst2[2] = "please work!";
        REQUIRE(lst3[2] != "please work!");
    }
    SECTION("printing") {
        PythonLikeList lst4(2);
        lst4[0] = "Victor";
        lst4[1] = "Norman";
        std::cout << "This is a list -->" << lst4 << "<--\n";
    }
    SECTION("append") {
        PythonLikeList aList;
        REQUIRE(aList.getSize() == 0);
        aList.append("Alex");
        REQUIRE(aList.getSize() == 1);
        REQUIRE(aList[0] == "Alex");
        aList.append("Betty");
        REQUIRE(aList.getSize() == 2);
        REQUIRE(aList[0] == "Alex");
        REQUIRE(aList[1] == "Betty");
    }
    SECTION("operator+") {
        PythonLikeList l1;
        l1.append("Hi");
        PythonLikeList l2;
        l2.append("Nihao");
        l2.append("Konnichiwa");
        PythonLikeList l3 = l1 + l2;
        REQUIRE(l3.getSize() == 3);
        REQUIRE(l3[0] == "Hi");
        REQUIRE(l3[1] == "Nihao");
        REQUIRE(l3[2] == "Konnichiwa");
    }
    // SECTION("negative indexes") {
    // PythonLikeList l4;
    // l4.append("Hi");
    // l4.append("Nihao");
    // l4.append("Konnichiwa");
    // REQUIRE(l4[-1] == "Konnichiwa");
    // REQUIRE(l4[-2] == "Nihao");
    // REQUIRE(l4.getItem(-2) == "Nihao");
    // REQUIRE_THROWS_AS(l4[-4], range_error);
    // l4[-1] = "AufWiedersehen";
    // REQUIRE(l4[2] == "AufWiedersehen");
    // l4.setItem(-1, "Hallo");
    // REQUIRE(l4[2] == "Hallo");
    // }
}
