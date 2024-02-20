#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Function to sort array of int in asc order
 *
 * @array: Array of ints
 * @size: Size of array
 *
 * Returns void
 */
void bubble_sort(int *array, size_t size)
{
	size_t run;
	int make, the_sorted;

	if (!array || size == 0)
		return;

	do {
		the_sorted = 1;
		for (run = 0; run < size - 1; run++)
		{
			if (array[run] > array[run + 1])
			{
				the_sorted = 0;
				make = array[run];
				array[run] = array[run + 1];
				array[run + 1] = make;
				print_array(array, size);
			}
		}

	} while (the_sorted == 0);
}
