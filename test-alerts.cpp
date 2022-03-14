#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "detect_ranges.h"
#include <string.h>

TEST_CASE("With provided input range, check if min-max range & number of readings matches the expected value.") {
  int input_range[2]= {4,5};
  const char *expected_range = "4-5,2";
  int size = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_range = findReadingsFromRange(input_range, size);
  REQUIRE(strcmp(actual_range, expected_range) == 0);
}

TEST_CASE("detect the ranges and check if the number of readings matches the expected value.") {
  int input_range[]= {3, 5, 4, 3};
  const char *expected_range = "3-5,4";
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_range = findReadingsFromRange(input_range, no_of_elements);
  REQUIRE(strcmp(actual_range, expected_range) == 0);
}


