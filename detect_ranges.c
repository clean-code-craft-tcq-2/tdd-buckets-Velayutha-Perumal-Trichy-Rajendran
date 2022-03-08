#include "detect_ranges.h"
#include <stdio.h>
#include <cstddef>
char output_string[10] = {0};

char* findReadingsFromRange (int *input)
{
	sprintf (output_string, "%d-%d,%d", input[0],input[1], 2);
	return output_string;
}