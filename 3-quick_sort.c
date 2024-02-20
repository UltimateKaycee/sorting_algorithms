#include "sort.h"

/**
 * swap_items - Function to swap two items in array.
 * @array: Array to modify.
 * @l: index of left item.
 * @r: index of right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int take;

	if (array != NULL)
	{
		take = array[l];
		array[l] = array[r];
		array[r] = take;
	}
}

/**
 * quick_sort_range_lomuto - Function to sort a sub array
 * @array: Array with sub-array.
 * @low: Start position of sub-array.
 * @high: End position of sub-array.
 * @size: Length of array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t sub, full;
	int turn;

	if ((low >= high) || (array == NULL))
		return;
	turn = array[high];
	sub = low;
	for (full = low; full < high; full++)
	{
		if (array[full] <= turn)
		{
			if (sub != full)
			{
				swap_items(array, sub, full);
				print_array(array, size);
			}
			sub++;
		}
	}
	if (sub != high)
	{
		swap_items(array, sub, high);
		print_array(array, size);
	}
	if (sub - low > 1)
		quick_sort_range_lomuto(array, low, sub - 1, size);
	if (high - sub > 1)
		quick_sort_range_lomuto(array, sub + 1, high, size);
}

/**
 * quick_sort - Function to sort array with quick sort algo
 * @array: The array.
 * @size: Length of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
