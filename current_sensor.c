#include "current_sensor.h"
#include <stdio.h>

void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps, int adc_bit, const int max_range, const int min_range)
{
	int reading_index;
	float adcValue;
	int max_limit = (1 << adc_bit) - 1;
	int max_current = max_range - min_range;
	
	for (reading_index = 0; reading_index < no_of_readings; reading_index++)
	{
		if (a2d_output[reading_index] > max_limit)
		{
			outputInAmps[reading_index] = -1;
		}
		else{
			adcValue = a2d_output[reading_index];
			outputInAmps[reading_index] = ((adcValue/max_limit) * max_current) + 0.5;
		}
	}
	return;
}