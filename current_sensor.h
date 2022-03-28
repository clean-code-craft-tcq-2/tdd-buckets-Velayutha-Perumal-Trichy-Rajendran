#pragma once

enum adc_output {ADC_12BIT=4096, ADC_10bit = 1024};
void convertA2DOutputIntoAmps (int *a2d_output, int no_of_readings, int *outputInAmps);
