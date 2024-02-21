#include "sort.h"
#include <stdio.h>
/**
 * swap - Funtion to change 2 values in ascending or descending
 * @arr: The array
 * @item1: item 1
 * @item2: item 2
 * @order: 1: ascending, 0 descending
 */
void swap(int arr[], int item1, int item2, int order)
{
	int ride;

	if (order == (arr[item1] > arr[item2]))
	{
		ride = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = ride;
	}
}
/**
 * merge - Function to recursively sort bitonic sequences in ascen and desce
 * @arr: The array
 * @low: first ele
 * @nelemnt: ele num
 * @order: 1: ascending, 0 descending
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int stay, run;

	if (nelemnt > 1)
	{
		stay = nelemnt / 2;
		for (run = low; run < low + stay; run++)
			swap(arr, run, run + stay, order);
		merge(arr, low, stay, order);
		merge(arr, low + stay, stay, order);
	}
}
/**
 * bitonicsort - Function for bitonic sort algorithm
 * @arr: The array
 * @low: first elem
 * @nelemnt: num of elem
 * @order: 1: ascending, 0 descending
 * @size: Length of array
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int stay;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		stay = nelemnt / 2;
		bitonicsort(arr, low, stay, 1, size);
		bitonicsort(arr, low + stay, stay, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - Funtion for the terrain to bitonic sort algorithm
 * @array: The array
 * @size: length of array
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
