#include "current_sensor.h"
#include <stdio.h>

void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps)
{
	int i;
	float adcValue;
	int max_range = 1<<12;
	
	for (i = 0; i < no_of_readings; i++)
	{
		if (a2d_output[i] > max_range)
		{
			outputInAmps[i] = -1;
		}
		else{
			adcValue = a2d_output[i];
			outputInAmps[i] = ((adcValue/ADC_12BIT) *10) + 0.5;
		}
	}
	return;
}