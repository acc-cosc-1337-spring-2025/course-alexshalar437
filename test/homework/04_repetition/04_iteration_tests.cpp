#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "repetition.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Test Factorial Function") {
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(6) == 720);
}

TEST_CASE("Test GCD Function") {
    REQUIRE(gcd(5, 15) == 5);
    REQUIRE(gcd(21, 28) == 7);
    REQUIRE(gcd(25, 100) == 25);
}

