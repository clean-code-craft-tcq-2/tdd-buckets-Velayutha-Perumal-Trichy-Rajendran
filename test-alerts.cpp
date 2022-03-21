#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "detect_ranges.h"
#include <string.h>
#include <stdio.h>

TEST_CASE("With provided input range, check if min-max range & number of readings matches the expected value.") {
  int input_range[2]= {4,5};
  const char *expected_range = "4-5,2";
  char readingRange[10];
  int size = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, size, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

TEST_CASE("detect the ranges and check if the number of readings matches the expected value.") {
  int input_range[]= {3, 5, 4, 3};
  const char *expected_range = "3-5,4";
  char readingRange[10];
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, no_of_elements, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

TEST_CASE("detect multiple ranges and check if the number of readings of each range matches the expected value.") {
  int input_range[]= {3, 5, 4, 3, 8, 10, 9, 7};
  const char *expected_range = "3-5,4\n7-10,4";
  char readingRange[16];
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, no_of_elements, readingRange);
  printf ("The result is %s\n",actual_result);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}


