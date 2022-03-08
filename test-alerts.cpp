#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "detect_ranges.h"
#include <string.h>

TEST_CASE("detect the ranges and check if the number of readings in each range matches the expected value.") {
  int input_range[2]= {4,5};
  const char *expected_output = "4-5,2";
  REQUIRE(strcmp(findReadingsFromRange(input_range), expected_output) == 0);
}
