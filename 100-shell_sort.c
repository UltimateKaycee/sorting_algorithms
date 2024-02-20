#include "sort.h"
#include <stdio.h>

/**
 * _swap - Function to swap 2 values.
 * @array: The array.
 * @i: First index
 * @j: Second index
 * Return: Nothing
 */
void _swap(int *array, int i, int j)
{
	int make;

	if (array[i] != array[j])
	{
		make = array[i];
		array[i] = array[j];
		array[j] = make;
	}
}

/**
 * shell_sort - Function to sort list and print the changes
 * @array: The array.
 * @size: Size of array
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	size_t game = 0, i, j;

	if (size < 2)
		return;

	while (game <= size / 3)
		game = game * 3 + 1;

	while (game >= 1)
	{
		for (i = game; i < size; i++)
			for (j = i; j >= game && array[j] < array[j - game]; j -= game)
				_swap(array, j, j - game);
		game /= 3;
		print_array(array, size);
	}
}
