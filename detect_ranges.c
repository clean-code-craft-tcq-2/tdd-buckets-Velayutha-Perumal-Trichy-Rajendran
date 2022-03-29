#include "detect_ranges.h"
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <stdlib.h>
char output_string[20] = {0};

int ascendingOrder (const void * value_1, const void * value_2) {
   return ( *(int*)value_1 - *(int*)value_2 );
}

void sortInOrder (int *sorted_in, int size)
{
	qsort(sorted_in, size, sizeof(int), ascendingOrder);
}

char* generateReadingsInEachRange (int *in_arr, int size, int first_element, char *result)
{
	int i;
	
	for (i = 0; i < (size - 1); i++)
	{
		if ((in_arr[i+1] - in_arr[i]) > 1)
		{
			sprintf (output_string, "%d-%d,%d\n", in_arr[first_element],in_arr[i], i+1-first_element);
			first_element = i+1;
			strcat(result, output_string);
			memset(output_string, '\0', sizeof(output_string));
		}
	}
	sprintf (output_string, "%d-%d,%d", in_arr[first_element],in_arr[i], i+1-first_element);
	strcat(result, output_string);
	return result;
}

char* getRangeAndReadings (int *in_arr, int size, char *result)
{
	for (int index = 0; index < size; index++)
	{
		in_arr[index] = abs(in_arr[index]);
	}
	sortInOrder(in_arr, size);

	return generateReadingsInEachRange(in_arr, size, FIRST_ELEMENT, result);
}