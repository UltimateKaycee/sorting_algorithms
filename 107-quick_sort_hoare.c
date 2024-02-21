#include "sort.h"
/**
*swap - Function to positions two elements in an array
*@array: The array
*@item1: array element one
*@item2: array element two
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int make;

	make = array[item1];
	array[item1] = array[item2];
	array[item2] = make;
}
/**
 *hoare_partition - Function to partition sorting scheme
 *@array: The array
 *@first: first element of array
 *@last: last element of array
 *@size: size of the array
 *Return: position of sorted last element
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int turn = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < turn);
		do {
			finder--;
		} while (array[finder] > turn);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}
/**
 *qs - Function for qucksort algorithm
 *@array: the array
 *@first: first element of array
 *@last: last element of array
 *@size: Size of array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t state = 0;

	if (first < last)
	{
		state = hoare_partition(array, first, last, size);
		qs(array, first, state - 1, size);
		qs(array, state, last, size);
	}
}
/**
 *quick_sort_hoare - Function to prepare terrain for quicksort algorithm
 *@array: The array
 *@size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
