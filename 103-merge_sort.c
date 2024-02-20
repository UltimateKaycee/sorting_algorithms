#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - Function to copy data from a buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 *
 * Return: None
 */
void copy(int *src, int *dst, int size)
{
	int run;

	for (run = 0; run < size; run++)
		dst[run] = src[run];
}

/**
 * merge - Function to merge 2 sets of data in ascending
 * @array: first set
 * @buff: second set
 * @minL: lower range of first set
 * @maxL: upper range of first set
 * @minR: lower range of second set
 * @maxR: upper range of second set
 *
 * Return: None
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int bim = minL, bam = minR, bum = minL;

	while (bim <= maxL || bam <= maxR)

		if (bim <= maxL && bam <= maxR)
			if (buff[bim] <= buff[bam])
				array[bum] = buff[bim], bum++, bim++;
			else
				array[bum] = buff[bam], bum++, bam++;

		else if (bim > maxL && bam <= maxR)
			array[bum] = buff[bam], bum++, bam++;
		else
			array[bum] = buff[bim], bum++, bim++;
}
/**
 * printcheck - Function to print array in range
 *
 * @array: array of data
 * @r1: start of range
 * @r2: end of range
 *
 * Return: None
 */
void printcheck(int *array, int r1, int r2)
{
	int bim;

	for (bim = r1; bim <= r2; bim++)
	{
		if (bim > r1)
			printf(", ");
		printf("%d", array[bim]);
	}
	printf("\n");
}
/**
 * split - Function to recursively split data into merge tree
 *
 * @array: array of data
 * @buff: auxiliary array of data
 * @min: min range of data
 * @max: max range of data
 * @size: size of total data
 *
 * Return: None
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int con, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	con = (max + min + 1) / 2;
	tmax = max;
	max = con - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = con;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}
/**
 * merge_sort - Function to sort array of int in ascendingi
 * with Merge sort algorithm
 *
 * @array: array of data
 * @size: size of data
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *buffed;

	if (size < 2)
		return;

	buffed = malloc(sizeof(int) * size);
	if (buffed == NULL)
		return;

	copy(array, buffed, size);

	split(array, buffed, 0, size - 1, size);

	free(buffed);
}
