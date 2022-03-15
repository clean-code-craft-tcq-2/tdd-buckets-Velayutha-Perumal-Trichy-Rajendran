#include "detect_ranges.h"
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <stdlib.h>
char output_string[20] = {0};

void sortInAscendingOrder (int *sorted_in, int size)
{
	int outer_loop, inner_loop, temp;
	for (outer_loop = 0; outer_loop < size -1; outer_loop++)
	{
		for (inner_loop = outer_loop+1; inner_loop < size; inner_loop++)
		{
			if (sorted_in[outer_loop] > sorted_in[inner_loop])
			{
				temp    		 		= sorted_in[outer_loop];
				sorted_in[outer_loop]   = sorted_in[inner_loop];
				sorted_in[inner_loop] 	= temp;
			}
		}	
	}
}

char* generateReadingsInEachRange (int *in_arr, int size, int first_element, char *result)
{
	int i;
	
	for (i = 0; i < (size - 1); i++)
	{
		if ((in_arr[i+1] - in_arr[i]) > 1)
		{
			sprintf (output_string, "%d-%d,%d;", in_arr[first_element],in_arr[i], i+1-first_element);
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
	sortInAscendingOrder(in_arr, size);

	return generateReadingsInEachRange(in_arr, size, FIRST_ELEMENT, result);
}