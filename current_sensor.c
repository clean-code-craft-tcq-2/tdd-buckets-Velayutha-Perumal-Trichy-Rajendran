#include "current_sensor.h"
#include <stdio.h>


void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps)
{
	int i;
	for (i = 0; i < no_of_readings; i++)
	{
		outputInAmps[i] = (a2d_output[i]/ADC_12BIT) *10;
	}
	return;
}