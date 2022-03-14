#include "detect_ranges.h"
#include <stdio.h>
#include <cstddef>
#include <stdlib.h>
char output_string[20] = {0};

void sortInAscendingOrder (int *sorted_in, int size)
{
	int outer_loop, inner_loop, temp;
	for (outer_loop = 0; outer_loop < size -1; outer_loop++)
	{
		for (inner_loop = outer_loop+1; inner_loop < size; inner_loop++)//3,3,4,5
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

char* findReadingsFromRange (int *in_arr, int size)
{
	sortInAscendingOrder(in_arr, size);
	
	sprintf (output_string, "%d-%d,%d", in_arr[0],in_arr[size-1], size);
	return output_string;
}