#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - Function for radix sort
 *
 * @array: array of data
 * @buff: malloc buffer
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: None
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int start, begin, big = 10, count;
	int sideone[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int sidetwo[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (start = 0; start < size; start++)
	{
		count = array[start];
		for (begin = 0; begin < lsd; begin++)
			if (begin > 0)
				count = count / 10;
		count = count % 10;
		buff[count][sideone[count]] = array[start];
		sideone[count] += 1;
	}

	for (start = 0, begin = 0; start < big; start++)
	{
		while (sideone[start] > 0)
		{
			array[begin] = buff[start][sidetwo[start]];
			sidetwo[start] += 1, sideone[start] -= 1;
			begin++;
		}
	}

	print_array(array, size);
}
/**
 * csort - Function for auxiliary radix sort
 *
 * @array: array of data
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: None
 */
void csort(int *array, int size, int lsd)
{
	int sideone[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int start, begin, count, big = 10, **buff;

	for (start = 0; start < size; start++)
	{
		count = array[start];
		for (begin = 0; begin < lsd; begin++)
			if (begin > 0)
				count = count / 10;
		count = count % 10;
		sideone[count] += 1;
	}

	if (sideone[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (start = 0; start < big; start++)
		if (sideone[start] != 0)
			buff[start] = malloc(sizeof(int) * sideone[start]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (start = 0; start < big; start++)
		if (sideone[start] > 0)
			free(buff[start]);
	free(buff);
}
/**
 * radix_sort - Function to sort array of int in ascending with
 * the Radix sort algorithm
 *
 * @array: array of data
 * @size: size of data
 *
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
