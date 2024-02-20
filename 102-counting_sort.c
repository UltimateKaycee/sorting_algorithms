#include "sort.h"
/**
 * counting_sort - Function to sort array of int in ascending
 * with Counting sort algorithm
 * @array: ptr to array
 * @size: size of array
 **/
void counting_sort(int *array, size_t size)
{
	int ent, bam, *counter, *come;
	size_t bim;

	if (!array || size < 2)
		return;
	ent = array[0];
	for (bim = 0; bim < size; bim++)
	{
		if (array[bim] > ent)
			ent = array[bim];
	}
	counter = calloc((ent + 1), sizeof(int));
	for (bim = 0; bim < size; bim++)
	{
		counter[array[bim]]++;
	}
	for (bam = 1; bam < ent; bam++)
	{
		counter[bam + 1] += counter[bam];
	}
	print_array(counter, ent + 1);
	come = malloc(sizeof(int) * size);
	for (bim = 0; bim < size; bim++)
	{
		counter[array[bim]]--;
		come[counter[array[bim]]] = array[bim];
	}
	for (bim = 0; bim < size; bim++)
	{
		array[bim] = come[bim];
	}
	free(come);
	free(counter);
}
