// 02_expressions_tests.cpp
#include "catch.hpp"
#include "hwexpressions.h"
#include "hwexpressions.cpp"

TEST_CASE("Test Get Sales Tax") {
    REQUIRE(get_sales_tax_amount(10) == double (0.675));
    REQUIRE(get_sales_tax_amount(20) == double (1.35));
}

TEST_CASE("Test Get Tip Amount") {
    REQUIRE(get_tip_amount(20, 0.15) == double (3.0));
    REQUIRE(get_tip_amount(20, 0.20) == double (4.0));
}