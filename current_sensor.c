#include "current_sensor.h"
#include <stdio.h>


void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps)
{
	int i;
	float adcValue;
	for (i = 0; i < no_of_readings; i++)
	{
		adcValue = a2d_output[i];
		outputInAmps[i] = ((adcValue/ADC_12BIT) *10) + 0.5;
	}
	return;
}