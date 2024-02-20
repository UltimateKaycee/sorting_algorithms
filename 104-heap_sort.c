#include "sort.h"
/**
 * check_tree - Function to check swiftdown
 * @array: ptr to array
 * @size: size of pointer
 * @size_init: original size of array
 * @i: index root of tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int moon, side_one, side_two;
	size_t one, two;

	one = i * 2 + 1;
	two = one + 1;
	side_one = array[one];
	side_two = array[two];
	if (((one < size) && (two < size) &&
		(side_one >= side_two && side_one > array[i]))
		|| ((one == size - 1) && side_one > array[i]))
	{
		moon = array[i];
		array[i] = side_one;
		array[one] = moon;
		print_array(array, size_init);
	}
	else if ((one < size) && (one < size) &&
		(side_two > side_one && side_two > array[i]))
	{
		moon = array[i];
		array[i] = side_two;
		array[two] = moon;
		print_array(array, size_init);
	}
	if (one < size - 1)
		check_tree(array, size_init, size, one);
	if (two < size - 1)
		check_tree(array, size_init, size, two);
}
/**
 * heap_sort - Function to sort array of int
 * in ascending with Heap sort algorithm
 * @array: ptr to array
 * @size: size of pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t run, size_init = size;
	int move;

	if (!array)
		return;
	for (run = 0; run < size / 2 ; run++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - run);
	}
	for (run = 0; run < size_init - 1; run++)
	{
		move = array[0];
		array[0] = array[size - 1 - run];
		array[size - 1 - run] = move;
		print_array(array, size_init);
		check_tree(array, size_init, size - run - 1, 0);
	}

}
