#pragma once

#define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))
void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps, int adcbit, const int max, const int min);
