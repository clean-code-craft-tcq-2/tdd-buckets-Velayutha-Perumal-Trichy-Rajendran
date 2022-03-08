#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "detect_ranges.h"
#include <string.h>

TEST_CASE("detect the ranges and check if the number of readings in each range matches the expected value.") {
  int input_range[2]= {4,5};
  const char *expected_range = "4-5,2";
  char *actual_range = findReadingsFromRange(input_range);
  REQUIRE(strcmp(actual_range, expected_range) == 0);
}
