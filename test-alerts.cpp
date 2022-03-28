#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define OUTPUT_SIZE 32
#include "test/catch.hpp"
#include "detect_ranges.h"
#include "current_sensor.h"
#include <string.h>
#include <stdio.h>

TEST_CASE("With provided input range, check if min-max range & number of readings matches the expected value.") {
  int input_range[2]= {4,5};
  const char *expected_range = "4-5,2";
  char readingRange[OUTPUT_SIZE];
  int size = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, size, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

TEST_CASE("detect the ranges and check if the number of readings matches the expected value.") {
  int input_range[]= {3, 5, 4, 3};
  const char *expected_range = "3-5,4";
  char readingRange[OUTPUT_SIZE];
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, no_of_elements, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

TEST_CASE("detect multiple ranges and check if the number of readings of each range matches the expected value.") {
  int input_range[]= {3, 5, 4, 3, 8, 10, 9, 7};
  const char *expected_range = "3-5,4\n7-10,4";
  char readingRange[OUTPUT_SIZE];
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, no_of_elements, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

SCENARIO("find the current in amps from 12bit sensor output")
{
    GIVEN("12bit readings")
    {
        int a2dOutput[2] = {2048, 3096};
        int expectedCurrentInAmps[2] = {5, 7};
		int actualCurrentInAmps[2];
		int no_of_elements = sizeof(a2dOutput)/sizeof(a2dOutput[0]);

        WHEN("convertA2DOutputIntoAmps() is called with given 12bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(a2dOutput, no_of_elements, actualCurrentInAmps);
            THEN("a2dOutput will be converted in to equivalent Amps")
            {
                for (int i = 0; i < no_of_elements; i++)
                {
                    REQUIRE(actualCurrentInAmps[i] == expectedCurrentInAmps[i]);
                }
            }
        }
    }
}

SCENARIO("validate current in amps rounded off to nearest integer")
{
    GIVEN("12bit readings")
    {
        int a2dOutput[2] = {2048, 1111};
        int expectedCurrentInAmps[2] = {5, 3};
		int actualCurrentInAmps[2];
		int no_of_elements = sizeof(a2dOutput)/sizeof(a2dOutput[0]);

        WHEN("convertA2DOutputIntoAmps() is called with given 12bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(a2dOutput, no_of_elements, actualCurrentInAmps);
            THEN("converted Amps readings will be rounded off to nearest integer and same is returned")
            {
                for (int i = 0; i < no_of_elements; i++)
                {
                    REQUIRE(actualCurrentInAmps[i] == expectedCurrentInAmps[i]);
                }
            }
        }
    }
}


