#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define OUTPUT_SIZE 32
#include "test/catch.hpp"
#include "detect_ranges.h"
#include "current_sensor.h"
#include <string.h>
#include <stdio.h>

/* TEST_CASE("With provided input range, check if min-max range & number of readings matches the expected value.") {
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
} */

TEST_CASE("detect multiple ranges and check if the number of readings of each range matches the expected value.") {
  int input_range[]= {3, 5, 4, 3, 8, 10, 9, 7};
  const char *expected_range = "3-5,4\n7-10,4";
  char readingRange[OUTPUT_SIZE];
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result = getRangeAndReadings(input_range, no_of_elements, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

/* SCENARIO("find the current in amps from 12bit sensor output")
{
    GIVEN("12bit readings")
    {
        int a2dOutput[2] = {2048, 3023};
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
 */
/* SCENARIO("validate current in amps rounded off to nearest integer")
{
    GIVEN("12bit readings")
    {
        int a2dOutput[2] = {2048, 1111};
        int expectedCurrentInAmps[2] = {5, 3};
		int actualCurrentInAmps[2];
		int no_of_elements = sizeof(a2dOutput)/sizeof(a2dOutput[0]);
		int adc_bit = 12;

        WHEN("convertA2DOutputIntoAmps() is called with given 12bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(a2dOutput, no_of_elements, actualCurrentInAmps, adc_bit);
            THEN("converted Amps readings will be rounded off to nearest integer and same is returned")
            {
                for (int i = 0; i < no_of_elements; i++)
                {
                    REQUIRE(actualCurrentInAmps[i] == expectedCurrentInAmps[i]);
                }
            }
        }
    }
} */

SCENARIO("Report error Readings")
{
    GIVEN("out of range 12bit readings")
    {
        int input_reading[3] = {4098, 4090, 3000};
        int expectedCurrentInAmps[3] = {-1, 10, 7};
		int actualCurrentInAmps[3];
		int no_of_readings = sizeof(input_reading)/sizeof(input_reading[0]);
		int adc_bit = 12; 
		const int max_current = 10, min_current = 0;

        WHEN("convertA2DOutputIntoAmps() is called with given 12bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(input_reading, no_of_readings, actualCurrentInAmps, adc_bit, max_current, min_current);
            THEN("out of range input to convertA2DOutputIntoAmps returns -1")
            {
                for (int i = 0; i < no_of_readings; i++)
                {
                    REQUIRE(actualCurrentInAmps[i] == expectedCurrentInAmps[i]);
                }
            }
        }
    }
}

/* SCENARIO("Check if converted positive 10bit current in amps rounded off to nearest integer")
{
    GIVEN(" '+'ve 10bit readings")
    {
        int a2dOutput[3] = {123, 567, 1222};
        int expectedCurrentInAmps[3] = {2, 8, -1};
		int actualCurrentInAmps[3];
		int no_of_elements = sizeof(a2dOutput)/sizeof(a2dOutput[0]);
		int adc_bit = 10; 
		const int max_current = 15;

        WHEN("convertA2DOutputIntoAmps() is called with given 10bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(a2dOutput, no_of_elements, actualCurrentInAmps, adc_bit, max_current);
            THEN("converted Amps readings will be rounded off to nearest integer and same is returned")
            {
                for (int i = 0; i < no_of_elements; i++)
                {
                    REQUIRE(actualCurrentInAmps[i] == expectedCurrentInAmps[i]);
                }
            }
        }
    }
} */

SCENARIO("Check if converted 10bit ADC output current in amps rounded off to nearest integer with +ve and -ve")
{
    GIVEN(" '+'ve 10bit readings")
    {
        int a2dOutput[4] = {123, 567, 1222, 456};
        int expectedCurrentInAmps[4] = {-11, 2, -1, -2};
		int actualCurrentInAmps[4];
		int no_of_elements = sizeof(a2dOutput)/sizeof(a2dOutput[0]);
		int adc_bit = 10; 
		const int max_current = 15, min_current = -15;

        WHEN("convertA2DOutputIntoAmps() is called with given 10bit integer array and number of elements")
        {
            convertA2DOutputIntoAmps(a2dOutput, no_of_elements, actualCurrentInAmps, adc_bit, max_current, min_current);
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