#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - Function to sort array of int in ascending
 * @array: Array
 * @size: Size of array
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t run, go, first;
	int ven;

	for (go = 0; go < size - 1; go++)
	{
		first = go;
		for (run = go + 1; run < size; run++)
		{
			if (array[run] < array[first])
				first = run;
		}

		if (first != go)
		{
			ven = array[go];
			array[go] = array[first];
			array[first] = ven;
			print_array(array, size);
		}
	}
}
